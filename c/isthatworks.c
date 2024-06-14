#include <stdio.h>

#if defined(__TINYC__)
#define CMP "TCC"   //�������, ���� {�������1} �����
#elif defined(_MSC_VER)
#define CMP "MSVC"  //�������, ���� {�������1} ������� � {�������2} �����
#elif defined(__GNUC__)
#define CMP "GCC"   //�������, ���� {�������{1,2}} ������� � {�������3} �����
#else
#define CMP "clang"        //�������, ���� ��� ������� �������
#endif

#if defined(_M_X64)
#define VER "64"
#else
#define VER "32"
#endif // defined

#if defined(assert)
#define ASTS "enabled"
#else
#define ASTS "disabled"
#endif

int main(){
    freopen("output.txt", "w", stdout);
    printf("Compiler: "CMP"\nBitness: "VER"\nAsserts: "ASTS);
    return 0;
}
