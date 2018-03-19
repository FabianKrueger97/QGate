#include "QBit.hpp"
#include "GateFunk.hpp"
#include "Gates.hpp"
using namespace std;

int main(int, char**){
if (SDL_Init(SDL_INIT_VIDEO) != 0){
            cout << "SDL_Init Error: " << SDL_GetError() << endl;
            return 1;
        }
            SDL_Window *win = SDL_CreateWindow("QGate", 0, 0, 1200, 800, SDL_WINDOW_SHOWN);
                if (win == 0) {
                cout << "window failed";
                return 1;
                }
vector<Gates>gate;
for (int i = 1; i < 5; ++i)
{
	gate.push_back(Gates(i));
}
vector<vector<Gates>>map;
map.push_back(gate);
paint_map(map,win);
SDL_Delay(3000);
return 0;}

