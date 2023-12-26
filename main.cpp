#include <iostream>
#include <stdio.h>

using namespace std;

void FileTest1();
void FileTest2();
void FileTest3();
void FileTest4();

int n;

int main()
{
    FileTest1();
    FileTest2();
    return 0;
}

void FileTest1(){
    printf("정수 입력 : ");
    scanf("%d", &n);
    printf("표준 출력 : %d\n", n);
}

void FileTest2(){
    FILE *inf = fopen("in.txt","r");
    FILE *outf = fopen("out2.txt","w");
    fscanf(inf,"%d", &n);
    fprintf(outf,"fopen으로 출력 : %d\n", n);
}
