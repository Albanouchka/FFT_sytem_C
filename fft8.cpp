#include "fft8.h"

#include <fstream>
#include <iostream>


void FFT8::COMPORTEMENT(){

while(true){
    fft_out.write(fft_in.read());
    wait();
}
}
