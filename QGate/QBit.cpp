#include "QBit.hpp"
using namespace std;
QBit::QBit(complex<double>a0, complex<double>b0){
    vek.push_back(a0);
    vek.push_back(b0);
    ostringstream a_real_stream, b_real_stream, a_im_stream, b_im_stream;
    a_real_stream << vek[0].real();
    b_real_stream << vek[1].real();
    a_im_stream << vek[0].imag();
    b_im_stream << vek[1].imag();
    value = a_real_stream.str()+"+"+"i*"+a_im_stream.str() + " |0> " + b_real_stream.str()+"+"+"i*"+b_im_stream.str() + " |1>";
}

void QBit::make_value(){
    ostringstream a_real_stream, b_real_stream, a_im_stream, b_im_stream;
    a_real_stream << vek[0].real();
    b_real_stream << vek[1].real();
    a_im_stream << vek[0].imag();
    b_im_stream << vek[1].imag();
    if (abs(vek[0])==0){
        if (abs(vek[1])==vek[1].real())
            value = "|1>";
        else if (abs(vek[1])==vek[1].imag())
            value = "i * "+b_im_stream.str() + " |1>";
        else
            value = "(" + b_real_stream.str()+" + "+"i * "+b_im_stream.str() +")" + " |1>";}
    else if (abs(vek[1])==0){
        if (abs(vek[1])==vek[0].real())
            value = "|0>";
        else if (abs(vek[0])==vek[0].imag())
            value = "i * "+a_im_stream.str() + " |0>";
        else
            value = "(" + a_real_stream.str()+" + "+"i * "+a_im_stream.str() +")" + " |0>";}
    else
        value ="("+a_real_stream.str()+" + "+"i * "+a_im_stream.str()+ ")" + " |0> " + " + "  + "(" + b_real_stream.str()+" + "+"i * "+b_im_stream.str() +")" + " |1>";
}

void QBit::paint_value(SDL_Window* win, int x, int y){
    SDL_Surface* null = IMG_Load("./Bilder/null.png"),*eins = IMG_Load("./Bilder/eins.png");
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = 50;
    dst.h = 50;
    SDL_Surface *screen;
    screen = SDL_GetWindowSurface(win);
    if (abs(vek[0])==1)
        SDL_BlitSurface(null,NULL,screen,&dst);
    else
        SDL_BlitSurface(eins,NULL,screen,&dst);
}