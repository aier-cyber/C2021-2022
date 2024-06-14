//====== ������� 2 ======
//��������� ������ (alpha*A*X + beta*Y) ����� m, � �������� ��� � Y
//����� A �- ������� ������� m �� n, X �- ������ ����� n, � Y �- ������ ����� m
void dgemv (
int m , int n ,
double alpha , const double *A , const double *X ,
double beta , double * Y
);
//��������� ������� (alpha*X*Yt + A) � �������� � � A
//����� Yt �- ��� ����������������� ������ Y, �� ���� ���������� ��� ������-������
// A �- ������� ������� m �� n, X �- ������ ����� m, � Y �- ������ ����� n
void dger (
int m , int n ,
double alpha , const double *X , const double *Y ,
double *A
);
