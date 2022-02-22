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
    sc_fifo_in<float> fft_in;

    SC_CTOR(FFT8)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk;
    }

    private :
    void COMPORTEMENT();

};


#endif