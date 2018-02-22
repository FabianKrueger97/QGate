#ifndef GATES_H
#define GATES_H

#include <time.h>
//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
#include <math.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
//#include <SDL2_ttf/SDL_ttf.h>
#include "QBit.hpp"

using namespace std;

class Gates{
    private:
        //SDL_Surface* surf;
        //SDL_Rect rect;
        int type;
        int breite;
    public:
        Gates(int type);
        vector<QBit> run(vector<QBit>Bits);
        };

class SigZ{
private:
    //SDL_Surface* surf;
    //SDL_Rect rect;
public:
    SigZ();
    QBit run(QBit);
    };


#endif // GATES_H
