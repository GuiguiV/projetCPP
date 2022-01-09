#include "../include/matrix.h"

Matrix::Matrix(std::vector<double> matrix, int n_l, int n_c ):n_lines(n_l),n_cols(n_c){
    if(n_l <= 0 || n_c <=0 || n_c*n_l != matrix.size()){
        throw "Illegal lines or columns";
    }
    this->matrix = matrix;
        
}

Matrix::Matrix(const Matrix& other){
    this->n_lines = other.n_lines;
    this->n_cols = other.n_cols;
    this->matrix = other.matrix;
}

Matrix::Matrix(int n_l,int n_c):n_lines(n_l),n_cols(n_c){

    this->matrix = std::vector<double>(n_l*n_c);
}

Matrix Matrix::operator+(Matrix other){
    Matrix sum = Matrix(*this);
    if(other.n_lines == this->n_lines && other.n_cols == this->n_cols){
        for(int i=0;i<this->matrix.size();i++){
            sum.matrix[i] += other.matrix[i];
        }
    }
    return sum;
}

Matrix Matrix::operator-(Matrix other){
    return *this + (-1.)*other;
}

Matrix Matrix::operator*(Matrix other){
    if(this->n_cols != other.n_lines){
        throw "Illegal matrix multiplication";
    }
    Matrix product(this->n_lines,other.n_cols);
    
    for(int i = 0;i< product.n_lines;i++){
        for(int j=0;j<product.n_cols;j++){
            double pij = 0;
            for(int k=0;k<this->n_cols;k++){
                pij += this->operator()(i,k) * other(k,j);
            }
            product.set(i,j,pij);
        }
        
    }
    return product;
}

Matrix Matrix::operator*(double scalar){
    Matrix scaled = Matrix(*this);
    for(auto &element : scaled.matrix){
        element *= scalar;
    }
    return scaled;
}

//the operator is commutative
Matrix operator*(double scalar,Matrix mat){
    return mat.operator*(scalar);
}


double Matrix::operator()(int i, int j){
    return this->matrix[n_cols*i + j];
}

bool Matrix::operator>(Matrix other){
    bool out = true;
    for(int i=0;i<this->n_lines*this->n_cols;i++){
        out *= (std::abs(this->matrix[i]) > std::abs(other.matrix[i]));
    }
    return out;
}

Matrix Matrix::T(){
    Matrix m_T{*this};
    if(this->n_lines == 1){
        m_T.reshape(this->n_cols,1);
    }else if(this->n_cols == 1){
        m_T.reshape(1,this->n_lines);
    }else{
        for(int i = 0;i<n_lines;i++){
            for(int j=0;i<n_cols;j++){
                m_T.set(i,j, this->operator()(j,i));
            }
        }
        m_T.reshape(this->n_cols,this->n_lines);
    }
    return m_T;
}

void Matrix::set(int i,int j, double value){
    this->matrix[n_cols * i + j] = value;
}

void Matrix::reshape(int new_l,int new_c){
    if (new_l * new_c != this->n_lines * this->n_cols){
        throw "Wrong size matrix";
    }
    this->n_lines = new_l;
    this->n_cols = new_c;
}

void Matrix::print(){
    for(int i = 0;i<this->n_lines;i++){
        for(int j = 0;j<this->n_cols;j++){
            std::cout << this->operator()(i,j) << " ";
        }
        std::cout << std::endl;
    }
}
void Matrix::fill(double x){
    std::fill(this->matrix.begin(),this->matrix.end(),x);
}

//permet de remplir la
void Matrix::fill_diag(double x, int n){

    int start = n;
    if(n < 0){
        start = -1 * n * this->n_cols; 
    }
    int step = (n_cols+1) + n;
    for(int i = start; i < (this->n_lines * this->n_cols); i += step){
        this->matrix[i] = x;
    }
}

