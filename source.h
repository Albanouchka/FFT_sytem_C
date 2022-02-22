#include <systemc.h>
#ifndef INPUT_H
#define INPUT_H

SC_MODULE(SOURCE){
	public:
		sc_in_clk clk;
		sc_fifo_out<float> fifo_source;

        SC_CTOR(SOURCE)
        {
            SC_THREAD(COMPORTEMENT);
            sensitive << clk.pos();
         }
	private:
	
	void COMPORTEMENT();
};

#endif
