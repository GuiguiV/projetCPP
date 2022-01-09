#include "matrix.h"
#include "gradient.h"
#include <cmath>

Matrix euler_explicite(float delta_T, float t_f, Matrix T, Matrix K){
    int N = (int)(std::ceil(t_f/delta_T));
    for(int i=0;i<N;i++){
        T = T - delta_T*K*T;
    }
    return T;

}

Matrix euler_implicite(float delta_T, float t_f, Matrix T, Matrix K){
    int N = (int)(std::ceil(t_f/delta_T));
    Matrix Id = Matrix(K);
    Id.fill(0.0);
    Id.fill_diag(1.0,0);
    Matrix A = Id + delta_T*K;
    for(int i=0;i<N;i++){
        conjugate_gradient(T,A,T)


    }
    return T;

}
