#include "../include/matrix.h"
#include "../include/gradient.h"
#include "../include/euler.h"
#include <fstream>


void test1();
constexpr double c_init(double x);

int main(int argc, char** argv){
    double D = 1.;
    double tf = 0.5;
    double delta_t = 0.01;
    double delta_x = 0.1;

    double N = 1/delta_x;


    Matrix K(N,N);

    std::vector<double> x0(N);

    for(int i=0;i<N;i++){
        x0[i] = c_init(i*delta_x);
    }

    Matrix X0(x0,N,1);
    Matrix Id(N,N);
    Id.fill_diag(1.,0);
    //creation of K : fill diagonals and boundary conditions at 0 and N-1
    K.fill_diag(-2*D,0);
    K.fill_diag(D,-1);
    K.fill_diag(D,1);
    K.set(0,0,-D);
    K.set(N-1,N-1,-D);

    K = K*(1./(delta_x * delta_x));

    Matrix A = Id - delta_t*K;
    Matrix Xf = euler_explicite(delta_t,tf,X0,K);

    std::ofstream file;
    file.open("./out.txt");
    file << Xf.T().print();
    file.close();


    return 0;
}

constexpr double c_init(double x){

    return (.5 + sin(2*M_PI*x) + .5*cos(2*M_PI*x));
}

void test1(){
    auto m1 = std::vector<double>{ 1,2,0,
                                   1,8,3};
    auto m2 = std::vector<double>{1,
                                  2,
                                  3};

    Matrix M1 = Matrix(m1,2,3);
    Matrix M2 = Matrix(m2,3,1);
    Matrix M3 = M1*M2;
    M3.print();
    (M1*3-M1).print();


    std::vector<double> a{3, 2,
                            1, 5};
    Matrix A(a,2,2);
    Matrix x0(std::vector<double>{1,1},2,1);
    Matrix b(std::vector<double>{1,1},2,1);

    auto X = conjugate_gradient(x0,A,b);
    X.print();

}
