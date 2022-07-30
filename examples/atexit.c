#include <stdio.h>
#include <stdlib.h>

void atexit_clean(void *data);

static void clean(void)
{
	atexit_clean(NULL);
}

void atexit_clean(void *data)
{
	static void *static_ptr;

	if (data)
	{
		static_ptr = data;
		atexit(clean);
	}
	else
		free(static_ptr);
}
