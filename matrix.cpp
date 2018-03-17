#include<iostream>
#include<vector>
#include"matrix.h"

using namespace std;

matrix &operator*(const vector<double>&x, const vector<double>&y){
	matrix res(y.size(), x.size());
	for (int i = 0; i < x.size(); i++){
		for (int j = 0; j < y.size(); j++){
			res[j][i] = x[i] * y[j];
		}
	}
	return res;
}

ostream&operator<<(ostream&os, const matrix &x){
	for (int i = 0; i < x[0].size(); i++){
		for (int j = 0; j < x.size(); j++){
			if (x[j][i] < pow(10, -13))os << 0 << " \t";
			else os << x[j][i] << " \t";
		}
		os << endl;
	}
	return os;
}
matrix matrix::operator*(matrix&x)const{
	matrix*res = new matrix(x.size(), row);
	for (int i = 0; i < x.size(); i++){
		for (int j = 0; j < row; j++){
			for (int k = 0; k < col; k++){
				(*res)[i][j] += (*this)[k][j] * x[i][k];
			}
		}
	}
	return *res;
}
matrix &matrix::operator*=(matrix&x){
	matrix res(x.size(), row);
	for (int i = 0; i < x.size(); i++){
		for (int j = 0; j < row; j++){
			for (int k = 0; k < col; k++){
				res[i][j] += (*this)[k][j] * x[i][k];
			}
		}
	}
	delete ma;
	ma = new vector<vector<double>>(col, vector<double>(row, 0));
	for (int i = 0; i < ma->size(); i++){
		for (int j = 0; j < (*ma)[0].size(); j++){
			(*ma)[i][j] = res[i][j];
		}
	}
	return *this;
}
matrix matrix::operator+(matrix&x)const{
	matrix res(*this);
	res += x;
	return res;
}
matrix &matrix::operator+=(matrix&x){
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			(*this)[i][j] += x[i][j];
		}
	}
	return *this;
}
matrix matrix::operator-(matrix&x)const{
	matrix res(*this);
	res -= x;
	return res;
}
matrix &matrix::operator-=(matrix&x){
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			(*this)[i][j] -= x[i][j];
		}
	}
	return *this;
}
matrix matrix::inver(){
	if (col == row){
		matrix L(col,row);
		double m = 0;
		for (int j = 0; j < col; j++){
			for (int i = j; i < row; i++){
				m = (*this)[i][j];
				for (int k = 0; k < j; k++){
					m = m - (L[i][k] * L[j][k]);
				}
				if (i == j){
					L[i][j] = sqrt(m);
				}
				else{
					L[i][j] = m / L[j][j];
				}
			}
		}
		
		matrix re(L.size(), L[0].size());
		for (int j = 0; j < L[0].size(); j++){
			for (int i = j; i < L.size(); i++){
				if (i == j){
					re[i][j] = 1 / L[i][j];
				}
				else{
					for (int k = 0; k < i; k++){
						re[i][j] = re[i][j] - re[k][j] * L[i][k];
					}
					re[i][j] = re[i][j] / L[i][i];
				}
			}
		}
		return re.ZTZ();
	}
	else return *this;
}

matrix *matrix::copy(){
	matrix *res = new matrix(col, row);
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			(*res)[i][j] = (*this)[i][j];
		}
	}
	return res;
}
matrix matrix::ZTZ(){
	matrix *res=new matrix(row, row);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < row; j++){
			for (int k = 0; k < col; k++){
				(*res)[i][j] += (*this)[k][i] * (*this)[k][j];
			}
		}
	}
	cout << res<<endl;
	return *res;
}
