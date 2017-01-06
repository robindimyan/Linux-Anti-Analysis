#include <stdio.h>
#include <stdlib.h>

void dummy();

void check_patching()
{
	char chk;
	static char checksum = 0x64; // Olması gereken checksum değeri. Debugger ile elde edilebilir. Farklı segmentte yer alması için static char olarak tanımlandı.

	for (int i = &check_patching; i <= &dummy+3; i++ ) // anti-breakpoint tekniğinde olduğu gibi bütün kod alanını tarıyoruz
	{
		char *p = i;
		chk += (*p) & 0xff; // Çok basit bir checksum algoritması, byte'ları toplayarak gidiyor.
	}

	if (chk != checksum) // Byte'ların toplamı asıl checksum değerine eşit değilse bu programın modifiye edildiğine işaret
		exit(0); // Bu durumda programı kapatalım.
}

int main()
{
	check_patching();
	puts("No patching detected! Starting evil stuff.."); // Pis işlerimiz..

	return 0;
}

void dummy()
{
	__asm__("nop");
}
