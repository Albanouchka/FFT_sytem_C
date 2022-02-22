#include "source.h"
#include <fstream>
#include <iostream>

void SOURCE::COMPORTEMENT(){

	ifstream inReFile("input_real.txt");
	ifstream inImFile("input_im.txt");

	float tmpRe;
	float tmpIm;

	if(!inReFile){
		cerr << "Unable to open file input_real.txt";
		exit(1);
	}
	

	if(!inImFile){
		cerr << "Unable to open file input_im.txt";
		exit(1);
	}

	while(true){
		if(!inReFile.eof()&&!inImFile.eof())
		{
			inReFile >> tmpRe;
			inImFile >> tmpIm;
			fifo_source.write(tmpRe);
			fifo_source.write(tmpIm);
		}
		else
		{ 
	  		//cout << "End of file" << endl;
	  		
		}
		wait();
	}

	inReFile.close();
	inImFile.close();

}
