#include "StringUtils.h"

#include <string.h>

int getSize(char* string) {
	char c;
	for (int x = 0;; x++) {
		c = string[x];
		if (c == '\0')
			return x;
	}

	return -1;
}

unsigned short equals(char* str1, char* str2) {
	int res = strcmp(str1, str2);

	if (res == 0)
		return 1;
	else
		return 0;
}
