//====== уровень 2 ======
//вычислить вектор (alpha*A*X + beta*Y) длины m, и записать его в Y
//здесь A Ц- матрица размера m на n, X Ц- вектор длины n, а Y Ц- вектор длины m
void dgemv (
int m , int n ,
double alpha , const double *A , const double *X ,
double beta , double * Y
);
//вычислить матрицу (alpha*X*Yt + A) и записать еЄ в A
//здесь Yt Ц- это транспонированный вектор Y, то есть записанный как вектор-строка
// A Ц- матрица размера m на n, X Ц- вектор длины m, а Y Ц- вектор длины n
void dger (
int m , int n ,
double alpha , const double *X , const double *Y ,
double *A
);
