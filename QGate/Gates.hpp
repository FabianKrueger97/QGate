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
#include <complex.h>


using namespace std;

class Gates{
    private:
        SDL_Surface* surf;
        SDL_Rect rect;
    public:
        Gates(int type);
        int type;
        vector<vector<vector<complex<double>>>> mat;
        int breite;
        int num;
        void move(SDL_Window* win, vector<vector<Gates>>*palette, vector<vector<Gates>> *map, SDL_Surface* aufgabe);
        void paint_gate(SDL_Window *win);
        void pos_in(vector<vector<Gates>>*map);
        void pos_rect(int xn, int yn);
        };


#endif // GATES_H
