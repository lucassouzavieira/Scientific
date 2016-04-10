#ifndef MATRIX_H
#define MATRIX_H
#include <gmp.h>

typedef struct Matrix {
	BigInt** matrix;
	unsigned long int lines;
	unsigned long int columns;
};

// Cria uma nova matriz de números aleatórios
__int64** newMatrix(unsigned int order);

// Soma duas matrizes
__int64** sum(__int64** firstMatrix, __int64** sndMatrix, unsigned int order);

// Multiplica duas matrizes
__int64** product(__int64** firstMatrix, __int64** sndMatrix, unsigned int order);

// Retorna a tranposta de uma matriz
__int64** transpose(__int64** matrix, unsigned int order);

// Retorna a linha da matriz
__int64* getRow(__int64** matrix, unsigned int row, unsigned int order);

// Retorna a coluna da matriz
__int64* getColumn(__int64** matrix, unsigned int column, unsigned int order);

// Retorna a diagonal de uma matriz
__int64* getDiagonal(__int64** matrix, unsigned int order);

// Imprime a matriz
void print(__int64** matrix, unsigned int order);


#endif // !MATRIX_H