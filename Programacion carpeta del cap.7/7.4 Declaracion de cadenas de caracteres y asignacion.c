#include <stdio.h>
#include <stdlib.h>

void main(void) 
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    char cad1[100] = "";
    gets(cad1);

    char cad2[20] = "M�xico";
    puts(cad2);
    gets(cad2);
    puts(cad2);
}

