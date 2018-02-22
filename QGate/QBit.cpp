#include "QBit.hpp"
using namespace std;
QBit::QBit(complex<double>a0, complex<double>b0){
    a = a0;
    b = b0;
    ostringstream a_real_stream, b_real_stream, a_im_stream, b_im_stream;
    a_real_stream << a.real();
    b_real_stream << b.real();
    a_im_stream << a.imag();
    b_im_stream << b.imag();
    value = a_real_stream.str()+"+"+"i*"+a_im_stream.str() + " |0> " + b_real_stream.str()+"+"+"i*"+b_im_stream.str() + " |1>";
}

void QBit::make_value(){
    ostringstream a_real_stream, b_real_stream, a_im_stream, b_im_stream;
    a_real_stream << a.real();
    b_real_stream << b.real();
    a_im_stream << a.imag();
    b_im_stream << b.imag();
    if (abs(a)==0){
        if (abs(b)==b.real())
            value = "|1>";
        else if (abs(b)==b.imag())
            value = "i * "+b_im_stream.str() + " |1>";
        else
            value = "(" + b_real_stream.str()+" + "+"i * "+b_im_stream.str() +")" + " |1>";}
    else if (abs(b)==0){
        if (abs(a)==a.real())
            value = "|0>";
        else if (abs(a)==a.imag())
            value = "i * "+a_im_stream.str() + " |0>";
        else
            value = "(" + a_real_stream.str()+" + "+"i * "+a_im_stream.str() +")" + " |0>";}
    else
        value ="("+a_real_stream.str()+" + "+"i * "+a_im_stream.str()+ ")" + " |0> " + " + "  + "(" + b_real_stream.str()+" + "+"i * "+b_im_stream.str() +")" + " |1>";
}
