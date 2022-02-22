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
	
	if(!outReFile){
		cerr << "Unable to open file outputRe.txt";
		exit(1);
	}
	if(!outImFile){
		cerr << "Unable to open file outputIm.txt";
		exit(1);
	}

	while(true){
		//cout << i << endl;
		if(i % 2 == 1){
			outImFile << fifo_sink.read() << endl;		
			//cout << "retour a la ligne" << endl;
			i++;
			wait();
		}
		else{
			outReFile << fifo_sink.read() << endl;
			//cout << "retour a la ligne bis" << endl;
			i++;
			wait();
		}		
		
	}

	outReFile.close();
	outImFile.close();
	
	
}


