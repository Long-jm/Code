#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool isBalanced(std::string str, int &error)
{
    stack<char> s;
    int i = 0;
    while (i<str.size()) {
        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (!s.empty()) {
                if (s.top() == '(' && str[i] != ')') {
                    error = i; 
                    return false;
                } else if (s.top() == '[' && str[i] != ']') {
                    error = i; 
                    return false;
                } else if (s.top() == '{' && str[i] != '}') {
                    error = i; 
                    return false;
                }
                s.pop();
            } else {error = i; return false;}
        }
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        }
        i++;
    }
    if (s.empty()) {
        return true;
    } else {error = str.size(); return false;}
    
}

void test_string(std::string s)
{
  int err;
  if ( isBalanced(s,err) )
    {
      std::cout << s << " is balanced." << std::endl;
    }
  else
    {
      std::cout << s << " is not balanced." << std::endl;
      std::string pointer = "^";
      pointer.insert(0, err,' ');
      //std::cout << s << std::endl;
      std::cout << pointer << std::endl;
    }
}


int main(int argc, char **argv)
{
  if (argc < 2) {
    test_string("({[]");
    test_string("(");
    test_string(")");
    test_string("[()]");
    test_string("{[()]}()");
    test_string("())");
    test_string("()(()]");
    test_string("(()()(){}){}[][]");
    test_string("([)]");
  } else
    {
      std::string s = argv[1];
      test_string(s);
    }
  return 0;
}