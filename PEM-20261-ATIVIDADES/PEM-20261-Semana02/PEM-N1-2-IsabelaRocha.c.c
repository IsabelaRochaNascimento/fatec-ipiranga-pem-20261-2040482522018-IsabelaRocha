
#include <stdio.h>
#include <string.h>

int main() {
    char frase[100]; //declara os caracteres
    int i; //controla o laço
    
    //pede pro usuario digitar a sua frase
    printf("Digite a frase completa: ");
    //le a frase digitada, fgets semprer reserva o /0
    fgets(frase, 100, stdin);
    
    //calcular o tamanho da frase
    int tamanho = strlen(frase);
    // contator de palvras 
    int contadorPalavras = 1;
    
    //laço de repeticao
    for(i = 0; i < tamanho; i++){
        //confere se o caractere atual e espaço
        if(frase [i] == ' '){ 
            //confere se e diferente de espaço
            //nao sendo o fim da string
            //se nao tem quebra de linha
            if(frase [i +1] != ' ' && frase [i + 1] != '\0' && frase [i + 1] != '\n'){
                
                //se for, incrementa o contador
                contadorPalavras = contadorPalavras + 1;
            }
        }
    }
        //mostra o total das palavras encontradas
        printf("O tota das palavras: %d\n", contadorPalavras);

    return 0;
}
