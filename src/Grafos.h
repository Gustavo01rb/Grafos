#ifndef __GRAFOS__
#define __GRAFOS__

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct GrafoLA ListaA;
typedef struct GrafoMA MatrizA;
typedef struct GrafoMI MatrizI;


//Lista de Ajacencia
struct GrafoLA{
   int key; // Conteúdo Armazenado
   int V; // Numero de vétices adjacentes
   int A; // Número de Arestas incidentes
   Lista *adj; //Endereços para os demais Vértices
};

//Matriz de adjacencia
struct GrafoMA{
   int key; // Conteúdo Armazenado
   int V; // Numero de vétices adjacentes
   int A; // Número de Arestas incidentes
   int **adj;
};

//Matriz de incidência
struct GrafoMI{
   int key; // Conteúdo Armazenado
   int V; // Numero de vétices adjacentes
   int A; // Número de Arestas incidentes
   int **adj;
};


GrafoMA initializeMA(int x);
GrafoMI initializeMI(int x);
GrafoLA initializeLA(int x);

int** MatrizVazia(int colunas, int linhas);


int** MatrizVazia(int colunas, int linhas){
	int **matriz = (int **)calloc(linhas , sizeof(int*));
	for(int i = 0; i < colunas; i++){
		matriz[i] = (int*)calloc(colunas , sizeof(int));
		for(int j = 0; j < colunas; j++)
			matriz[i][j] = 0;
	}
	
	return matriz;
}


#endif