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
#include "Gates.hpp"
using namespace std;
class QBit{
private:
public:
    string value;
    vector<complex<double>>vek;
    QBit(complex<double>a0, complex<double>b0);
    void make_value();
    void paint_value(SDL_Window* win, int x, int y);
    };

#endif // QBIT_H
