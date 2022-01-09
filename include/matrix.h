#ifndef _MATRICE
#define _MATRICE

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class Matrix{
    public:
    Matrix(std::vector<double> matrix,int n_l, int n_c);
    Matrix(int n_l, int n_c);
    Matrix(const Matrix& other); 
    Matrix operator+(Matrix other);
    Matrix operator-(Matrix other);
    Matrix operator*(Matrix other);
    Matrix operator*(double scalar);
    Matrix T();
    double operator()(int i, int j);
    bool operator>(Matrix other); //checks if every coef is superior (absolute comparison)
    void set(int i, int j, double value);
    void reshape(int new_l,int new_c);
    void fill(double x);
    void fill_diag(double x,int n); //fills nth diagonal
    std::string print();
    
    private:
    int n_lines;
    int n_cols;
    std::vector<double> matrix;
};

Matrix operator*(double scalar, Matrix mat); //for operator commutativity

#endif