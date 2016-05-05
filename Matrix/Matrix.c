#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Matrix.h"

#define DEBUG

// Cria uma nova matriz de números aleatórios
int64_t** newMatrix(unsigned int order) 
{
	int64_t**	matrix;
	int			balance;

	if (order < 2)
		return NULL;
	// Aloca a memória
	matrix = (int64_t**)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++)
		matrix[i] = (int64_t*)malloc(order*sizeof(int64_t));
	// Preenche inteiros aleatórios para os elementos da Matriz
	srand(time(NULL));
	_sleep(1000);
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			balance = -300 + rand() % 500;
			matrix[i][j] = (balance + rand() % 200);
		}
	}
	return matrix;
}

// Soma duas matrizes
int64_t** sum(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order)
{
	int64_t**	matrix;
	clock_t		startTime;
	clock_t		endTime;
	double		executionTime;

	if (order < 2)
		return NULL;
	// Aloca memória
	matrix = (int64_t**)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++)
		matrix[i] = (int64_t*)malloc(order*sizeof(int64_t));
	// Soma
	startTime = clock();
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i][j] = firstMatrix[i][j] + sndMatrix[i][j];
		}
	}
	endTime = clock();
	executionTime = (double)((endTime - startTime) * 1000 / CLOCKS_PER_SEC);
#ifdef DEBUG
	printf("\nTime: %.2f\n", executionTime);
#endif
	return matrix;
}

// Multiplica duas matrizes
int64_t** product(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order)
{
	int64_t**	matrix;
	clock_t		startTime;
	clock_t		endTime;
	double		executionTime;

	if (order < 2)
		return NULL;
	// Aloca memória
	matrix = (int64_t**)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++)
		matrix[i] = (int64_t*)malloc(order*sizeof(int64_t));
	// Produto
	int64_t product = 0;
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
	executionTime = (double)((endTime - startTime) * 1000 / CLOCKS_PER_SEC);
#ifdef DEBUG
	printf("\nTime: %.2f\n", executionTime);
#endif 
	return matrix;
}

// Divide as duas matrizes em blocos, e efetua a multiplicação de cada uma
int64_t** getBlock(int64_t** matrix, unsigned int order, unsigned int blockNumber)
{
	unsigned int	elements = order*order;
	unsigned int	blockOrder = order / 2;
	int64_t**		block = NULL;

	if ((elements % 4 != 0) || (matrix == NULL)){
		printf("Size error \n");
		return NULL;
	}
	
	block = (int64_t**)malloc(blockOrder * sizeof(int64_t));
	for (int i = 0; i < order; i++)
		block[i] = (int64_t*)malloc(blockOrder * sizeof(int64_t));

	switch (blockNumber)
	{
	default:
		// Retorna bloco 1, por padrão
		for (int i = 0; i < blockOrder; i++) {
			for (int j = 0; j < blockOrder; j++) {
				block[i][j] = matrix[i][j];
			}
		}
		break;
	case 1:
		// Bloco 1
		for (int i = 0; i < blockOrder; i++) {
			for (int j = 0; j < blockOrder; j++) {
				block[i][j] = matrix[i][j];
			}
		}
		break;
	case 2:
		// Bloco 2
		for (int i = 0; i < blockOrder; i++) {
			for (int j = 0; j < blockOrder; j++) {
				block[i][j] = matrix[i + blockOrder][j];
			}
		}
		break;
	case 3:
		// Bloco 3
		for (int i = 0; i < blockOrder; i++) {
			for (int j = 0; j < blockOrder; j++) {
				block[i][j] = matrix[i][j + blockOrder];
			}
		}
		break;
	case 4:
		// Bloco 4
		for (int i = 0; i < blockOrder; i++) {
			for (int j = 0; j < blockOrder; j++) {
				block[i][j] = matrix[i + blockOrder][j + blockOrder];
			}
		}
		break;
	}
	return block;
}

// Forma uma matriz a partir dos blocos
int64_t ** mergeBlocks(int64_t ** firstBlock, int64_t ** sndBlock, int64_t ** thrdBlock, int64_t ** fourthBlock, unsigned int order)
{
	unsigned int	matrixOrder = 2*order;
	int64_t**		matrix;

	// Aloca memória
	matrix = (int64_t**)malloc(matrixOrder * sizeof(int64_t));
	for (int i = 0; i < matrixOrder; i++)
		matrix[i] = (int64_t*)malloc(matrixOrder * sizeof(int64_t));

	// Junta os elementos dos blocos numa única matriz
	// Bloco 1
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i][j] = firstBlock[i][j];
		}
	}
	// Bloco 2
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i + order][j] = sndBlock[i][j];
		}
	}
	// Bloco 3
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i][j + order] = thrdBlock[i][j];
		}
	}
	// Bloco 4
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i + order][j + order] = fourthBlock[i][j];
		}
	}
#ifdef DEBUG
	//print(matrix, matrixOrder);
#endif 
	return matrix;
}

int64_t** blockProduct(int64_t** firstMatrix, int64_t** sndMatrix, unsigned int order)
{
	int64_t**		firstMatrixBlockA;
	int64_t**		firstMatrixBlockB;
	int64_t**		firstMatrixBlockC;
	int64_t**		firstMatrixBlockD;
	int64_t**		sndMatrixBlockA;
	int64_t**		sndMatrixBlockB;
	int64_t**		sndMatrixBlockC;
	int64_t**		sndMatrixBlockD;
	int64_t**		firstBlock;
	int64_t**		sndBlock;
	int64_t**		thrdBlock;
	int64_t**		fourthBlock;
	int64_t**		matrix;
	int64_t			productValue;
	clock_t			startTime;
	clock_t			endTime;
	double			executionTime;

	if (order < 2)
		return NULL;
	// Aloca memória
	matrix = (int64_t**)malloc(order * sizeof(int64_t));
	for (int i = 0; i < order; i++)
		matrix[i] = (int64_t*)malloc(order * sizeof(int64_t));
	// Produto		
	// Divide as matrizes em blocos
	firstMatrixBlockA = getBlock(firstMatrix, order, 1);
	firstMatrixBlockB = getBlock(firstMatrix, order, 2);
	firstMatrixBlockC = getBlock(firstMatrix, order, 3);
	firstMatrixBlockD = getBlock(firstMatrix, order, 4);
	sndMatrixBlockA = getBlock(sndMatrix, order, 1);
	sndMatrixBlockB = getBlock(sndMatrix, order, 2);
	sndMatrixBlockC = getBlock(sndMatrix, order, 3);
	sndMatrixBlockD = getBlock(sndMatrix, order, 4);

	startTime = clock();
	firstBlock	= product(firstMatrixBlockA, sndMatrixBlockA, order / 2);
	sndBlock = product(firstMatrixBlockB, sndMatrixBlockB, order / 2);
	thrdBlock = product(firstMatrixBlockC, sndMatrixBlockC, order / 2);
	fourthBlock = product(firstMatrixBlockD, sndMatrixBlockD, order / 2);
	matrix = mergeBlocks(firstBlock, sndBlock, thrdBlock, fourthBlock, order / 2);

	endTime = clock();

	executionTime = (double)((endTime - startTime) * 1000 / CLOCKS_PER_SEC);
#ifdef DEBUG
	printf("\nTime: %.2f\n", executionTime);
#endif
	return matrix;

}

// Retorna a tranposta de uma matriz
int64_t** transpose(int64_t** matrix, unsigned int order)
{
	int64_t**	tranpose;
	clock_t		startTime;
	clock_t		endTime;
	double		executionTime;

	if (order < 2)
		return NULL;
	// Aloca memória
	tranpose = (int64_t**)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++)
		tranpose[i] = (int64_t*)malloc(order*sizeof(int64_t));
	// Transpose
	startTime = clock();
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
				tranpose[i][j] = matrix[j][i];
		}
	}
	endTime = clock();
	executionTime = (double)((endTime - startTime) * 1000 / CLOCKS_PER_SEC);
	printf("\nTime: %.2f\n", executionTime);
	return tranpose;
}

// Retorna a linha da matriz
int64_t* getRow(int64_t** matrix, unsigned int row, unsigned int order)
{
	if (row > order || row < 1)
		return NULL;
	return matrix[row - 1];
}

// Retorna a coluna da matriz
int64_t* getColumn(int64_t** matrix, unsigned int column, unsigned int order)
{
	int64_t*	matrixColumn;

	if (column > order || column < 1)
		return NULL;
	matrixColumn = (int64_t*)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++) {
		matrixColumn[i] = matrix[i][column - 1];
	}
	return matrixColumn;
}

// Retorna a diagonal de uma matriz
int64_t* getDiagonal(int64_t** matrix, unsigned int order)
{
	int64_t*	diagonal;

	if (order < 2)
		return NULL;
	diagonal = (int64_t*)malloc(order*sizeof(int64_t));
	for (int i = 0; i < order; i++) {
		diagonal[i] = matrix[i][i];
	}
	return diagonal;
}

// Imprime a matriz
void print(int64_t** matrix, unsigned int order) 
{
	if (order < 2)
		return;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			printf("%ld\t", matrix[i][j]);
		}
		printf("\n");
	}
}
