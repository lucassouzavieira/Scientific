#ifndef MATRIX_H
#define MATRIX_H

#include <inttypes.h>

// Cria uma nova matriz de números aleatórios
int64_t** newMatrix(unsigned int order);

// Soma duas matrizes
int64_t** sum(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order);

// Retira um bloco de uma matriz
int64_t** getBlock(int64_t** matrix, unsigned int order, unsigned int blockNumber);

// Forma uma matriz maior com os blocos repassados
int64_t** mergeBlocks(int64_t** firstMatrix, int64_t** sndMatrix,
	int64_t** thrdMatrix, int64_t** fourthMatrix,
	unsigned int order);

// Faz multiplicação por blocos nas matrizes
int64_t** blockProduct(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order);

// Multiplica duas matrizes
int64_t** product(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order);

// Retorna a tranposta de uma matriz
int64_t** transpose(int64_t** matrix, unsigned int order);

// Retorna a linha da matriz
int64_t* getRow(int64_t** matrix, unsigned int row, unsigned int order);

// Retorna a coluna da matriz
int64_t* getColumn(int64_t** matrix, unsigned int column, unsigned int order);

// Retorna a diagonal de uma matriz
int64_t* getDiagonal(int64_t** matrix, unsigned int order);

// Imprime a matriz
void print(int64_t** matrix, unsigned int order);


#endif // !MATRIX_H