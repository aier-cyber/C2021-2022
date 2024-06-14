#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{         //main может принимать эти параметры
    char* all;
    char* empt;
    empt = ' ';
    for (int i = 0; i < argc; i++) {        //argc --- количество параметров + 1
      strcat(all, argv[i]);
      strcat(all, empt);   //argv[0] --- полный путь к испольняемому файлу
    }                                       //argv[>0] --- параметры командной строки в порядке задания
    return 7;                               //возвращаемое значение main = "код возврата"
}
