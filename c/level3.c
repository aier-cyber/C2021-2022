//====== уровень 3 ======
//вычислить матрицу (alpha*A*B + beta*C) и записать еЄ в C
//здесь A Ц- матрица размера m на k, B Ц- матрица размера k на n,
// C Ц- матрица размера m на n
void dgemm (
int m , int n , int k ,
double alpha , const double *A , const double *B ,
double beta , double * C
);
