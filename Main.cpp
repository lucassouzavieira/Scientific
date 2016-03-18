#include <iostream>
#include "Matrix\SquareMatrix.h"
#define ORDER 1000

int main(void)
{
	__int64** matA;
	__int64** matB;
	__int64** soma;
	__int64** produto; 
	__int64** transposta;
	__int64** matC = newMatrix(ORDER);
	system("COLOR 3");
	matA = newMatrix(ORDER);
	matB = newMatrix(ORDER);
	// Soma, Multiplicacao, Transposta
	std::cout << "Matriz A" << std::endl;
	print(matA, ORDER);
	std::cout << "Matriz B" << std::endl;
	print(matB, ORDER);
	soma = sum(matA, matB, ORDER);
	std::cout << "Soma A + B" << std::endl;
	print(soma, ORDER);
	std::cout << "Produto A * B" << std::endl;
	produto = product(matA, matB, ORDER);
	print(produto, ORDER);
	std::cout << "Transposta de A" << std::endl;
	transposta = transpose(matA, ORDER);
	print(transposta, ORDER);
	// Questao 5
	std::cout << "Matriz C = Diagonal de A + Restante de B" << std::endl;
	__int64* diagonalA = getDiagonal(matA, ORDER);
	for (int i = 0; i < ORDER; i++) {
		for (int j = 0; j < ORDER; j++) {
			if (i != j)
				matC[i][j] = matB[i][j];
		}
		matC[i][i] = diagonalA[i];
	}
	print(matC, ORDER);
	// Questao 6
	std::cout << "Somatorio = 3 coluna de A + 21 coluna de B" << std::endl;
	__int64* columnA = getColumn(matA, 1, ORDER);
	__int64* columnB = getColumn(matB, 2, ORDER);
	__int64 sigma = 0;
	for (int i = 0; i < ORDER; i++) {
		sigma = sigma + columnA[i] + columnB[i];
	}
	std::cout << "Soma: " << sigma << std::endl;
	system("pause");
	return 0;
}