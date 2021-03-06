#include "../include/matrix.h"
#include "../include/gradient.h"
#include "../include/euler.h"
#include <chrono>

void test1();
constexpr double c_init(double x);
void test_time();

int main(int argc, char** argv){
    double D = 1.;
    
    double tf = 0.5;
    double delta_t = 0.0001;
    double delta_x = 0.01;

    int N = (int)(1/delta_x + 1);


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
    K(0,0) =-D;
    K(0,1) = 0;
    K(N-1,N-1) =-D;
    K(N-1,N-2) = 0;

    K = K*(1./(delta_x * delta_x));

    test_time();

    Matrix Xf = euler_explicite(delta_t,delta_x,tf,X0,K);
    Xf = euler_implicite(delta_t,delta_x,tf,X0,K);
    
    return 0;
}

constexpr double c_init(double x){

    return (.5 + sin(2*M_PI*x) - .5*cos(2*M_PI*x));
}

void test_time(){

    double D = 1.;
    std::ofstream fichier;
    fichier.open("../results/timetests.txt");
    
    double tf = 0.5;
    double delta_x;
    double delta_t;
    for(float i = 1;i<3.6;i+= 0.5){

        delta_x = std::pow(10,(-i));

        int N = (int)(1/delta_x + 1);


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
        K(0,0) =-D;
        K(0,1) = 0;
        K(N-1,N-1) =-D;
        K(N-1,N-2) = 0;

        K = K*(1./(delta_x * delta_x));

        for (int j = 1;j<4;j++){
            delta_t = std::pow(10, -j);

            auto t0 = std::chrono::steady_clock::now();
            Matrix Xf = euler_explicite(delta_t,delta_x,tf,X0,K);
            auto t1 = std::chrono::steady_clock::now();
            Xf = euler_implicite(delta_t,delta_x,tf,X0,K);
            auto t2 = std::chrono::steady_clock::now();

            fichier << "dx,dt : " << delta_x <<" , "<< delta_t<<std::endl
            << "Dur??e euler explicite : " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()<<" ms"
            << std::endl << "Dur??e euler implicite : " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms"<< std::endl<<std::endl;

        }
    }
    fichier.close();
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
