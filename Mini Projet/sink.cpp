#include <systemc.h>
#include <fstream>
#include "sink.h"
#include <iostream>

using namespace std;
int i = 0;

void SINK::COMPORTEMENT(){
	
	//cout << "SINK instancié oui salue" << endl;

	ofstream outReFile("outputRe.txt");
	ofstream outImFile("outputIm.txt");
	
	float 		tmpRe;
	float		tmpImag;


	if(!outReFile){
		cerr << "Unable to open file outputRe.txt";
		exit(1);
	}
	if(!outImFile){
		cerr << "Unable to open file outputIm.txt";
		exit(1);
	}

	wait();

	while(true){

		data_req_sink = false;

		if(!outReFile.eof() && !outImFile.eof())
		{
			data_req_sink = true;

			if(data_valid_sink){

				
				tmpRe = out_real.read();
				//cout << tmpRe << endl;
				outReFile << tmpRe << endl;
				
				tmpImag = out_imag.read();
				outImFile << tmpImag << endl;
			}
			
		}
		else
		{ 
			outReFile.close();
			outImFile.close();
		};

		wait();
	}

	outReFile.close();
	outImFile.close();
	
	
}


