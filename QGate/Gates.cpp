#include "Gates.hpp"
#include "GateFunk.hpp"

Gates::Gates(int typ){
	type = typ;
	double p = sqrt(2.);
	complex<double> q = 1/p;
	switch(typ){
		case 0:
		{
			surf = IMG_Load("./Bilder/id.png");
			breite = 1;
			num = 1;
			mat = {{{1.,0.},{0.,1.}}};
		}
		break;
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
	rect.x = 1000 + (breite % 2) * a * 50;
	rect.y = 100 + (breite % 2)*((typ+1 - a)/2 -1 ) * 50 + (breite+1)%2 * (typ-3) * 50 ;
	rect.w = 50*breite;
	rect.h = 50*breite;
}

void Gates::paint_gate(SDL_Window* win){
	SDL_Surface *screen;
	screen = SDL_GetWindowSurface(win);
	SDL_BlitSurface(surf,NULL,screen,&rect);
}

void Gates::move(SDL_Window* win,vector<vector<Gates>>*palette,vector<vector<Gates>>*map){
	SDL_Event e;
	bool left = false;
	while(!left){
		while(SDL_PollEvent(&e)){
		if(e.type != SDL_MOUSEBUTTONUP){
			int xn,yn;
			SDL_GetMouseState( &xn, &yn);
			rect.x = xn-25*breite;
			rect.y = yn-25;
			paint_back(win);
			paint_gmap(palette,win);
			paint_gmap(map,win);
			paint_gate(win);
			SDL_UpdateWindowSurface(win);

	}
	else
		left = true;
}}}

void Gates::pos_in(vector<vector<Gates>>*map){
	int xn,yn,zeile,spalte;
	SDL_GetMouseState( &xn, &yn);
	xn -= 400;
	yn -= 65;
	zeile = (yn - yn%60)/60;
	spalte = (xn - xn%50)/50 - (breite+1)%2 * (1 - round((xn%50)/50));
	if (breite == 2 && spalte ==7)
		spalte--;
	if (breite == 2 && spalte == -1)
		spalte++;
	rect.y = zeile * 60 + 70;
	rect.x = spalte * 50 + 400;
	if (breite == 1){
		vector<int> ueber;
		int n = 0, i = 0; 
		while (ueber.size() < 8){
			if ((*map)[zeile][i].type>4){
				ueber.push_back(n);
				ueber.push_back(n);
			}
			else
				ueber.push_back(n);
			n++;
			i++;

		}
		int pos = ueber[spalte];
		if ((*map)[zeile][pos].type>4){
			Gates o(0);
			o.pos_rect(spalte+1,zeile);
			auto it = (*map)[zeile].begin();
			it = (*map)[zeile].insert(it+pos+1,o);
			
		}
		if (ueber[spalte]==ueber[spalte-1]){
			Gates o(0);
			o.pos_rect(spalte,zeile);
			(*map)[zeile][pos] = o;
			pos++;
		}
		(*map)[zeile][pos] = (*this);
	}
	if (breite == 2){
		vector<int> ueber;
		int n = 0, i=0; 
		while (ueber.size() < 8){
			if ((*map)[zeile][i].type>4){
				ueber.push_back(n);
				ueber.push_back(n);
			}
			else
				ueber.push_back(n);
			n++;
			i++;

		}
		int pos = ueber[spalte];
		if (ueber[spalte]!=ueber[spalte+1] && spalte!=0 && spalte!=ueber.size()-2){
			if (ueber[spalte+1]==ueber[spalte+2]){
				if (ueber[spalte]==ueber[spalte-1]){
					(*map)[zeile][pos] = Gates(0);
					(*map)[zeile][pos].pos_rect(spalte+1,zeile);
					pos++;
					auto it = (*map)[zeile].begin();
					it = (*map)[zeile].insert(it+pos+1,Gates(0));
					(*map)[zeile][pos+1].pos_rect(spalte+2,zeile);
				}
				else{
					(*map)[zeile][pos+1] = Gates(0);
					(*map)[zeile][pos+1].pos_rect(spalte+2,zeile);
				}
			}
			if (ueber[spalte]==ueber[spalte-1]){
				if (ueber[spalte+1]!=ueber[spalte+2]){
					auto it = (*map)[zeile].begin();
					it = (*map)[zeile].insert(it+pos,Gates(0));
					(*map)[zeile][pos].pos_rect(spalte,zeile);
					pos++;
					(*map)[zeile].erase((*map)[zeile].begin()+pos+1);
				}
			}
			if(ueber[spalte]!=ueber[spalte-1] && ueber[spalte+1]!=ueber[spalte+2]){
				(*map)[zeile].erase((*map)[zeile].begin()+(pos+1));
			}

		}
		if (ueber[spalte]!=ueber[spalte+1] && spalte==0){
			if (ueber[spalte+1]==ueber[spalte+2]){
				(*map)[zeile][pos+1] = Gates(0);
				(*map)[zeile][pos+1].pos_rect(spalte+2,zeile);
			}
			else
				(*map)[zeile].erase((*map)[zeile].begin()+(pos+1));
			
		}
		if (ueber[spalte]!=ueber[spalte+1] && spalte==ueber.size()-2){
			if (ueber[spalte]==ueber[spalte-1]){
				(*map)[zeile][pos] = Gates(0);
				(*map)[zeile][pos].pos_rect(spalte,zeile);
				pos++;
			}
			else
				(*map)[zeile].erase((*map)[zeile].begin()+(pos+1));	
		}

		(*map)[zeile][pos] = (*this);

	}
}

void Gates::pos_rect(int xn, int yn){
	rect.y = yn * 60 + 70;
	rect.x = xn * 50 + 400;
}