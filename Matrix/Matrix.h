#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <iostream>

using namespace std;

class Matrix 
{
public:
	// Construtores
	Matrix();
	Matrix(unsigned int order);
	Matrix(unsigned int lines, unsigned int columns);

	// Destruidor
	~Matrix();

	// Métodos Públicos
	void Sum(Matrix sndMatrix);
	void Product(Matrix sndMatrix);
	__int64* getLine(unsigned int line);
	__int64* getColumn(unsigned int column);
	Matrix getBlock(unsigned int startLine, unsigned int endLine, unsigned int startColumn, unsigned int endColumn);

private:
	unsigned int lines;
	unsigned int columns;
	__int64** matrix;
};

#endif // !MATRIX_H
