#include <cstdio>
#include <ctime>

int DT[100001];

int f(int n){
    if(n<=2){
        return 1;
    }

    if(!DT[n]){
        DT[n] = f(n-1) + f(n-2);
    }

    return DT[n];
}

int fib(int num){
    int n1, n2, n3, tot, cnt = 2;
    n1 = n2 = 1;
    tot = 2;
    n3 = 0;

    while(cnt != num){
        n3 = n1 + n2;
        tot = n3;
        n1 = n2;
        n2 = n3;
        cnt++;
    }

    return tot;
}

int fibonacci(int num){
    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }
    else{
        return fibonacci(num - 2) + fibonacci(num - 1);
    }
}

int main()
{
    int num, start;
    scanf("%d", &num);
    start = clock();
    printf("%d\n", fibonacci(num));
    printf("clock()\t = %d\n", clock()-start);
    start = clock();
    printf("%d\n", fib(num));
    printf("clock()\t = %d\n", clock()-start);
    start = clock();
    printf("%d\n", f(num));
    printf("clock()\t = %d\n", clock()-start);
    return 0;
}
