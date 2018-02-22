#ifndef QBIT_H
#define QBIT_H
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <complex.h>
using namespace std;
class QBit{
private:


public:
    string value;
    complex<double>a,b;
    QBit(complex<double>a0, complex<double>b0);
    void make_value();
    };

#endif // QBIT_H
