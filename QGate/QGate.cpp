#include "QBit.hpp"
#include "GateFunk.hpp"
#include "Gates.hpp"
using namespace std;

int main(int, char**){
srand (time(NULL));
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
SDL_Surface *aufgabe = IMG_Load("./Bilder/A1.png");
paint_back(win, aufgabe);
paint_gmap(&palette,win);
paint_gmap(&map,win);
SDL_UpdateWindowSurface(win);
bool laeuft = true, geschafft = false;
vector<QBit> eingang;
for (int i=0;i<8;i++){
	eingang.push_back(QBit(1.,0.));
}
while (laeuft  && !geschafft){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_MOUSEBUTTONDOWN){
			klicked(&map,&palette,&eingang,&eingang,win,aufgabe,&laeuft,&geschafft);
		}
	}
}
return 0;}

