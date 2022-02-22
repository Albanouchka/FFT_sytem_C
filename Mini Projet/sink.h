#include <systemc.h>
#ifndef OUTPUT_H
#define OUTPUT_H

SC_MODULE(SINK){
	public:
		sc_in_clk clk;
		sc_fifo_in<float> fifo_sink;


        SC_CTOR(SINK)
        {
          SC_THREAD(COMPORTEMENT);
          sensitive << clk.pos();
         }
	private:
	
	void COMPORTEMENT();
};

#endif
