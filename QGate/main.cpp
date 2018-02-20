#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <stdio.h>
#include "QBit.hpp"
#include "Gates.hpp"
#include "GateFunk.hpp"

using namespace std;

int main () {
    std::complex<double> qbits_input, qbits_input2;
    vector<QBit*> qbits_vec;
    
    cout << "Input your QBits: " << endl;
    cin >> qbits_input;
    cin >> qbits_input2;

    QBit qbits(qbits_input,qbits_input2);
    qbits_vec.push_back(&qbits);
    
    cout << "After applying Hadamard: " << hadamard(qbits_vec)[0] << endl;
}
