#ifndef GATES_H
#define GATES_H

#include <time.h>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <math.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <SDL_ttf.h>
#include "QBit.hpp"

using namespace std;

class Gates{
    private:
        SDL_Surface* surf;
        SDL_Rect rect;
        int type;
        int breite;
    public:
        Gates(int type);
        vector<QBit*> run(vector<QBit*>Bits);
        void paint_gate(SDL_Window *win);
        };

class SigZ{
private:
    SDL_Surface* surf;
    SDL_Rect rect;
public:
    SigZ();
    QBit run(QBit);
    };


#endif // GATES_H
