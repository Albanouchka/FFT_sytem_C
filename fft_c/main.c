#include "fft.h"
#include <stdio.h>

void usage() 
{
	fprintf(stderr, "test_fft <input_file> <output_file>\n");
	fprintf(stderr, "\t <input_file> is the file containing the input samples\n");
	fprintf(stderr, "\t which must be processed by the FFT\n");
	fprintf(stderr, "\t <input_file> is the file where processed samples will\n");
	fprintf(stderr, "\t be written\n");
}

int main(int argc, char** argv) 
{
	if (argc < 3) {
		fprintf(stderr, "Missing arguments...\n");
		usage();
		return -1;
	}
	if (argc > 3) {
		fprintf(stderr, "Too many arguments...\n");
		usage();
		return -1;
	}

	FILE *input_file, *output_file;

	if (!(input_file = fopen(argv[1], "r+"))) {
		fprintf(stderr, "Failed to open file %s for reading\n", argv[1]);
		return -1;
	}
	if (!(output_file = fopen(argv[2], "w"))) {
		fprintf(stderr, "Failed to open file %s for writing\n", argv[2]);
		return -1;
	}
	complex_t in[8], out[8];
	char tmp_str[33];

	while (!feof(input_file)) {
	 		for (int i = 0; i < 8; i++) {
				int tmp_real, tmp_imag;
				fscanf(input_file, "%d %d\n", &tmp_real, &tmp_imag);
				in[i].real = (double)tmp_real;
				in[i].imag = (double)tmp_imag;
			}
			fft(in, out);
	 		for (int i = 0; i < 8; i++) {
				sprintf(tmp_str, "% e % e \n", out[i].real, out[i].imag);
				fwrite(tmp_str, 29, 1, output_file);
			}
	}

	fclose(input_file);
	fclose(output_file);
	return 0;
}
