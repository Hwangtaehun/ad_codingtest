#include <cstdio>
#include <ctime>

int num, D[100];

int Up(int n){
    if(n == num){
        return n;
    }

    return n + Up(n + 1);
}

int Down(int n){
    if(n == 1){
        return 1;
    }

    return n + Down(n - 1);
}

int f(int k){
    if(k == num + 1){
        return 0;
    }

    D[k] = k + f(k + 1);

    return D[k];
}


int main()
{
    int start;
    scanf("%d", &num);
    start = clock();
    printf("%d\n", Up(1));
    printf("clock()\t = %d\n", clock()-start);
    start = clock();
    printf("%d\n", Down(num));
    printf("clock()\t = %d\n", clock()-start);
    start = clock();
    printf("%d\n", f(1));
    printf("clock()\t = %d\n", clock()-start);

    return 0;
}
