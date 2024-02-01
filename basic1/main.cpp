#include <cstdio>
#include <ctime>

int f1(int n){
    int i, sum = 0;
    for(i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

int f2(int n){
    if(n == 1){
        return 1;
    }

    return f2(n-1) + n;
}

int f3(int n){
    if(n == 1){
        return 1;
    }

    return 2 * f3(n/2) + ((n+1)/2) * ((n+1)/2);
}

int Sum(int num){
    if(num == 1){
        return 1;
    }
    return num + Sum(num-1);
}

int main()
{
    //total =  Sum(10);
    //printf("total = %d\n", total);
    int n;
    scanf("%d", &n);
    printf("clock()\t =  %d\n", clock());

    printf("%d\n", f1(n));
    printf("clock()\t =  %d\n", clock());

    printf("%d\n", f3(n));
    printf("clock()\t =  %d\n", clock());

    printf("%d\n", f2(n));
    printf("clock()\t =  %d\n", clock());

    return 0;
}
