#include <systemc.h>

#ifndef FFT8_H
#define FFT8_H

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