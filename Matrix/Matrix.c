#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>
#include "Matrix.h"

// Cria uma nova matriz de números aleatórios
__int64** newMatrix(unsigned int order) 
{
	__int64** matrix;
	if (order < 2)
		return NULL;
	// Aloca a memória
	matrix = (__int64**)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++)
		matrix[i] = (__int64*)malloc(order*sizeof(__int64));
	// Preenche inteiros aleatórios para os elementos da Matriz
	srand(time(NULL));
	_sleep(1000);
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			int balance = -300 + rand() % 500;
			matrix[i][j] = (balance + rand() % 200);
		}
	}
	return matrix;
}

// Soma duas matrizes
__int64** sum(__int64** firstMatrix, __int64** sndMatrix, unsigned int order)
{
	if (order < 2)
		return NULL;
	__int64** matrix;
	// Aloca memória
	matrix = (__int64**)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++)
		matrix[i] = (__int64*)malloc(order*sizeof(__int64));
	// Soma
	clock_t startTime, endTime, executionTime;
	startTime = clock();
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i][j] = firstMatrix[i][j] + sndMatrix[i][j];
		}
	}
	endTime = clock();
	executionTime = ((endTime - startTime)*(1000 / CLOCKS_PER_SEC));
	std::cout << "Time: " << executionTime << std::endl;
	return matrix;
}

// Multiplica duas matrizes
__int64** product(__int64** firstMatrix, __int64** sndMatrix, unsigned int order)
{
	if (order < 2)
		return NULL;
	__int64** matrix;
	// Aloca memória
	matrix = (__int64**)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++)
		matrix[i] = (__int64*)malloc(order*sizeof(__int64));
	// Produto
	__int64 product = 0;
	clock_t startTime, endTime, executionTime;
	startTime = clock();
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			product = 0;
			for (int k = 0; k < order; k++) {
				product = product + firstMatrix[i][k] * sndMatrix[k][j];
			}
			matrix[i][j] = product;
		}
	}
	endTime = clock();
	executionTime = ((endTime - startTime)*(1000 / CLOCKS_PER_SEC));
	std::cout << "Time: " << executionTime << std::endl;
	return matrix;
}

// Retorna a tranposta de uma matriz
__int64** transpose(__int64** matrix, unsigned int order)
{
	if (order < 2)
		return NULL;
	__int64** tranpose;
	// Aloca memória
	tranpose = (__int64**)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++)
		tranpose[i] = (__int64*)malloc(order*sizeof(__int64));
	// Transpose
	clock_t startTime, endTime, executionTime;
	startTime = clock();
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
				tranpose[i][j] = matrix[j][i];
		}
	}
	endTime = clock();
	executionTime = ((endTime - startTime)*(1000 / CLOCKS_PER_SEC));
	std::cout << "Time: " << executionTime << std::endl;
	return tranpose;
}

// Retorna a linha da matriz
__int64* getRow(__int64** matrix, unsigned int row, unsigned int order)
{
	if (row < order || row < 0)
		return NULL;
	return matrix[row];
}

// Retorna a coluna da matriz
__int64* getColumn(__int64** matrix, unsigned int column, unsigned int order)
{
	if (column > order || column < 0)
		return NULL;
	__int64* matrixColumn = (__int64*)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++) {
		matrixColumn[i] = matrix[i][column];
	}
	return matrixColumn;
}

// Retorna a diagonal de uma matriz
__int64* getDiagonal(__int64** matrix, unsigned int order)
{
	if (order < 2)
		return NULL;
	__int64* diagonal = (__int64*)malloc(order*sizeof(__int64));
	for (int i = 0; i < order; i++) {
		diagonal[i] = matrix[i][i];
	}
	return diagonal;
}

// Imprime a matriz
void print(__int64** matrix, unsigned int order) 
{
	if (order < 2)
		return;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}