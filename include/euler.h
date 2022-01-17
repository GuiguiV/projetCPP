#ifndef _EULER
#define _EULER
#include "matrix.h"
#include "gradient.h"

Matrix euler_explicite(float delta_T, float t_f, Matrix T, Matrix K);
Matrix euler_implicite(float delta_T, float t_f, Matrix T, Matrix K);

#endif