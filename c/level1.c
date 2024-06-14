//====== уровень 1 ======
// (все векторы длины n)
//скопировать вектор из X в Y
void dcopy (int n , const double *X , double *Y ){
    *Y = *X;
}
//обмен€ть местами содержимое векторов X и Y
void dswap (int n , double *X , double *Y ){
    double *Z;
    dcopy(n, X, Z);
    dcopy(n, Y, X);
    dcopy(n, Z, Y);
}
//домножить вектор X на коэффициент alpha
void dscal (int n , double alpha , double *X ){
    *X = (double)n * alpha;
}
//прибавить к вектору Y вектор X, умноженный на коэффициент alpha
void daxpy (int n , double alpha , const double *X , double *Y );
//вычислить скал€рное произведение векторов X и Y
double ddot (int n , const double *X , const double * Y );
