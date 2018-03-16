#include "QBit.hpp"
#include "GateFunk.hpp"
#include "Gates.hpp"
using namespace std;

int main(int, char**){


double q = 1/sqrt(2);
complex<double> a (q,0.), b (q,0.);
QBit Bit1(a,b);
QBit Bit2(a,b);
QBit Bit3(a,b);
QBit Bit4(a,b);
vector<QBit*>Bits1, Bits2, Bits3, Bits4,Bits5;
Bits1.push_back(&Bit1);
Bits2.push_back(&Bit2);
Bits3.push_back(&Bit3);
Bits4.push_back(&Bit4);
Bits5.push_back(&Bit4);
Bits5.push_back(&Bit1);
try{
cout <<(*hadamard(Bits1)[0]).value <<endl;
cout <<(*pauli_x(Bits2)[0]).value <<endl;
cout <<(*pauli_y(Bits3)[0]).value <<endl;
cout <<(*pauli_z(Bits4)[0]).value <<endl;
cout <<(*hadamard(Bits5)[0]).value <<endl;}
catch (const runtime_error &e){
cout<<"runtime_error: "<<e.what()<<endl;}

cin.ignore();
return 0;}

