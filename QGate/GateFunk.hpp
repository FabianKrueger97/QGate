#ifndef GATEFUNK_H
#define GATEFUNK_H
#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <complex.h>
#include "QBit.hpp"

using namespace std;

vector<QBit*> hadamard(vector<QBit*> Bits);
vector<QBit*> pauli_x(vector<QBit*> Bits);
vector<QBit*> pauli_y(vector<QBit*> Bits);
vector<QBit*> pauli_z(vector<QBit*> Bits);

#endif // GateFunk_H
