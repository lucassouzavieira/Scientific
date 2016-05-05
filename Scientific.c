// Scientific.cpp : Defines the entry point for the console application.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Matrix\Matrix.h"
#define ORDER 100

void normalProduct() 
{
	for (int i = ORDER; i <= 2000; i = i + ORDER) {
		int64_t** matrixA = newMatrix(i);
		int64_t** matrixB = newMatrix(i);

		printf("Produto de Matrizes de Ordem %d", i);
		product(matrixA, matrixB, i);
		printf("\n");

		free(matrixA);
		free(matrixB);
	}
}

void matrixBlockProduct() 
{
	for (int i = ORDER; i <= 2000; i = i + ORDER) {
		int64_t** matrixA = newMatrix(i);
		int64_t** matrixB = newMatrix(i);

		printf("Produto de Matrizes de Ordem %d", i);
		blockProduct(matrixA, matrixB, i);
		printf("\n");

		free(matrixA);
		free(matrixB);
	}
}

void parallelProduct()
{
#pragma omp for{
	for (int i = ORDER; i <= 2000; i = i + ORDER) {
		int64_t** matrixA = newMatrix(i);
		int64_t** matrixB = newMatrix(i);

		printf("Produto de Matrizes de Ordem %d", i);
		blockProduct(matrixA, matrixB, i);
		printf("\n");

		free(matrixA);
		free(matrixB);
	}
}

int main(int argc, char *argv[]) 
{
	parallelProduct();
	system("pause");
	return 0;
}

