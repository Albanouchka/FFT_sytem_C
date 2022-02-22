 // main . cpp
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
//trace()du canal que l'on veut suivre
mainTop.fifo_input_fft.trace(tf);
mainTop.fifo_fft_output.trace(tf);
//Lancement de la simulation
sc_start(2000 , SC_NS);
// Fin
cout << "Finishe dat " << sc_time_stamp ( ) << " \n " ;
// Fermeture du fichier de traces
sc_close_vcd_trace_file(tf);
return 0 ;
}