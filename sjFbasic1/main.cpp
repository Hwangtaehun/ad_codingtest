#include <cstdio>

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
    int num;
    scanf("%d", &num);
    printf("%d", fibonacci(num));
    return 0;
}
