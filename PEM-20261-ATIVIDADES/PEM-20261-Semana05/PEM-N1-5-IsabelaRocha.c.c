#include <stdio.h>
//para usar textos
#include <string.h>

//uma diretiva
//entao toda vez que digitar TAM o compilador entende que e 8
#define TAM 8

//void retorna
//char recebe o tabuleiro
void inicializarTabuleiro(char tab[TAM][TAM][4]);//montar tabuleiro
void mostrarTabuleiro(char tab[TAM][TAM][4]);//imprimir tabuleiro

//cada um, representa o lance do xeque pastor
void jogada1(char tab[TAM][TAM][4]);
void jogada2(char tab[TAM][TAM][4]);
void jogada3(char tab[TAM][TAM][4]);
void jogada4(char tab[TAM][TAM][4]);

int main() {
	//linha coluna e texto
	char tabuleiro[TAM][TAM][4];
//montar o tabuleiro
	inicializarTabuleiro(tabuleiro);

	printf("\nTabuleiro Inicial\n");
	mostrarTabuleiro(tabuleiro);
//executar as jogadas
	jogada1(tabuleiro);
	mostrarTabuleiro(tabuleiro);

	jogada2(tabuleiro);
	mostrarTabuleiro(tabuleiro);

	jogada3(tabuleiro);
	mostrarTabuleiro(tabuleiro);

	jogada4(tabuleiro);
	mostrarTabuleiro(tabuleiro);

	return 0;
}
//mostrar o tabuleiro
void mostrarTabuleiro(char tab[TAM][TAM][4]) {
	int i, j;
	printf("\n");
	for(i = 0; i < TAM; i++) {
		for(j = 0; j < TAM; j++) {
			printf("%s\t", tab[i][j]);
		}
		printf("\n");
	}
}
//inicializa o tabuleiro
void inicializarTabuleiro(char tab[TAM][TAM][4]){
	int i, j;
  for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
           strcpy(tab[i][j], "---");
        }
    } 
    //peoes brancos
       for(j = 0; j < TAM; j++)
        strcpy(tab[6][j], "PB");
    //peoes pretos
        for(j = 0; j < TAM; j++)
         strcpy(tab[1][j], "PP");
         
    strcpy(tab[7][3], "DB");//dama branca
    strcpy(tab[7][5], "BB");//bispo branco
}
//jogada1
void jogada1(char tab[TAM][TAM][4]){
    printf("\nJogada 1\n");
    
    //PB
    strcpy(tab[6][4], "...");
    strcpy(tab[4][4], "PB5");
    //PP
    strcpy(tab[1][4], "...");
    strcpy(tab[3][4], "PP5");
}
//jogada2
void jogada2(char tab[TAM][TAM][4]){
    printf("\nJogada 2\n");
    
    //BB
    strcpy(tab[7][5], "...");
    strcpy(tab[4][2], "BB");
    //CP
    strcpy(tab[0][1], "...");
    strcpy(tab[2][2], "CP");
}
//jogada3
void jogada3(char tab[TAM][TAM][4]){
    printf("\nJogada 3\n");
    
    //DB
    strcpy(tab[7][3], "...");
    strcpy(tab[3][7], "DB");
    //CP
    strcpy(tab[0][6], "...");
    strcpy(tab[2][5], "CP");
}
//jogada4 xeque mate
void jogada4(char tab[TAM][TAM][4]){
    printf("\nJogada 4 - Xeque Mate\n");
    
    //dama captura peao em [1][5]
    strcpy(tab[3][7], "...");
    strcpy(tab[1][5], "DB");
   
}
