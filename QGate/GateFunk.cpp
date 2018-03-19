#include "GateFunk.hpp"

using namespace std;

vector<QBit*> hadamard(vector<QBit*> Bits) {
    if (Bits.size()>1)
        throw runtime_error("Hadamard bekam Mehrbitinput!");
    if (Bits.size()==0)
        throw runtime_error("Hadamard bekam Nullbitinput!");
    string str_a, str_b;
    complex<double> a_copy = (*Bits[0]).a;
    (*Bits[0]).a = ((*Bits[0]).a + (*Bits[0]).b)/sqrt(2);
    (*Bits[0]).b = (a_copy - (*Bits[0]).b)/sqrt(2);
    (*Bits[0]).make_value();
    return Bits;
}

vector<QBit*> pauli_x(vector<QBit*> Bits) {
    if (Bits.size()>1)
        throw runtime_error("Pauli_X bekam Mehrbitinput!");
    if (Bits.size()==0)
        throw runtime_error("Pauli_X bekam Nullbitinput!");
    complex<double> a_copy = (*Bits[0]).a;
    (*Bits[0]).a = (*Bits[0]).b;
    (*Bits[0]).b = a_copy;
    (*Bits[0]).make_value();
    return Bits;
}

vector<QBit*> pauli_y(vector<QBit*> Bits) {
    if (Bits.size()>1)
        throw runtime_error("Pauli_Y bekam Mehrbitinput!");
    if (Bits.size()==0)
        throw runtime_error("Pauli_Y bekam Nullbitinput!");
    complex<double> a_copy = (*Bits[0]).a, c = -1i;
    (*Bits[0]).a = (*Bits[0]).b*c;
    (*Bits[0]).b = a_copy*(-c);
    (*Bits[0]).make_value();
    return Bits;
}

vector<QBit*> pauli_z(vector<QBit*> Bits) {
    if (Bits.size()>1)
        throw runtime_error("Pauli_Z bekam Mehrbitinput!");
    if (Bits.size()==0)
        throw runtime_error("Pauli_Z bekam Nullbitinput!");
    (*Bits[0]).b = -((*Bits[0]).b);
    (*Bits[0]).make_value();
    return Bits;
}

