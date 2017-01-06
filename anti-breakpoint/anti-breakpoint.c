#include <stdio.h>
#include <stdlib.h>

void dummy();

void check_breakpoint()
{
	for (int i = &check_breakpoint; i <= &dummy+3; i++ ) // "check_breakpoint" fonksiyonundan "dummy" fonksiyonuna kadar olan kısmı
  {                                                    // yani diğer bir deyişle programımızı baştan sonra tarıyoruz.
		char *p = i;
		if ( (*p) & 0xff == 0xcc) // şayet herhangi bir adresin değeri "int 3" (breakpoint) opcode'una eşit ise bu debugger kullanıldığına işarettir.
			exit(0); // bu durumda program kapansın.
	}

}

int main()
{
	check_breakpoint();
	puts("No breakpoints detected! Starting evil stuff..");

	return 0;
}

void dummy()
{
	__asm__("nop");
}
