#include <stdio.h>
int main(){
    char tabuleiro[3][3]; //armazenar valores do jogo
    char jogador = 'X';  //jogador inicial
    char vencedorJogador;
    int vencedor = 0; // ninguem venceu ainda
    int i, j;
    int linha, coluna;
    int jogadas = 0;
    
    for(i = 0; i < 3; i++){ //percorre cada linha
        for(j = 0; j < 3; j++){ //percorre cada coluna 
            tabuleiro[i][j]= ' '; //espaço vazio
        }
    } 
    do{
         for(i = 0; i < 3; i++){
            printf(" %c | %c | %c\n", 
            tabuleiro[i][0],
            tabuleiro[i][1],
            tabuleiro[i][2]);
            
            if(i <2)
            printf("---+---+---\n");
        }
        //começa a rodada
        printf("\nJogador %c\n", jogador);
        printf("Digite linha e coluna(0 a 2): ");
        scanf("%d%d", &linha, &coluna);
        
        //verifica a posiçao
        if(tabuleiro [linha][coluna] == ' '){
            tabuleiro[linha][coluna] = jogador;
            jogadas++;
        } 
        else{
            printf("Posiçao ocupada!\n");
        } 
        
        //verifica linhas
        for(i = 0; i < 3; i++)
            if(tabuleiro[i][0] == jogador &&
                tabuleiro[i][1] == jogador &&
                tabuleiro[i][2] == jogador){
                vencedor = 1;
                vencedorJogador = jogador;
        }
          // verificar colunas
        for(i = 0; i < 3; i++)
            if(tabuleiro[0][i] == jogador &&
               tabuleiro[1][i] == jogador &&
               tabuleiro[2][i] == jogador){
                vencedor = 1;
                vencedorJogador = jogador;
        }

        // verificar diagonais
        if(tabuleiro[0][0] == jogador &&
           tabuleiro[1][1] == jogador &&
           tabuleiro[2][2] == jogador){
            vencedor = 1;
            vencedorJogador = jogador;
        }
        
        //troca de jogador
        if(jogador == 'X'){
              jogador = '0';
        }
        else{
            jogador = 'X';
        }
    }while(vencedor == 0 && jogadas < 9);
    
        // mostrar tabuleiro final
        printf("\nTabuleiro final:\n");

        for(i = 0; i < 3; i++){
        printf(" %c | %c | %c\n",
               tabuleiro[i][0],
               tabuleiro[i][1],
               tabuleiro[i][2]);

        if(i < 2)
            printf("---+---+---\n");
    }
        // resultado final
        if(vencedor == 1){
        printf("\nO jogador %c venceu!\n", vencedorJogador);
        }else{ 
        printf("\nO jogo terminou em empate.\n");
        }
     
    return 0;
}