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
#include "Gates.hpp"

using namespace std;
/*
vector<QBit*> hadamard(vector<QBit*> Bits);
vector<QBit*> pauli_x(vector<QBit*> Bits);
vector<QBit*> pauli_y(vector<QBit*> Bits);
vector<QBit*> pauli_z(vector<QBit*> Bits);
vector<QBit*> id(vector<QBit*> Bits);*/
vector<complex<double>> tensv(vector<QBit> Bits);
void tensvh(vector<vector<complex<double>>>* veks);
vector<vector<complex<double>>> tensm(vector<Gates>gate);
void tensmh(vector<vector<vector<complex<double>>>>* mats);
void paint_map(vector<vector<Gates>> map, SDL_Window *win);
#endif // GateFunk_H
