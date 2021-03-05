
#include <cstddef>
#include <iostream>
using namespace std;


class Irregular2DArray {
public:
    int numDims;
    int *dims;
    int **arrays;
    Irregular2DArray(int a_numDims=4, int *a_dims=nullptr) {  
        numDims = a_numDims;
        dims = new int [numDims]; 
        arrays = new int * [numDims];
        for(int i=0; i<numDims; i++) {
            dims[i] = a_dims[i];
            // 2D array - each array[i]’s length is determined by value in dims[i]
            arrays[i] = new int [dims[i]];
            for(int j=0; j < dims[i]; j++) {
                arrays[i][j] = 0;
            }
        }
    }
    Irregular2DArray (const Irregular2DArray &original) {
        numDims = original.numDims;
        dims = new int [numDims]; 
        arrays = new int * [numDims];
        for(int i=0; i<numDims; i++) {
            dims[i] = original.dims[i];
            arrays[i] = new int [dims[i]];
            for(int j=0; j < dims[i]; j++) {
                arrays[i][j] = 0;
            }
        }
    }
    Irregular2DArray& operator =(const Irregular2DArray &other) {
        numDims = other.numDims;
        dims = new int [numDims]; 
        arrays = new int * [numDims];
        for(int i=0; i<numDims; i++) {
            dims[i] = other.dims[i];
            arrays[i] = new int [dims[i]];
            for(int j=0; j < dims[i]; j++) {
                arrays[i][j] = 0;
            }
        }
        return *this;
    }
    ~Irregular2DArray() {
        delete [] dims; 
        delete [] *arrays;
    }
    void print() {
        for(int i=0; i<numDims; i++) {
            for(int j=0; j < dims[i]; j++) {
                cout << arrays[i][j] << ", ";
            }
            cout << '\n';
        }
        return;
    }
};


Irregular2DArray global(0,nullptr);

void other() {
    int array[] = {3,1,2};
    int *aPtr;
    aPtr = array;
    Irregular2DArray temp(3,aPtr);
    temp.print();
    Irregular2DArray copy = temp;
    copy.print();
    global = copy;
    global.print();
    return;
}

int main() {

    other();
    global.print();

    return 0;
}


// class triangle {
// private:
//     int base;
//     int height;
// public:
//     triangle(int b, int h) {base=b; height=h;}
//     triangle scale(int factor) {
//         int sBase = base*factor;
//         int sHeight = height*factor;
//         triangle Scaled(sBase, sHeight);
//         return Scaled;
//     }
//     void print(){
//         cout << "Triangle base is " << base << "and height is " << height << "\n";
//         return;
//     }
// };



// class square {
// private:
//     int base;
//     int height;
// public:
//     square(int b, int h) {base=b; height=h;}
//     int area() {
//         int ar = base * height;
//         return ar;
//     }
// };


// int main() {

//     triangle tri1(2,3);
//     triangle val(0,0);
//     val = tri1.scale(2);
//     val.print();
//     return 0;
// }
