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

void klicked(vector<vector<Gates>>*map,vector<vector<Gates>>*palette,vector<QBit>*eingang,vector<QBit>*loesung,SDL_Window *win, SDL_Surface* aufgabe, bool *laeuft, bool *geschafft){
    int xn,yn, zeile, spalte;
    SDL_GetMouseState( &xn, &yn);
    if (xn>1179 && yn<51 ){
        *laeuft = false;
    }
    if (xn > 1000 && xn < 1100 && yn > 50 && yn < 100){
        vector<complex<double>> calc = gates_run(map,eingang);
        vector<complex<double>> soll = tensv((*loesung));
        paint_back(win, aufgabe);
        paint_gmap(palette,win);
        paint_gmap(map,win);
        *geschafft = abgleich(win,soll,calc);
        if (*geschafft == true){
            int x = 400, y = 20;
            for (QBit b:(*eingang)){
                b.paint_value(win, x,y);
                x +=50;
                }
            cout << "richtig"<< endl;
            SDL_UpdateWindowSurface(win);
            SDL_Delay(100000);
            return;
        }
        else{
            cout << "leider falsch" << endl;
            SDL_UpdateWindowSurface(win);
            SDL_Delay(100000);
            return;}

    }
    if (xn>999 && xn<1101 && yn>99 && yn<301){
        int t;
        if (yn<151){
            if (xn<1051)
                t = 1;
            else
                t = 2;
        }
        if (yn<201 && yn>150){
            if (xn<1051)
                t = 3;
            else
                t = 4;
        }
        if (yn<251 && yn>200)
            t = 5;
        if (yn<301 && yn>250)
            t = 6;
        Gates *gz = new Gates(t);
        (*gz).move(win,palette,map,aufgabe);
        SDL_GetMouseState( &xn, &yn);
        if (xn>800 || xn<400 || yn<70 || yn>720){
            delete gz;
            paint_back(win, aufgabe);
            paint_gmap(palette,win);
            paint_gmap(map,win);
            SDL_UpdateWindowSurface(win);
            return;
        }
        (*gz).pos_in(map);
        paint_back(win, aufgabe);
        paint_gmap(palette,win);
        paint_gmap(map,win);
        SDL_UpdateWindowSurface(win);
        delete gz;
        return;
    }
    if (xn<800 && xn>400 && yn > 65 && yn<725 && (60-(yn-65)%60)>5 && (60-(yn-65)%60)<55){
        xn -= 400;
        yn -= 65;
        zeile = (yn - yn%60)/60;
        spalte = (xn - xn%50)/50;
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
        int ty = (*map)[zeile][pos].type;
        if (ty == 0)
            return;
        Gates o(0);
        if (ueber[spalte]==ueber[spalte+1]){
            Gates u(0);
            u.pos_rect(spalte+1,zeile);
            o.pos_rect(spalte,zeile);
            (*map)[zeile][pos]=o;
            auto it = (*map)[zeile].begin();
            it = (*map)[zeile].insert(it+pos+1,u);
        }
        else if (ueber[spalte]==ueber[spalte-1]){
            Gates u(0);
            u.pos_rect(spalte,zeile);
            o.pos_rect(spalte-1,zeile);
            (*map)[zeile][pos]=o;
            auto it = (*map)[zeile].begin();
            it = (*map)[zeile].insert(it+pos+1,u);
        }
        else{
            o.pos_rect(spalte,zeile);
            (*map)[zeile][pos]=o;
        }
        Gates *gz = new Gates(ty);
        (*gz).move(win,palette,map,aufgabe);
        SDL_GetMouseState( &xn, &yn);
        if (xn>800 || xn<400 || yn<70 || yn>720){
            delete gz;
            paint_back(win,aufgabe);
            paint_gmap(palette,win);
            paint_gmap(map,win);
            SDL_UpdateWindowSurface(win);
            for (vector<Gates> uv:(*map)){
            for (Gates g : uv){
            cout << g.type;
            }
            cout << endl;
            }
            cout <<endl;
            return;
        }
        (*gz).pos_in(map);
        paint_back(win,aufgabe);
        paint_gmap(palette,win);
        paint_gmap(map,win);
        SDL_UpdateWindowSurface(win);
        delete gz;
        return;
    }

}   


void paint_back(SDL_Window *win, SDL_Surface* aufgabe){
    SDL_Surface *back = IMG_Load("./Bilder/map.png");
    SDL_Surface *screen;
    screen = SDL_GetWindowSurface(win);
    SDL_Rect dst;
    dst.x = 50;
    dst.y = 70;
    dst.w = 200;
    dst.h = 230;
    SDL_BlitSurface(back,NULL,screen,NULL);
    SDL_BlitSurface(aufgabe,NULL,screen,&dst);
    }
void paint_gmap(vector<vector<Gates>>*map, SDL_Window *win){
    for(vector<Gates> uv : (*map)){
        for(Gates g : uv){
            g.paint_gate(win);
        }
    }
}

vector<complex<double>> gates_run(vector<vector<Gates>>*map,vector<QBit>*Bits){
    vector<complex<double>> input = tensv((*Bits));
    for (vector<Gates> reihe : (*map)){
        vector<complex<double>> result = {};
        vector<vector<complex<double>>> uni = tensm(reihe);
        for (vector<complex<double>> zeile : uni){
            complex<double> eintrag = 0.;
            try{
            for (int i=0;i<zeile.size()-1;i++)
                eintrag += zeile[i]*input[i];
            result.push_back(eintrag);
        }
            catch (const runtime_error& err){
            cerr << err.what()<<endl;
        }
    }
        
        input = result;
}
return input;
}

double get_p(vector<complex<double>>a,vector<complex<double>>b){
    complex<double>result1,result2;
    for (int i = 0; i<a.size()-1; i++){
        result1+= conj(a[i])*b[i];
        result2+= conj(b[i])*a[i];
    }
    return abs(result1*result2);
}
bool abgleich(SDL_Window* win, vector<complex<double>> soll, vector<complex<double>>vist){
    vector<vector<QBit>>moeglichkeiten;
    vector<QBit> erste;
    for (int i=0;i<8;i++){
         erste.push_back(QBit(1.,0.));
        }
    moeglichkeiten.push_back(erste);
    for (int i = 0; i<8 ; i++){
        int s = moeglichkeiten.size();
        for (int j = 0; j<s;j++){
            vector<QBit> n_uv = moeglichkeiten[j];
            n_uv[i] = QBit(0.,1.);
            moeglichkeiten.push_back(n_uv);
        }
    }
    vector<vector<complex<double>>>tens_moes;
    vector<double>p;
    for (vector<QBit> uv : moeglichkeiten){
        vector<complex<double>>tens_moe = tensv(uv);
        p.push_back(get_p(tens_moe,vist));
        tens_moes.push_back(tens_moe);
    }
    double sum = 0., sum2 = 0., treffer;
    int wurf = rand();
    wurf = wurf%1000;
    treffer = ((double) wurf)/1000.;
    int i = 0;
    while (sum<treffer){
        sum+=p[i];
        i++;
    }
    i--;
    int x = 400, y = 720;
    for (QBit b:moeglichkeiten[i]){
        b.paint_value(win, x,y);
        x +=50;}
    
    if (tens_moes[i]==soll){
        return true;
    }
    else
        return false;


}