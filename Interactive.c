#include "Interactive.h"

#include "Interpreter.h"
#include "StringUtils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void interactive() {
	char* input;
	initInterpreter(30000); // Initializing the interpreter

	while (1) {
		input = (char*)malloc(sizeof(char) * 256);
		printf(">>> ");
		scanf("%s", input);
		
		if (eval(input) == 1)
			break;

		free(input);
		printf("\n");
	}

	cleanUpInterpreter(); // Cleaning up afterwards
}
