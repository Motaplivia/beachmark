#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <x86intrin.h>

int *geraVetorAleatorio1(int extent);
int* geraVetorAleatorio2(int extent);

/*Protótipos de funções para busca*/
void recebeKeySearch(int *array, int extent, int keySearch);
void lerElementosDoArquivo1(const char *fp, int **array, int *extent);
void geraResultadosBusca(int *array, int extent, int keySearch);
int buscaLinear(int *array, int extent, int keySearch, int **posicoes, int *contadorPosicoes);
int buscaLinearComSentinela(int *array, int extent, int keySearch);
int buscaBinaria(int *array, int extent, int keySearch);

/*Protótipos de funções para classificação/ordenação*/
void geraResultadosOrdenacao(int *array, int extent);
void lerElementosDoArquivo2(const char *fp, int **array, int *extent);
void insertionSort(int *array, int extent);
void selectionSort(int *array, int extent);
void bubbleSort(int *array, int extent);
int realizaParticao(int *array, int inicio, int fim);
void quickSort(int *array, int inicio, int fim);
void realizaMescla(int *array, int inicio, int meio, int fim);
void mergeSort(int *array, int inicio, int fim);


#endif