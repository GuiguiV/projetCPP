#include "../include/euler.h"
#include <cmath>
#include <fstream>

Matrix euler_explicite(float delta_T, float t_f, Matrix T, Matrix K){
    std::ofstream file;
    file.open("./out_expl.txt");

    int N = (int)(std::ceil(t_f/delta_T));
    for(int i=0;i<N;i++){
        T = T + delta_T*K*T;
        file << T.T().print();
    }
    file.close();
    return T;

}

Matrix euler_implicite(float delta_T, float t_f, Matrix T, Matrix K){
    int N = (int)(std::ceil(t_f/delta_T));
    std::ofstream file;
    file.open("./out_impl.txt");

    Matrix Id = Matrix(K);
    Id.fill(0.0);
    Id.fill_diag(1.0,0);
    Matrix A = Id - delta_T*K;

    for(int i=0;i<N;i++){
        T = conjugate_gradient(T,A,T);
        file << T.T().print();
    }

    return T;

}
