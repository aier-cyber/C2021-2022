#include <stdio.h>

#if defined(__clang__)
#define CMP "clang"   //�������, ���� {�������1} �����
#elif defined(_MSC_VER)
#define CMP "MSVC"  //�������, ���� {�������1} ������� � {�������2} �����
#elif defined(__GNUC__)
#define CMP "GCC"   //�������, ���� {�������{1,2}} ������� � {�������3} �����
#else
#define CMP "TCC"        //�������, ���� ��� ������� �������
#endif

#if defined(__32BIT__)
#define VER "32"
#else
#define VER "64"
#endif // defined

#if defined(assert)
#define ASTS "enabled"
#else
#define ASTS "disabled"
#endif

int main(){
    printf("Compiler: "CMP"\nBitness: "VER"\nAsserts: "ASTS);
    return 0;
}
