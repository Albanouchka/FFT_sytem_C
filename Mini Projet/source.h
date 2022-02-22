#include <systemc.h>
#ifndef INPUT_H
#define INPUT_H

SC_MODULE(SOURCE){
	public:
		sc_in_clk clk;
        sc_out<bool> data_valid;
        sc_in<bool> data_req;
        sc_out<float> in_real;
        sc_out<float> in_imag;

        SC_CTOR(SOURCE)
        {
            SC_THREAD(COMPORTEMENT);
            sensitive << clk.pos();
         }
	private:
	
	void COMPORTEMENT();
};

#endif
