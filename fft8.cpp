/*
 * Author: Pierre-Henri Horrein
 * Pure software C implementation of a 8 point FFT based on Cooley-Tuckey algorithm
 * This is a floating point implementation
 */

#include <stdio.h>
#include <string>
#include "fft8.h"


complex_t weights[4] = W;
complex_t in[8];
complex_t out[8];

int compteur = 0;
int compteur_sink = 0;
int total_length = 20;
int integer_length = 10;
int zero_index = total_length-integer_length;

void but1(complex_t *weight,
					complex_t *in0,
					complex_t *in1,
					complex_t *out0,
					complex_t *out1)
                     
{
      sc_dt::sc_fixed<30, 20> tmp;

      tmp = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
      sc_dt::sc_fixed<30,20> tranche = tmp; 
      out0->real = tranche << 7;

      tmp = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp; 
      out0->imag = tranche << 7;

      tmp = in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag));
      tranche = tmp;
      out1->real = tranche << 7;

      tmp = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp;
      out1->imag = tranche << 7;
}

void but2(complex_t *weight,
					complex_t *in0,
					complex_t *in1,
					complex_t *out0,
					complex_t *out1)
                     
{
      sc_dt::sc_fixed<30, 20> tmp;

      tmp = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
      sc_dt::sc_fixed<30,20> tranche = tmp; 
      out0->real = tranche << 7;

      tmp = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp; 
      out0->imag = tranche << 7;

      tmp = in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag));
      tranche = tmp;
      out1->real = tranche << 7;

      tmp = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp;
      out1->imag = tranche << 7;
}

void but3(complex_t *weight,
					complex_t *in0,
					complex_t *in1,
					complex_t *out0,
					complex_t *out1)
                     
{
      sc_dt::sc_fixed<30, 20> tmp;

      tmp = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
      sc_dt::sc_fixed<30,20> tranche = tmp; 
      //out0->real = (tranche.read().range(integer_length-18,total_length-integer_length)).to_int() + 0.000001*(tranche.read().range(total_length-integer_length, total_length-integer_length-5)).to_int();
      out0->real = tranche << 7;

      tmp = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp; 
      out0->imag = tranche << 7;

      tmp = in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag));
      tranche = tmp;
      out1->real = tranche << 7;

      tmp = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
      tranche = tmp;
      out1->imag = tranche << 7;
}
	
void fft(complex_t in[8], complex_t out[8]) 
{
	complex_t stage1[8], stage2[8];

	// First stage
	but1(&weights[0], &in[0], &in[4], &stage1[0], &stage1[1]);
	but1(&weights[0], &in[2], &in[6], &stage1[2], &stage1[3]);
	but1(&weights[0], &in[1], &in[5], &stage1[4], &stage1[5]);
	but1(&weights[0], &in[3], &in[7], &stage1[6], &stage1[7]);

	// Second stage
	but2(&weights[0], &stage1[0], &stage1[2], &stage2[0], &stage2[2]);
	but2(&weights[2], &stage1[1], &stage1[3], &stage2[1], &stage2[3]);
	but2(&weights[0], &stage1[4], &stage1[6], &stage2[4], &stage2[6]);
	but2(&weights[2], &stage1[5], &stage1[7], &stage2[5], &stage2[7]);
                
	// Etape 3
	but3(&weights[0], &stage2[0], &stage2[4], &out[0], &out[4]);
	but3(&weights[1], &stage2[1], &stage2[5], &out[1], &out[5]);
	but3(&weights[2], &stage2[2], &stage2[6], &out[2], &out[6]);
	but3(&weights[3], &stage2[3], &stage2[7], &out[3], &out[7]);
}



void FFT8::COMPORTEMENT(){


while(true){
    data_req = false;
    data_valid_sink = false;

    if(compteur < 8){
        
        data_req = true;

        if (data_valid){
            in[compteur].real = in_real;
            in[compteur].imag = in_imag;
            compteur++;
        }

        if(compteur == 8){
            data_req = false;
            
            compteur_sink = 0;
        }
    }
    else{
        fft(in, out);
        data_valid_sink = true;

        if(data_req_sink){
            out_real = out[compteur_sink].real;
            out_imag = out[compteur_sink].imag;

            compteur_sink++;
        }

        if(compteur_sink == 8){
            wait();
            data_valid_sink = false;
            data_req = true;
            compteur = 0;
        }

    }
    
    wait();      

};

}
