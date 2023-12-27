#define _CRT_SECURE_NO_WARNINGS
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
    FileTest3();
    FileTest4();
    return 0;
}

void FileTest1() {
    printf("���� �Է� : ");
    scanf("%d", &n);
    printf("ǥ�� ��� : %d\n", n);
}

void FileTest2() {
    FILE* inf = fopen("in.txt", "r");
    FILE* outf = fopen("out2.txt", "w");
    fscanf(inf, "%d", &n);
    fprintf(outf, "fopen���� ��� : %d\n", n);
}

void FileTest3() {
    FILE* inf = stdin;
    FILE* outf = stdout;
    printf("���� �Է� 2: ");
    fscanf(inf, "%d", &n);
    fprintf(outf, "ǥ�� ��� 2 : %d\n", n);
}

void FileTest4() {
    freopen("in.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
    scanf("%d", &n);
    printf("freopen���� �� ���� �� ��� : %d\n", n);
    fclose(stdin);
    fclose(stdout);
    freopen("con", "r", stdin);
    freopen("con", "w", stdout);

    printf("ǥ����������� �ٽ� ���� �� �Է� : ");
    scanf("%d", &n);
    printf("ǥ����������� �ٽ� ���� �� ��� : %d\n", n);
}