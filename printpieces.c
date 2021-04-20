#include <stdio.h>
//#include "io.h"
#include <fcntl.h>

int main()
{
//_setmode(_fileno(stdout), _O_U16TEXT);
//wprintf(L"\x2654");
printf("\u2654 \n");
return 0;
}
