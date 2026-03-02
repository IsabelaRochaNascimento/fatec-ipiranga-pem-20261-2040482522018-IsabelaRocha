#include <stdio.h>
        
    int main(){
        int idProduto[10] = {0}; // incia tudo com 0
        int idBusca, i;
        int opcao, encontrado;
        
        do{
        printf("MENU:\n");
        printf("\n1 - Criar\n");
        printf("\n2 - Colsulta\n");
        printf("\n3 - Atualizar\n");
        printf("\n4 - Deletar\n");
        printf("\n5 - Ler\n");
        printf("Digite a sua escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: //criar
            for(i = 0; i < 10; i++){
                if(idProduto[i] == 0){
                printf("\nDigite o ID do produto:\n");
                scanf("%d", &idProduto[i]);
               // break;
            }
          }
            break;
          
            case 2: //consulta
            printf("Digite o ID para buscar: ");
            scanf("%d", &idBusca);
            encontrado = 0;
            for(i = 0; i < 10; i++){
               if(idProduto[i] == idBusca){
                printf("ID encontrado na posicao %d\n", i);
                encontrado = 1;
                break;
               }
            } if(!encontrado){
                printf("Produto nao encontrado!");
            }   
            break;
            
            case 3: //atualizar
            printf("\nDigite o ID para alterar:\n");
            scanf("%d", &idBusca);
            for(i = 0; i < 10; i++){
                if(idProduto[i] == idBusca){
                printf("\nAtualizacao do ID:\n");
                scanf("%d", &idProduto[i]);
                break;
                }
            }
            break;
            
            case 4://exclusao
            printf("\nDigite o ID para excluir:\n");
            scanf("%d", &idBusca);
            for(i = 0; i < 10; i++){
                if(idProduto[i] == idBusca){
                    idProduto[i] = 0; 
                    printf("Produto excluido!\n");
                    break;
                }
            }
            break;
            
            case 5://listar todos
            printf("\nLista dos produtos:\n");
            for(i = 0; i < 10; i++){
                if(idProduto != 0){
                    printf("Posicao %d - ID %d\n", i, idProduto[i]);
                }
            }
            break;
            
            default:
                printf("Opcao Invalida!");
        } 
    } while(opcao != 5); //so sai do loop quando inserir o numero cinco 
        return 0;
}
    
