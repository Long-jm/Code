#include <iostream>
using namespace std;

class A {
public:
   virtual int get() = 0;
   int geta() { return 0; }
};

class B : public A {
public:
   B(int ab=1):A(),b(ab){}
   int b;
   virtual int get() override { return b; }
   int getb() { return b; }
};

class C : public B {
public:
   C(int ac=2):B(1),c(ac){}
   int c;
   int get() override { return c; }
   int getc() { return c; }
};

ostream &operator<<(ostream& out, A &a) {
  out << a.get() << std::endl;
  return out;
}



int main() {


  return 0;
}