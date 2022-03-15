// main.cpp
// Testbench pour FFT
#include <systemc.h>
#include "main.h"
int sc_main ( int argc , char * argv [ ] )
{

//Instanciation du TOP
MAIN mainTop("top") ;

//Creation des traces

sc_trace_file* tf = sc_create_vcd_trace_file("trace");
tf->set_time_unit(1,SC_NS);

//il faut fauire appel a la methode
//trace() du canal que l'on veut suivre

sc_trace(tf,mainTop.in_real, "in_real");
sc_trace(tf,mainTop.in_imag, "in_imag");
sc_trace(tf,mainTop.data_valid, "data_valid");
sc_trace(tf,mainTop.data_req, "data_req");
sc_trace(tf, mainTop.clk, "clk");

sc_trace(tf,mainTop.out_real, "out_real");
sc_trace(tf,mainTop.out_imag, "out_imag");
sc_trace(tf,mainTop.data_valid_sink, "data_valid_sink");
sc_trace(tf,mainTop.data_req_sink, "data_req_sink");

//Lancement de la simulation
sc_start(2000 , SC_NS);
// Fin

cout << "Finishe dat " << sc_time_stamp ( ) << "\n" ;

// Fermeture du fichier de traces
sc_close_vcd_trace_file(tf);
return 0 ;

}