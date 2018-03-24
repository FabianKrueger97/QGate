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
for (int i = 1; i < 7; ++i)
{
	gate.push_back(Gates(i));
}
vector<vector<Gates>>map;
map.push_back(gate);
paint_map(map,win);
vector<Gates>rudi;
rudi.push_back(Gates(2));
rudi.push_back(Gates(3));
vector<vector<complex<double>>> red = tensm(gate);
/*for (vector<complex<double>> v : red){
	for(complex<double> num : v){
		cout << num;
	}
	cout<<endl;
}*/
cout<<"ready";
SDL_Delay(30000);
return 0;}

