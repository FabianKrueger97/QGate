#include "Gates.hpp"
#include "GateFunk.hpp"

Gates::Gates(int typ){
	type = typ;
	switch(typ){
		case 1:
		{
			surf = IMG_Load("./Bilder/hadamard.png");
			breite = 1; 
		}
		break;
		case 2:
		{
			surf = IMG_Load("./Bilder/paulix.png");
			breite = 1; 
		}
		break;
		case 3:
		{
			surf = IMG_Load("./Bilder/pauliy.png");
			breite = 1; 
		}
		break;
		case 4:
		{
			surf = IMG_Load("./Bilder/pauliz.png");
			breite = 1; 
		}
		break;
	}
	int a = (typ+1) % 2;
	rect.x = 1000 + a*50;
	rect.y = 100 + ((typ+1 - a)/2 -1 ) * 50;
	rect.w = 50;
	rect.h = 50;
}

vector<QBit*> Gates::run(vector<QBit*>Bits){
	switch(type){
		case 1:
		{
			return hadamard(Bits);
		}		
		break;
		case 2:
		{
			return pauli_x(Bits);
		}
		break;
		case 3:
		{
			return pauli_y(Bits);
		}
		break;
		case 4:
		{
			return pauli_z(Bits);
		}		
		break;

	}
}

void Gates::paint_gate(SDL_Window* win){
	SDL_Surface *screen;
	screen = SDL_GetWindowSurface(win);
	SDL_BlitSurface(surf,NULL,screen,&rect);
	SDL_UpdateWindowSurface(win);
}
