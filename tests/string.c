#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* The Str_* functions are unique in that they conform to cdecl */

extern unsigned int Str_length(char *str) __attribute__((cdecl));
extern void Str_copy(char *src, char *dst) __attribute__((cdecl));

void test_Str_length(void) {
	char *str = "This is a string";
	int desired_length = strlen(str), length;

	length = Str_length(str);

	assert(length == desired_length);
}

void test_Str_copy(void) {
	char *src = malloc(6), *dest = malloc(6);
	/* Otherwise those strings end up in a read-only segment or somesuch */
	strcpy(src, "Hello");
	strcpy(dest, "World");

	Str_copy(src, dest);

	assert(strcmp(dest, "Hello") == 0);
}

int main(void) {
	test_Str_length();
	test_Str_copy();

	return 0;
}
