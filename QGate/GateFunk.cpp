#include "GateFunk.hpp"

using namespace std;
vector<complex<double>> tensv(vector<QBit> Bits){
vector<vector<complex<double>>> veks;
for (QBit bit : Bits){
    veks.push_back(bit.vek);
}
tensvh(&veks);
return veks[0];
}

void tensvh(vector<vector<complex<double>>>* veks){
    vector<complex<double>>zwischen;
    for (complex<double>num1 : (*veks)[0]){
        for (complex<double>num2 : (*veks)[1]){
            zwischen.push_back(num1*num2);
        }
    }
    (*veks)[1] = zwischen;
    (*veks).erase((*veks).begin()+0);
    if ((*veks).size() != 1)
        tensvh(veks);

}

vector<vector<complex<double>>> tensm(vector<Gates>gate){
    vector<vector<vector<complex<double>>>> mats;
    for (Gates g:gate){
        mats.push_back(g.mat[0]);
    }
    tensmh(&mats);
    return mats[0];
}

void tensmh(vector<vector<vector<complex<double>>>>* mats){
    vector<vector<complex<double>>>zwischen;
    for (vector<complex<double>>vek1 : (*mats)[0]){
        for (vector<complex<double>>vek2 : (*mats)[1]){
            vector<vector<complex<double>>>veks;
            veks.push_back(vek1);
            veks.push_back(vek2);
            tensvh(&veks);
            zwischen.push_back(veks[0]);
        }
    }
    (*mats)[1] = zwischen;
    (*mats).erase((*mats).begin()+0);
    if ((*mats).size() != 1)
        tensmh(mats);

}


void paint_map(vector<vector<Gates>>map, SDL_Window *win){
    for(vector<Gates> uv : map){
        for(Gates g : uv){
            g.paint_gate(win);
        }
    }
}
