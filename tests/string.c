#include <assert.h>
#include <string.h>

void test_Str_length() {
	char *str = "This is a string";
	int desired_length = strlen(str), length;

	// FIXME: something is funky with my understanding of the stack. I poked
	// through this with the debugger for a few minutes and I'm fairly sure
	// that Str_length is popping the return address, and taking the length of
	// that. Then, it is jmp'ing to the address next on the stack, which is
	// the argument I'm (trying) to pass... Also related is the TODO in
	// string.s
	asm volatile
		("push %[address]\n\t"
		"call Str_length\n\t"
		"mov %%eax, %[output]"
		: [address] "=r" (str)
		: [output] "r" (length)
		: "%eax");

	assert(length == desired_length);
}

int main(void) {
	test_Str_length();

	return 0;
}
