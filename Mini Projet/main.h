#include "sink.h"
#include "source.h"
#include "fft8.h"
#include <systemc.h>

#ifndef MAIN_H
#define MAIN_H

SC_MODULE(MAIN) {

    sc_clock            clk;
    sc_signal<bool>     data_valid;
    sc_signal<bool>     data_req;
    sc_signal<float>    in_real;
    sc_signal<float>    in_imag;
    
    sc_fifo<float> fifo_fft_output;

    SOURCE  source1;
    SINK    sink1;
    FFT8    fft1;

    void INIT()
    {
    };

    SC_CTOR(MAIN)
        : clk("clk", 2, SC_NS, 0.5),
        source1 ("source1"),
        sink1 ("sink1"),
        fft1 ("fft1")
        {
            fft1.fft_out(fifo_fft_output);
            fft1.in_real(in_real);
            fft1.in_imag(in_imag);
            fft1.data_valid(data_valid);
            fft1.data_req(data_req);
            fft1.clk(clk);

            source1.clk(clk);
            source1.in_real(in_real);
            source1.in_imag(in_imag);
            source1.data_valid(data_valid);
            source1.data_req(data_req);
            
            sink1.clk(clk);
            sink1.fifo_sink(fifo_fft_output);
        }
    
};

#endif