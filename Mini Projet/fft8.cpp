/*
 * Author: Pierre-Henri Horrein
 * Pure software C implementation of a 8 point FFT based on Cooley-Tuckey algorithm
 * This is a floating point implementation
 */

#include <stdio.h>
#include "fft8.h"


complex_t weights[4] = W;
complex_t in[8];
complex_t out[8];

int compteur =0;
float tmp[16];


void but(complex_t *weight,
					complex_t *in0,
					complex_t *in1,
					complex_t *out0,
					complex_t *out1)
{
      out0->real = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
      out0->imag = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
      out1->real = (in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag)));
      out1->imag = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
}

	
void fft(complex_t in[8], complex_t out[8]) 
{
	complex_t stage1[8], stage2[8];

	// First stage
	but(&weights[0], &in[0], &in[4], &stage1[0], &stage1[1]);
	but(&weights[0], &in[2], &in[6], &stage1[2], &stage1[3]);
	but(&weights[0], &in[1], &in[5], &stage1[4], &stage1[5]);
	but(&weights[0], &in[3], &in[7], &stage1[6], &stage1[7]);

	// Second stage
	but(&weights[0], &stage1[0], &stage1[2], &stage2[0], &stage2[2]);
	but(&weights[2], &stage1[1], &stage1[3], &stage2[1], &stage2[3]);
	but(&weights[0], &stage1[4], &stage1[6], &stage2[4], &stage2[6]);
	but(&weights[2], &stage1[5], &stage1[7], &stage2[5], &stage2[7]);
                
	// Etape 3
	but(&weights[0], &stage2[0], &stage2[4], &out[0], &out[4]);
	but(&weights[1], &stage2[1], &stage2[5], &out[1], &out[5]);
	but(&weights[2], &stage2[2], &stage2[6], &out[2], &out[6]);
	but(&weights[3], &stage2[3], &stage2[7], &out[3], &out[7]);
}



void FFT8::COMPORTEMENT(){


while(true){
    data_req = false;

    if(compteur < 8){
        
        data_req = true;

        if (data_valid){
            in[compteur].real = in_real;
            in[compteur].imag = in_imag;
            cout << in[compteur].real << "+ i"<< in[compteur].imag << endl;
            cout << "compteur : " << compteur << endl;
            compteur++;
        }

        if(compteur == 8){
            data_req = false;
        }
    }

    else{
        
        data_req = true;
        fft(in, out);
        compteur = 0;

        for(int k = 0; k<8; k++){
            fft_out.write(out[k].real);

            fft_out.write(out[k].imag);

        }

    }
    
    wait();      

};

}
