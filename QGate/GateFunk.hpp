#ifndef GATEFUNK_H
#define GATEFUNK_H
#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include "QBit.hpp"
#include "Gates.hpp"

using namespace std;

vector<complex<double>> tensv(vector<QBit> Bits);
void tensvh(vector<vector<complex<double>>>* veks);
vector<vector<complex<double>>> tensm(vector<Gates>gate);
void tensmh(vector<vector<vector<complex<double>>>>* mats);
void paint_gmap(vector<vector<Gates>>*map, SDL_Window *win);
void paint_back(SDL_Window *win, SDL_Surface* aufgabe);
void klicked(vector<vector<Gates>>*map,vector<vector<Gates>>*palette,vector<QBit>*eingang,vector<QBit>*loesung,SDL_Window *win, SDL_Surface* aufgabe, bool *laeuft, bool *geschafft);
vector<complex<double>> gates_run(vector<vector<Gates>>*map,vector<QBit>*Bits);
double get_p(vector<complex<double>>a,vector<complex<double>>b);
bool abgleich(SDL_Window* win,vector<complex<double>> soll, vector<complex<double>>vist);
#endif // GateFunk_H
