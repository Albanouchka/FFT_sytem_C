#include <systemc.h>
#ifndef OUTPUT_H
#define OUTPUT_H

SC_MODULE(SINK){
	public:
		sc_in_clk clk;
    sc_in<float>  out_real;
    sc_in<float>  out_imag;
    sc_in<bool>   data_valid_sink;
    sc_out<bool>  data_req_sink;

    SC_CTOR(SINK)
    {
      SC_THREAD(COMPORTEMENT);
      sensitive << clk.pos();
    }

	private:
		void COMPORTEMENT();
    
};

#endif
