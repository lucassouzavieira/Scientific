#include "Matrix.h"

/*
 Construtores
*/
Matrix::Matrix()
{
	lines = 1;
	columns = 1;
	matrix = (__int64**)malloc(1*sizeof(__int64));
	for (int i = 0; i < 1; i++)
		matrix[i] = (__int64*)malloc(1*sizeof(__int64));
}

Matrix::Matrix(unsigned int order)
{
	lines = order;
	columns = order;
	matrix = (__int64**)malloc(lines*sizeof(__int64));
	for (int i = 0; i < lines; i++)
		matrix[i] = (__int64*)malloc(columns*sizeof(__int64));
	matrix = { 0 };
}

Matrix::Matrix(unsigned int lines, unsigned int columns)
{
	this->lines = lines;
	this->columns = columns;
	matrix = (__int64**)malloc(lines*sizeof(__int64));
	for (int i = 0; i < lines; i++)
		matrix[i] = (__int64*)malloc(columns*sizeof(__int64));
	matrix = { 0 };
}

/*
 Destruidor
*/
Matrix::~Matrix()
{
	free(this->matrix);
	delete this;
}






