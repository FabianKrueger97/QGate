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

vector<complex<double>> tensv(vector<QBit> Bits);
void tensvh(vector<vector<complex<double>>>* veks);
vector<vector<complex<double>>> tensm(vector<Gates>gate);
void tensmh(vector<vector<vector<complex<double>>>>* mats);
void paint_gmap(vector<vector<Gates>>*map, SDL_Window *win);
void paint_back(SDL_Window *win);
void klicked(vector<vector<Gates>>*map,vector<vector<Gates>>*palette,vector<QBit>*eingang, SDL_Window *win, bool *laeuft);
#endif // GateFunk_H
