#include "algoritmos.h"

int* geraVetorAleatorio1(int extent) {
    int keySearch = -1, i;

    FILE *file = fopen("busca.txt", "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int* array = (int*)malloc(extent * sizeof(int)); 
    if (array == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return NULL;  
    }

    printf("Elementos gerados: ");
    for (int i = 0; i < extent; i++) {
        array[i] = rand() % 1000;
        fprintf(file, "%d\t ", array[i]);
        printf("%d ", array[i]);
    }
    fprintf(file, "\n");
    fclose(file);

    printf("\n");    
    
    recebeKeySearch(array, extent, keySearch);    

    return array; 
}

//Função para ler os elementos gerados no arquivo//
void lerElementosDoArquivo1(const char *fp, int **array, int *extent) {

    FILE *file = fopen(fp, "r");
    
    if (file == NULL) {
        perror("Erro na abertura de arquivo");
        exit(EXIT_FAILURE);
    }

    int num;
    int size = 0;

    while (fscanf(file, "%d", &num) == 1) {
        size++;
    }

    *array = (int *)malloc(size * sizeof(int));
    if (*array == NULL) {
        perror("Erro ao alocar memória para o vetor");
        exit(EXIT_FAILURE);
    }

    //Volta ao início do arquivo//
    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &(*array)[i]);
    }

    *extent = size;
    fclose(file);
}

//Função para receber a chave de busca//
void recebeKeySearch(int *array, int extent, int keySearch){

    
    
    int i, contadorPosicoes = 0, *posicoes = NULL;      //Definição de um contador de posições (no caso de mais de uma) e um ponteiro para essas posições.//

    printf("Agora o digite o elemento que desejas buscar:\n");
    scanf("%d", &keySearch);

    lerElementosDoArquivo1("busca.txt", &array, &extent);


    //Chamadas das funções//
    buscaLinear(array, extent, keySearch, &posicoes, &contadorPosicoes);
    buscaLinearComSentinela(array, extent, keySearch);
    buscaBinaria(array, extent, keySearch);
    
    if (contadorPosicoes > 0){              
        printf("Elemento encontrado na(s) posição(ões):");
        for (i = 0; i < contadorPosicoes; i++){     //Caso haja duplicatas de um elemento//
            printf("%d\t", posicoes[i]);
        }
        printf("\n");
    }
    else{
        printf("Elemento não encontrado.\n");
    }
    free(posicoes);         //Liberação de memória alocada dinamicamente//
    
    geraResultadosBusca(array, extent, keySearch);
}

void geraResultadosBusca(int *array, int extent, int keySearch) {
    
    int contadorPosicoes = 0, *posicoes = NULL;

    clock_t inicio, fim;
    
    inicio = clock();
    int resultadoLinear = buscaLinear(array, extent, keySearch, &posicoes, &contadorPosicoes);
    fim = clock();
    printf("Tempo de Busca Linear para n=%d: %d ticks de clock - Tempo decorrido: %f segundos\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoSentinela = buscaLinearComSentinela(array, extent, keySearch);
    fim = clock();
    printf("Tempo de Busca Linear com Sentinela para n=%d: %d ticks de clock - Tempo decorrido: %f segundos\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoBinaria = buscaBinaria(array, extent, keySearch);
    fim = clock();
    printf("Tempo de Busca Binária para n=%d: %d ticks de clock - Tempo decorrido: %f segundos\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    if (contadorPosicoes > 0) {
        printf("Elemento encontrado na(s) posição(ões):");
        for (int i = 0; i < contadorPosicoes; i++) {
            printf("%d\t", posicoes[i]);
        }
        printf("\n");
    }
    else {
        printf("Elemento não encontrado.\n");
    }  

    free(posicoes);

    system("PAUSE");

}



//Função de busca sequencial linear simples//
int buscaLinear(int *array, int extent, int keySearch, int **posicoes, int *contadorPosicoes) {
    //Inicialização do contador de posições como ponteiro e alocação dinâmica para posições//
    *contadorPosicoes = 0;
    *posicoes = (int *)malloc (extent * sizeof(int));
    
    if (*posicoes == NULL){
        printf("Erro na alocação de memória.\n");
    }
    for (int i = 0; i < extent; i++) {      
        if (array[i] == keySearch) {
            (*posicoes)[(*contadorPosicoes)++] = i;
        }
    }
    return -1; 
    
}

//Função de busca sequencial linear com valor sentinela//
int buscaLinearComSentinela(int *array, int extent, int keySearch) {
    int lastElement = array[extent];       
    array[extent] = keySearch; 
    int i = 0;
    while (array[i] != keySearch) {     //Procura a chave de busca até encontrar//
        i++;
    }
    if ((i < extent - 1) || (array[extent - 1] == keySearch)) {     
        return i;  
    }
    return -1;     
}

//Função de busca binária//
int buscaBinaria(int *array, int extent, int keySearch) {
   
    int left = 0;
    int right = extent - 1;         
    while (left <= right) {
        int half = left + (right - left) / 2;
        if (array[half] == keySearch) {
            return half;
        }
        if (array[half] < keySearch) {
            left = half + 1;
        } else {
            right = half - 1;
        }
    }
    return -1;      
}
