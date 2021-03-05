
//Jonathan M. Long: jmlong4

#include <iostream>
using namespace std;

class fraction {
private:
    int numerator;
    int denominator;
public:
    fraction() {numerator=1; denominator=1;}
    fraction(int num, int den) {numerator=num; denominator=den;}
    fraction add(fraction fa1, fraction fa2) {
        int aDen = fa1.denominator * fa2.denominator;
        int aNum = fa1.denominator * fa2.numerator + fa2.denominator * fa1.numerator;
        fraction sum(aNum,aDen);
        return sum;
    }
    fraction sub(fraction fs1, fraction fs2) {
        int sDen = fs1.denominator * fs2.denominator;
        int sNum = fs2.denominator * fs1.numerator - fs1.denominator * fs2.numerator;
        fraction diff(sNum,sDen);
        return diff;
    }
    double fraction_convert(fraction fc)
    {
        return ((double) fc.numerator) / fc.denominator;
    }
    void print() {
        cout << numerator << " / " << denominator;
    }
};

//Jonathan M. Long: jmlong4
int main() {
    fraction half(1,2);
    fraction third(1,3);

    fraction f(0,0);
    f = f.add(half,third);
    half.print();
    cout << " + ";
    third.print();
    cout << "\n = "; 
    f.print();
    cout << "\n";

    f = f.sub(half,third);
    half.print();
    cout << " - ";
    third.print();
    cout << "\n = "; 
    f.print();
    cout << "\n";

    return 0;
}
