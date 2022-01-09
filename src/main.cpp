#include "../include/matrix.h"
#include "../include/gradient.h"

void test1();

int main(){
    Matrix K();
    test1();
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
    double epsilon = 0.1;
    Matrix eps(2,1);
    eps.fill(epsilon);

    auto X = conjugate_gradient(x0,A,b,eps);
    X.print();

}
