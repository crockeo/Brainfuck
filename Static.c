#include "Static.h"

#include "Interpreter.h"
#include "StringUtils.h"
#include <stdlib.h>
#include <stdio.h>

void staticRead(char* location) {
	// Opening the file
	FILE* file = fopen(location, "r");
	if (file == NULL) {
		printf("ERROR: File link could not be created.");
		return;
	}

	// Initializing the interpreter
	initInterpreter(30000);

	// Evaluate loop
	int res = 0;
	while (res != EOF) {
		res = fgetc(file);
		if (res == EOF)
			continue;
		
		evalChar((char)res);
	}

	// Cleaning up after yourself
	cleanUpInterpreter();
	printf("\n");
}
