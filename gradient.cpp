#include "gradient.h"

Matrix conjugate_gradient(Matrix x0, Matrix A, Matrix b, Matrix epsilon){
    Matrix r = b - A*x0;
    Matrix x = x0;
    Matrix p = r;
    while(r > epsilon){
        double alphak = (r.T()*r)(0,0)/(p.T()*A*p)(0,0);
        x = x + alphak*p;
        Matrix old_r = r;
        r = r - alphak*A*p;
        double betak = (r.T()*r)(0,0)/(old_r.T()*old_r)(0,0);
        p = r + betak*p;
    }
    return x;
}