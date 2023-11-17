
#include "algoritmos.h"

int main(void) {

    int opcao, extent, keySearch = -1, *array;    
    printf("Bem-vindo ao nosso programa!\n");
    printf("                    --------Selecione uma opção----------           \n");
    printf("                    (1) - ALGORITMOS DE BUSCAS                      \n");
    printf("                    (2) - ALGORITMOS DE CLASSIFICAÇÃO               \n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("Digite o tamanho do vetor:\n");
            scanf("%d", &extent);
            array = geraVetorAleatorio1(extent);
            free(array);
            break;
        case 2:
            printf("Digite o tamanho do vetor:\n");
            scanf("%d", &extent);
            array = geraVetorAleatorio2(extent);
            free(array);
            break;
        default:    
            printf("Opção inválida!\n");
            break;
    }
    return 0;
}

