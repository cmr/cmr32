#include <assert.h>
#include <string.h>

/* The Str_* functions are unique in that they conform to cdecl */

unsigned int Str_length(char *str) __attribute__((cdecl));

void test_Str_length() {
	char *str = "This is a string";
	int desired_length = strlen(str), length;

	length = Str_length(str);

	assert(length == desired_length);
}

int main(void) {
	test_Str_length();

	return 0;
}
