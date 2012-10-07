#include "Static.h"

#include "Interpreter.h"
#include "StringUtils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int maxLines = 4096;
const int maxCharsPerLine = 512;

void staticRead(char* location) {
	// Creating all of the lines
	char* lines[maxLines];
	for (int i = 0; i < maxLines; i++)
		lines[i] = NULL;

	// Creating the file
	FILE* file;
	file = fopen(location, "r");
	if (file = NULL) {
		printf("ERROR: Could not create the file.");
		return;
	}
	
	fscanf(file, "%s", lines[0]);
	for (int i = 0; )

	initInterpreter(30000); // Initializing the interpreter
	
	cleanUpInterpreter(); // Cleaning up the interpeter
	fclose(); // Closing the file
}
