#include <iostream>
#include <vector>

using namespace std;

class BTNode {
public:
   int item;
   BTNode *left;
   BTNode *right;
   BTNode(int i, BTNode *l=nullptr, BTNode *r=nullptr):item(i),left(l),right(r){}
};

BTNode *root = nullptr;
vector<int> BTList;

void insert(int i) {
   if (!root) {
      root = new BTNode(i); 
   }
   else {
      BTNode* temp = root;
      while (temp) {
         if (i < temp->item) {
            if (!temp->left) {
               temp->left = new BTNode(i);
               break;
            }
            else {temp = temp->left;}
         }
         else if (i > temp->item) {
            if (!temp->right) {
               temp->right = new BTNode(i);
               break;
            }
            else {temp = temp->right;}
         }
         else {break;}
      }
   }
}

BTNode * remove_leaf(int item, bool &removed) {          // only removes leaf nodes from BST
   BTNode* temp = root;
   BTNode* parent = NULL;
   removed = false;

   while (temp) {
      if (temp->item == item) {
         if ((!temp->left) && (!temp->right)) {
            removed = true;
            if (parent == NULL) { root = NULL; }
            else if (parent->left == temp) { parent->left = NULL; }
            else { parent->right = NULL; }
         }
         return temp;
      }
      else {
         parent = temp;
         if (item < temp->item) { temp = temp->left; }
         else { temp = temp->right; }
      }
   }
   return nullptr;
}

BTNode *find(int item)
{
   BTNode* temp;
   temp = root;
   while (temp) {
      if (item == temp->item) { return temp; }
      else if (item < temp->item) { temp = temp->left; }
      else { temp = temp->right; }
   }
  return nullptr; 
}

std::vector<int> inorder_traversal(BTNode *node) {
   if (node==0) return BTList;
   inorder_traversal(node->left);
   BTList.push_back(node->item);
   inorder_traversal(node->right);
   return BTList;
}

int main()
{
   /*root = new BTNode(10, new BTNode(0), new BTNode(100));
   std::vector<int> res = inorder_traversal(root);
   
   for(auto &i : res) {
      std::cout << i << ", ";  
   }
   std::cout << std::endl;
   return 0;*/

   /*insert (5);
   insert (10);
   insert (1);
   insert (10);
   
   if (root) 
   {
      std::cout << "root = " << root->item << std::endl;
      if (root->left)
         std::cout << "root->left = " << root->left->item << std::endl;
      if (root->right)
         std::cout << "root->right = " << root->right->item << std::endl;
   }*/

   /*root = new BTNode(50, new BTNode(25), new BTNode(100));
   bool r=false;

   BTNode *tmp50 = remove_leaf(50,r);
   if (tmp50 == nullptr || r == true) {
     std::cout << "Should not have removed node 50! It has a child node." << std::endl;  
   } else if (!r) {
     std::cout << "Correctly chose not to remove node 50." << std::endl;        
   }
   
   BTNode *tmp100 = remove_leaf(100,r);
   if (tmp100 == nullptr || r == false) {
     std::cout << "Should have removed node 100! It is a leaf node." << std::endl;  
   } else if (r) {
     std::cout << "Correctly chose to remove node 100." << std::endl;        
   }
   
   BTNode *tmp25 = remove_leaf(25,r);
   if (tmp25 == nullptr || r == false) {
     std::cout << "Should have removed node 25! It is a leaf node." << std::endl;  
   } else if (r) {
     std::cout << "Correctly chose to remove node 25." << std::endl;        
   }
   
   tmp50 = remove_leaf(50,r);
   if (tmp50 == nullptr || r == false) {
     std::cout << "Should have removed node 50! It is a leaf node." << std::endl;  
   } else if (r) {
     std::cout << "Correctly chose to remove node 50." << std::endl;        
   }
   if (root!=nullptr) {
     std::cout << "root should be nullptr now, but it isn't!" << std::endl;  
   } else {
      std::cout << "Correctly set root to nullptr." << std::endl;  
   }*/

   root = new BTNode(10, new BTNode(1), new BTNode(20));
   
   BTNode *t1 = find(10);
   if (t1)
      std::cout << "Found " << t1->item << std::endl;
   else
      std::cout << "Should have found 10." << std::endl;
   
      
   BTNode *t2 = find(1);
   if (t1)
      std::cout << "Found " << t2->item << std::endl;
   else
      std::cout << "Should have found 1." << std::endl;
   
   BTNode *t3 = find(20);
   if (t3)
      std::cout << "Found " << t3->item << std::endl;
   else
      std::cout << "Should have found 20." << std::endl;
   
   BTNode *t4 = find(100);
   if (t4)
      std::cout << "Should have found 20." << std::endl;   
   else
      std::cout << "Did not find 100." << std::endl;
   
   return 0;
}
