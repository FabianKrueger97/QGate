#include "Gates.hpp"
#include "GateFunk.hpp"

Gates::Gates(int typ){
	type = typ;
	double p = sqrt(2.);
	complex<double> q = 1/p;
	switch(typ){
		case 1:
		{
			surf = IMG_Load("./Bilder/hadamard.png");
			breite = 1;
			num = 1;
			mat = {{{q,q},{q,-q}}};
		}
		break;
		case 2:
		{
			surf = IMG_Load("./Bilder/paulix.png");
			breite = 1; 
			num = 1;
			mat = {{{0.,1.},{1.,0.}}};
		}
		break;
		case 3:
		{
			surf = IMG_Load("./Bilder/pauliy.png");
			breite = 1;
			num = 1; 
			mat = {{{0.,-1.i},{1.i,0.}}};
		}
		break;
		case 4:
		{
			surf = IMG_Load("./Bilder/pauliz.png");
			breite = 1; 
			num = 1;
			mat = {{{1.,0},{0.,-1.}}};
		}
		break;
		case 5:
		{
			surf = IMG_Load("./Bilder/cnot.png");
			breite = 2;
			num = 2;
			mat = {{{1.,0.,0.,0.},{0.,1.,0.,0.},{0.,0.,0.,1.},{0.,0.,1.,0.}}};
		}
		break;
		case 6:
		{
			surf = IMG_Load("./Bilder/swap.png");
			breite = 2;
			num = 4;
			mat = {{{1.,0.,0.,0.},{0.,0.,1.,0.},{0.,1.,0.,0.},{0.,0.,0.,1.}}};
		}
	}
	int a = (typ+1) % 2;
	rect.x = 1000 + (breite % 2) * a * 51;
	rect.y = 100 + (breite % 2)*((typ+1 - a)/2 -1 ) * 51 + (breite+1)%2 * (typ-3) * 51 ;
	rect.w = 50*breite;
	rect.h = 50*breite;
}

void Gates::paint_gate(SDL_Window* win){
	SDL_Surface *screen;
	screen = SDL_GetWindowSurface(win);
	SDL_BlitSurface(surf,NULL,screen,&rect);
	SDL_UpdateWindowSurface(win);
}
