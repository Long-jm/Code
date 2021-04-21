#include <iostream>
#include <random>


class BinarySearchTree {
protected:
  // Class to represent a node of a binary tree
  class BTNode
  {
  public:
    int data;
    BTNode *right;
    BTNode *left;
    BTNode(int d, BTNode *l=nullptr, BTNode *r=nullptr):data(d),right(r),left(l){}
  };
  
  BTNode *root;
public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  ~BinarySearchTree()
  {
    while(root)
      remove(root->data);
  }

  void insert(int data)
  {
    BTNode *node = new BTNode(data);

    if (root == nullptr)
	   root = node;
    else
    {   
	   BTNode * tmp = root;
	   while (tmp != nullptr)
	   {	    
	     if (data < tmp->data)
	     {
		// data must be on left side
		  if (tmp->left == nullptr)
		  {
		    tmp->left = node; // 
		    return;
		  }
		  else
		  tmp = tmp->left;
	      }
	    else
	      {
		// data must be on right side
		  if (tmp->right == nullptr)
		  {
		    tmp->right = node;
		    return;		    
		  }
		  else
		    tmp = tmp->right;
	      }
	  }
    }

  }

  bool search(int data) 
  {
    BTNode * tmp = root;
    while (tmp != nullptr)
      {
	   if (data == tmp->data)
	     return true;
	   if (data < tmp->data)
	     tmp = tmp->left;
	   else
	     tmp = tmp->right;
      }
    return false;
  }

private:
   bool Case1(BTNode *node, BTNode *parent)
   {
      if ((!node->left) && (!node->right)) {
         if (!parent)
            root = NULL;
         else if (parent->left == node)
            parent->left = NULL;
         else parent->right = NULL;
         return true;
      }
      return false; // not Case 1, try Case 2    
   }

   bool Case2(BTNode *node, BTNode *parent)
   {
      if (node->left && !node->right)
      {
         if (!parent)
            root = node->left;
         else if (parent->left == node)
            parent->left = node->left;
         else parent->right = node->left;
         return true;
      }
      else if (!node->left && node->right)
      {
         if (!parent)
            root = node->right;
         else if (parent->left == node)
            parent->left = node->right;
         else parent->right = node->right;
         return true;
      }
   return false; // not Case 1 or 2, must use Case 3
   }

  bool Case3(BTNode *node, BTNode *parent)
  {
    BTNode* succ = node->right;
    BTNode* prev = node;
    while (succ->left) 
    {
      prev = succ;
      succ = succ->left;
    }
    if (!Case1(succ, prev)) 
      Case2(succ, prev);
    succ->left = node->left;
    succ->right = node->right;
    if (!parent)
      root = succ;
    else if (parent->left == node)
      parent->left = succ;
    else parent->right = succ;
    // Case 3 must succeed!
    return true;
  }
    
public:
  void remove(int data) 
  {
    BTNode *tmp = root;
    BTNode *parent = nullptr;
    
    // Find the node in the tree
    while (tmp != nullptr)
    {
	   if (tmp->data == data)
	   {
	     if (!Case1(tmp,parent))
	       if (!Case2(tmp,parent))
		      Case3(tmp,parent);
	    // delete node once removed	    
	    delete tmp;
	    break;
	  }			
	  else if (data < tmp->data)
	  {
	    parent = tmp;
	    tmp = tmp->left;
	  }
	  else
	  {
	    parent = tmp;
	    tmp = tmp->right;
	  }
    }
  }  

public:
  bool hasRoot() {
    return root != nullptr;
  }

  int getRoot() {
    if  (hasRoot()) return root->data;
    else return -1;
  }

  bool rootHasRightChild() {
    return root->right != nullptr;
  }

  int getRootRightChild() {
    return root->right->data;
  }

  bool rootHasLeftChild() {
    return root->left != nullptr;
  }

  int getRootLeftChild() {
    return root->left->data;
  }
public:
  friend std::ostream& operator<< (std::ostream& out, BTNode *bt);
  friend std::ostream& operator<< (std::ostream& out, BinarySearchTree &bst);
};

std::ostream& operator<< (std::ostream& out, BinarySearchTree::BTNode *bt)
{
  if (bt == nullptr)
    return out;
  
  if (bt->left != nullptr)
    out << bt->left;

  out << bt->data << " ";

  if (bt->right != nullptr)
    out << bt->right;

  return out;
}

std::ostream& operator<< (std::ostream& out, BinarySearchTree &bst)
{
  out << bst.root;
  return out;
}


int main()
{  
  //std::random_device generator;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0,1000);

  BinarySearchTree *b2 = new BinarySearchTree();
  /*for(int i=0; i<10; i++)
    {
      b2->insert(dist(generator));      
    }
  for (int i=0; i<5; i++)
    b2->insert(i*100);
  for(int i=0; i<10; i++)
    {
      b2->insert(dist(generator));      
    }
*/
b2->insert(14);
b2->insert(13);
b2->insert(12);
b2->insert(11);

  std::cout << *b2 << std::endl;

  for (int i=0; i<5; i++)
    {
      std::cout << "remove " << i*100 << std::endl;
      b2->remove(i*100);
    }
  std::cout << *b2;

  delete b2;
  
  return 0;
}
