#include <stdio.h>

#if defined(__clang__)
#define CMP "clang"   //остаётся, если {условие1} верно
#elif defined(_MSC_VER)
#define CMP "MSVC"  //остаётся, если {условие1} неверно и {условие2} верно
#elif defined(__GNUC__)
#define CMP "GCC"   //остаётся, если {условие{1,2}} неверны и {условие3} верно
#else
#define CMP "TCC"        //остаётся, если все условия неверны
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
