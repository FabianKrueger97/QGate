#ifndef GATEFUNK_H
#define GATEFUNK_H
#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <math.h>
#include "QBit.hpp"
using namespace std;
vector<*QBit>hadamard(vector<*QBit>Bits){
    if Bits.size()>1
        throw runtime_error("Hadamard bekam Mehrbitinput!");
    if Bits.size()==0
        throw runtime_error("Hadamard bekam Nullbitinput!");
    string str_a, str_b;
    (*Bits[0]).a = (Bit.a + Bit.b)/sqrt(2)
    (*Bits[0]).b = (Bit.a - Bit.b)/sqrt(2)
    ostringstream a_stream, b_stream;
    a_stream << (*Bits[0]).a;
    b_stream << (*Bits[0]).b;
    (*Bits[0]).value = a_stream.str() + " |0> " + b_stream.str() + " |1>";
    return Bits;
}

vector<*QBit>pauli_x(vector<*QBit>Bits){
    if Bits.size()>1
        throw runtime_error("Pauli_X bekam Mehrbitinput!");
    if Bits.size()==0
        throw runtime_error("Pauli_X bekam Nullbitinput!");
    complex<double> a_copy = (*Bits[0]).a;
    (*Bits[0]).a = (*Bits[0]).b;
    (*Bits[0]).b = a_copy;
    ostringstream a_stream, b_stream;
    a_stream << (*Bits[0]).a;
    b_stream << (*Bits[0]).b;
    (*Bits[0]).value = a_stream.str() + " |0> " + b_stream.str() + " |1>";
    return Bits;
}

vector<*QBit>pauli_y(vector<*QBit>Bits){
    if Bits.size()>1
        throw runtime_error("Pauli_Y bekam Mehrbitinput!");
    if Bits.size()==0
        throw runtime_error("Pauli_Y bekam Nullbitinput!");
    complex<double> a_copy = (*Bits[0]).a;
    (*Bits[0]).a = (*Bits[0]).b;
    (*Bits[0]).b = a_copy;
    ostringstream a_stream, b_stream;
    a_stream << (*Bits[0]).a;
    b_stream << (*Bits[0]).b;
    (*Bits[0]).value = a_stream.str() + " |0> " + b_stream.str() + " |1>";
    return Bits;
}

#endif // GateFunk_H
