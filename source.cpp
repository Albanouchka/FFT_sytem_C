#include "source.h"
#include <fstream>
#include <iostream>

void SOURCE::COMPORTEMENT(){

	ifstream inReFile("input_real.txt");
	ifstream inImFile("input_im.txt");

	int 	tmpRe;
	int		tmpImag;

	if(!inReFile){
		cerr << "Unable to open file input_real.txt";
		exit(1);
	}
	

	if(!inImFile){
		cerr << "Unable to open file input_im.txt";
		exit(1);
	}
	wait();

	while(true){

		data_valid = false;

		if(!inReFile.eof() && !inImFile.eof())
		{
			data_valid = true;

			if(data_req){

				inReFile >> tmpRe;
				in_real.write(tmpRe)
				inImFile >> tmpImag;
				in_imag.write(tmpImag);
			}
			
		}
		else
		{ 
			inReFile.close();
			inImFile.close();
		};

		wait();
	};



}
