//====== ������� 3 ======
//��������� ������� (alpha*A*B + beta*C) � �������� � � C
//����� A �- ������� ������� m �� k, B �- ������� ������� k �� n,
// C �- ������� ������� m �� n
void dgemm (
int m , int n , int k ,
double alpha , const double *A , const double *B ,
double beta , double * C
);
