#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

#include<vector>

class matrix{
protected:
	std::vector<std::vector<double>>*ma;
	int col, row;
public:
	int size()const{ return col; }
	matrix(int a = 0, int b = 0) :col(a), row(b){ ma = new std::vector<std::vector<double>>(col, std::vector<double>(row, 0)); }
	~matrix(){ delete ma; }
	std::vector<double>&operator[](int i){ return (*ma)[i]; }
	std::vector<double>operator[](int i)const{ return (*ma)[i]; }
	double operator()(int i, int j)const{ return (*ma)[i][j]; }
	double &operator()(int i, int j){ return (*ma)[i][j]; }
	matrix operator*(matrix&x)const;
	matrix &operator*=(matrix&x);
	matrix operator+(matrix&x)const;
	matrix &operator+=(matrix&x);
	matrix operator-(matrix&x)const;
	matrix &operator-=(matrix&x);
	matrix inver();
	matrix ZTZ();
	matrix *copy();
};
matrix &operator*(const std::vector<double>&x, const std::vector<double>&y);
std::ostream&operator<<(std::ostream&os, const matrix &x);

#endif
