#include <stdio.h>

#if defined(__TINYC__)
#define CMP "TCC"   //остаётся, если {условие1} верно
#elif defined(_MSC_VER)
#define CMP "MSVC"  //остаётся, если {условие1} неверно и {условие2} верно
#elif defined(__GNUC__)
#define CMP "GCC"   //остаётся, если {условие{1,2}} неверны и {условие3} верно
#else
#define CMP "clang"        //остаётся, если все условия неверны
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
