#include "sink.h"
#include "source.h"
#include "fft8.h"
#include <systemc.h>

#ifndef MAIN_H
#define MAIN_H

SC_MODULE(MAIN) {

    sc_clock   clk;
    sc_fifo<float> fifo_input_fft;
    sc_fifo<float> fifo_fft_output;

    SOURCE  source1;
    SINK    sink1;
    FFT8    fft1;

    void INIT();

    SC_CTOR(MAIN)
        : clk("clk", 2, SC_NS, 0.5),
        source1 ("source1"),
        sink1 ("sink1"),
        fft1 ("fft1")
        {
            fft1.fft_out(fifo_fft_output);
            fft1.fft_in(fifo_input_fft);
            fft1.clk(clk);

            source1.clk(clk);
            source1.fifo_source(fifo_input_fft);

            sink1.clk(clk);
            sink1.fifo_sink(fifo_fft_output);
        }
    
};

#endif