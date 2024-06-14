//====== ������� 1 ======
// (��� ������� ����� n)
//����������� ������ �� X � Y
void dcopy (int n , const double *X , double *Y ){
    *Y = *X;
}
//�������� ������� ���������� �������� X � Y
void dswap (int n , double *X , double *Y ){
    double *Z;
    dcopy(n, X, Z);
    dcopy(n, Y, X);
    dcopy(n, Z, Y);
}
//��������� ������ X �� ����������� alpha
void dscal (int n , double alpha , double *X ){
    *X = (double)n * alpha;
}
//��������� � ������� Y ������ X, ���������� �� ����������� alpha
void daxpy (int n , double alpha , const double *X , double *Y );
//��������� ��������� ������������ �������� X � Y
double ddot (int n , const double *X , const double * Y );
