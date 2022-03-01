#include <systemc.h>

#ifndef FFT8_H
#define FFT8_H

#define W {\
	{1, 0}, \
	{0.7071067812, -0.7071067812}, \
	{0, -1}, \
	{-0.7071067812, -0.7071067812}\
}

typedef struct complex_s complex_t;

struct complex_s{
	sc_fixed<23,18> real;
	sc_fixed<23,18> imag;
};

void fft(complex_t in[8], complex_t out[8]);

SC_MODULE(FFT8){
    
    public :
    sc_in_clk clk;

    sc_in<sc_fixed<23,18>> in_real;
    sc_in<sc_fixed<23,18>> in_imag;
    sc_in<bool> data_valid;
    sc_out<bool> data_req;

    sc_out<sc_fixed<23,18>> out_real;
    sc_out<sc_fixed<23,18>> out_imag;
    sc_out<bool>  data_valid_sink;
    sc_in<bool>   data_req_sink;

    SC_CTOR(FFT8)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private :
    void COMPORTEMENT();

};


#endif