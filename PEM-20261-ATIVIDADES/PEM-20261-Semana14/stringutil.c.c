#include "stringutil.h"
#include <string.h>

int contaVogais(char *s) {
    int cont = 0;
    while(*s) {
        char c = *s;
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') cont++;
        s++;
    }
    return cont;
}

void inverteCString(char *s) {
    int tam = strlen(s);
    for(int i = 0; i < tam/2; i++) {
        char aux = s[i];
        s[i] = s[tam - 1 - i];
        s[tam - 1 - i] = aux;
    }
}

int ePalindromo(char *s) {
    int tam = strlen(s);
    for(int i = 0; i < tam/2; i++) {
        if(s[i] != s[tam - 1 - i]) return 0;
    }
    return 1;
}