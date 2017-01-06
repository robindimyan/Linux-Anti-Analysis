#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>

int check_ptrace()
{
	if ( ptrace(PTRACE_TRACEME) == -1 ) // Program kendisine "attach" olamadığı takdirde bu debugger kullanıldığına işaret edebilir.
		exit(0); // Bu durumda program kapansın
}

int main()
{
	check_ptrace();
	puts("No ptrace detected! Starting evil stuff..");
	
	return 0;
}
