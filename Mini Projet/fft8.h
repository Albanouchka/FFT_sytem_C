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

struct complex_s {
	double real;
	double imag;
};

void fft(complex_t in[8], complex_t out[8]);

SC_MODULE(FFT8){
    
    public :
    sc_in_clk clk;
    sc_fifo_out<float> fft_out;
    sc_in<float> in_real;
    sc_in<float> in_imag;
    sc_in<bool> data_valid;
    sc_out<bool> data_req;


    SC_CTOR(FFT8)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private :
    void COMPORTEMENT();

};


#endif