#include "../include/euler.h"

Matrix euler_explicite(double delta_T, double delta_X, double t_f, Matrix T, Matrix K){
    std::ofstream file;
    file.open("../results/out_expl" + std::to_string(delta_T) + std::to_string(delta_X) + ".txt");

    int N = (int)(std::ceil(t_f/delta_T));
    for(int i=0;i<N;i++){
        T = T + delta_T*K*T;
        file << T.T().print();
    }
    file.close();
    return T;

}

Matrix euler_implicite(double delta_T, double delta_X, double t_f, Matrix T, Matrix K){
    int N = (int)(std::ceil(t_f/delta_T));
    std::ofstream file;
    file.open("../results/out_impl" + std::to_string(delta_T) + std::to_string(delta_X) + ".txt");

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
