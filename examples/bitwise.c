#include <stdio.h>

#define FIRST_STATE (1L<<0)
#define SECOND_STATE (1L<<1)
#define THIRD_STATE (1L<<2)
#define FOURTH_STATE (1L<<3)
#define FIFTH_STATE (1L<<4)
#define SIXTH_STATE (1L<<5)
#define SEVENTH_STATE (1L<<6)
#define EIGHTH_STATE (1L<<7)

void check_current_state(unsigned long flags)
{
	if (flags & FIRST_STATE)
		printf("First | ");
	if (flags & SECOND_STATE)
		printf("Second | ");
	if (flags & THIRD_STATE)
		printf("Third | ");
	if (flags & FOURTH_STATE)
		printf("Fourth | ");
	if (flags & FIFTH_STATE)
		printf("Fifth | ");
	if (flags & SIXTH_STATE)
		printf("Sixth | ");
	if (flags & SEVENTH_STATE)
		printf("Seventh | ");
	if (flags & EIGHTH_STATE)
		printf("Eighth | ");
	printf("are set\n\n");
}

int main(void)
{
	unsigned long flags = 0;

	flags = FIRST_STATE | SECOND_STATE | THIRD_STATE;
	check_current_state(flags);
	flags = flags | FOURTH_STATE;
	check_current_state(flags);
	flags = flags | FIFTH_STATE | SIXTH_STATE | SEVENTH_STATE | EIGHTH_STATE;
	check_current_state(flags);
	flags = flags & ~EIGHTH_STATE & ~SEVENTH_STATE & ~SIXTH_STATE & ~FIFTH_STATE & ~FOURTH_STATE;
	check_current_state(flags);

	return 0;
}
