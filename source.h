#include <systemc.h>
#include <sysc/datatypes/fx/sc_fixed.h>

#ifndef INPUT_H
#define INPUT_H

SC_MODULE(SOURCE){
	public:
		sc_in_clk               clk;
        sc_out<bool>            data_valid;
        sc_in<bool>             data_req;
        sc_int<sc_fixed<23,18>>  in_real; //Ne peut pas être un sc_in sinon il n'est pas modifiable
        sc_int<sc_fixed<23,18>>  in_imag; //idem

        SC_CTOR(SOURCE)
        {
            SC_THREAD(COMPORTEMENT);
            sensitive << clk.pos();
         }
	private:
	
	void COMPORTEMENT();
};

#endif
