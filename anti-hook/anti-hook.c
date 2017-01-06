#include <stdio.h>
#include <stdlib.h>

void check_hook()
{
	if (getenv("LD_PRELOAD") != NULL) // LD_PRELOAD ortam değişkeninin içi doluysa bu function hook yapıldığına işaret.
		exit(0); // Bu durumda programı kapatalım.
}

int main()
{
	check_hook();
	puts("No hooks detected! Starting evil stuff..");

	return 0;
}
