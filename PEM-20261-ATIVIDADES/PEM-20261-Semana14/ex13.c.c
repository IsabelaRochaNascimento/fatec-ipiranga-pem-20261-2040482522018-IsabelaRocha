#include <stdio.h>
#include "stringutil.h"

int main() {
    char str1[50] = "Arara";
    char str2[50] = "Fatec";

    printf("Vogais em '%s': %d\n", str2, contaVogais(str2));
    
    printf("Palindromo '%s'? %d\n", str1, ePalindromo(str1));
    
    inverteCString(str2);
    printf("Invertida: %s\n", str2);

    return 0;
}