#include "bmp.h"
#include "stego.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void notEnoughArgError() {
	printf("Error! Not enough arguments!\n");
}

int main(int argc, char **argv) {
	if (argc < 2) {
		notEnoughArgError();
		return 1;
	}
	if (strcmp(argv[1], "insert") == 0) {
		if (argc < 6) {
			notEnoughArgError();
			return 1;
		}
		char *imgFile = argv[2];
		char *resImgFile = argv[3];
		char *keyFile = argv[4];
		char *msgFile = argv[5];
		encrypt(imgFile, msgFile, keyFile, resImgFile);
		return 0;
	}
	if (strcmp(argv[1], "extract") == 0) {
		if (argc < 5) {
			notEnoughArgError();
			return 1;
		}
		char *imgFile = argv[2];
		char *keyFile = argv[3];
		char *msgFile = argv[4];
		decrypt(imgFile, keyFile, msgFile);
		return 0;
	}
	if (strcmp(argv[1], "crop-rotate") == 0) {
		if (argc < 8) {
			notEnoughArgError();
			return 1;
		}
		char *inputFile = argv[2];
		char *outputFile = argv[3];
		int x = atoi(argv[4]), y = atoi(argv[5]);
		int w = atoi(argv[6]), h = atoi(argv[7]);
		if (cropAndRotate(inputFile, outputFile, x, y, w, h) != 0)
			return 1;
		return 0;
	}
	printf("Nothing is done...\n");
	return 0;
}