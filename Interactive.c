#include "Interactive.h"

#include "Interpreter.h"
#include "StringUtils.h"

#include <string.h>
#include <stdio.h>

void interactive() {
	char* input;
	while (1) {
		printf(">>> ");
		scanf("%s", input);
		
		if (equals(input, "quit"))
			break;
		eval(input);

		printf("\n");
	}
}
