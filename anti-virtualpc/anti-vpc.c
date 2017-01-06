#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void evil_func() // Pis işlerimizi yapacağımız fonksiyon..
{
	puts("No VirtualPC detected! Starting evil stuff..");
	exit(0);
}

void catch_segfault() // Segmentation-fault sinyali handler'ı, şayet sinyal yakalanırsa VirtualPC yok demek. Yani pis işlerimizi yapabiliriz.
{
	evil_func();
}

void check_vm()
{
	char * code = {     // Çalıştırılacak shellcode.
		"\x90\x90\x90\x90"
		"\x0f\x3f\x07\x0b" // Bu satırdaki değerler VirtualPC'ye özel opcode değerleri.
		"\xc3"             // Bunları normalde çalıştırmayı denediğinizde segmentation-fault hatasıyla karşılaşırsınız.
	};

	void (*fPtr)(void); // Fonksiyon pointer tanımladık.

	fPtr = mmap(NULL, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0); // Fonksiyonumuz için hafızadan yer ayırdık ve bu alana RWX izinlerini verdik.
	memcpy(fPtr, code, 5); // Shellcode'umuzu bu tahsis edilen alana kopyaladık.

	fPtr(); // Ardından fonksiyonumuzu çağırdık. Bu kod Virtual PC dışında biyerde çalıştırıldığında Segmentation Fault hatası verecek.
}

int main()
{
	signal( SIGSEGV, catch_segfault); // Segmentation fault signali'ni dinlemeye alıyoruz.
	check_vm(); // Virtual PC içerisindemiyiz bakalım..
	puts("Virtual PC detected.."); // Şayet Virtual PC'de çalışıyorsak shellcode başarıyla çalışacak dolayısı ile hata üretmeyecek.
	return 0; // Bu durumda da herhangi bir işlem yapmadan programı kapatalım.
}
