#include "StringUtils.h"

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

}
