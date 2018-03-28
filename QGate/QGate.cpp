#include "QBit.hpp"
#include "GateFunk.hpp"
#include "Gates.hpp"
using namespace std;

int main(int, char**){
if (SDL_Init(SDL_INIT_VIDEO) != 0){
            cout << "SDL_Init Error: " << SDL_GetError() << endl;
            return 1;
        }
            SDL_Window *win = SDL_CreateWindow("QGate", 10, 10, 1200, 800, SDL_WINDOW_SHOWN);
                if (win == 0) {
                cout << "window failed";
                return 1;
                }
vector<Gates>pal;
paint_back(win);
for (int i = 1; i < 7; ++i)
{
	pal.push_back(Gates(i));
}
vector<vector<Gates>>map,palette;
for (int i=0; i < 11; i++){
	vector<Gates>zeile;
	for (int j=0; j<8; j++){
		Gates o(0);
		o.pos_rect(j,i);
		zeile.push_back(o);
	}
	map.push_back(zeile);
}
palette.push_back(pal);
paint_back(win);
paint_gmap(&palette,win);
paint_gmap(&map,win);
SDL_UpdateWindowSurface(win);
bool laeuft = true;
vector<QBit> eingang;
for (int i=0;i<9;i++){
	eingang.push_back(QBit((1.,0),(0.,0.)));
}
while (laeuft){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_MOUSEBUTTONDOWN){
			klicked(&map,&palette,&eingang,win,&laeuft);
		}
	}
}
return 0;}

