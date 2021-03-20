
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <algorithm>
 
template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
        // unless the result is subnormal
        || std::fabs(x-y) < std::numeric_limits<T>::min();
}

using namespace std;

class Complex {
private:
   double real;
   double imag;
public:
  Complex():real(0), imag(0) {}

  Complex(double re, double im) 
  {
    real = re; imag = im;
  }

  Complex operator+(const Complex &rhs) const
  {
    Complex c;
    c.real = real + rhs.real;
    c.imag = imag + rhs.imag;
    return c;
  }

  Complex operator-(const Complex &rhs) const
  {
    Complex c;
    c.real = real - rhs.real;
    c.imag = imag - rhs.imag;
    return c;
  }

  Complex operator*(const Complex &rhs) const
  {
    Complex c;
    c.real = real * rhs.real - imag * rhs.imag;
    c.imag = imag * rhs.imag + real * rhs.imag;
    return c;
  }
  
  Complex operator*(int rhs) const
  {
    Complex c;
    c.real *= rhs;
    c.imag *= rhs;
    return c;
  }

  Complex operator/(const Complex &rhs) const; // implement divide

  Complex operator-() const // negation
  {
    Complex c;
    c.real = -c.real;
    c.imag = -c.imag;
    return c;
  }

  Complex operator~() const // conjugation
  {
    Complex c;
    c.imag = -c.imag;
    return c;
  }

// DO NOT MODIFY BELOW THIS
  bool operator==(const Complex &other) const {
    return almost_equal(real,other.real,2) && almost_equal(imag,other.imag,2);
  }

  bool operator!=(const Complex &other) const {
    return !operator==(other);
  }

  friend ostream& operator<<(ostream&,const Complex &c);
};

ostream& operator<< (ostream& out, const Complex &c)
{
  if (c.imag < 0)
    out << "(" << c.real << " - " << -c.imag << "j)" ;
  else
    out << "(" << c.real << " + " << c.imag << "j)" ;
  return out;
}

int main()
{
  Complex z;
  
  Complex j(0,1);
  Complex x(5,0);

  std::cout << "j = " << j << std::endl;
  std::cout << "x = " << x << std::endl;

  Complex y(1,1);
  Complex c;

  c = y + j*10 ; // assign y to c
  std::cout << (j*10);

  std::cout << "c = " << c << std::endl;
  
  return 0;
}
