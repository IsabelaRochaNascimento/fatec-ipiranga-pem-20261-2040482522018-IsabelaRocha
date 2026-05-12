#include <stdio.h>
#include "interface.h"

int main()
{
    int opcao;

    do
    {
        mostrarMenu();
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                menuBinario();
                break;

            case 2:
                menuPotencia();
                break;

            case 3:
                menuSomaDigitos();
                break;

            case 0:
                printf("programa encerrado\n");
                break;

            default:
                printf("opcao invalida\n");
        }

    } while(opcao != 0);

    return 0;
}
