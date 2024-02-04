#include <cstdio>

int num;

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

int main()
{

    scanf("%d", &num);
    printf("%d\n", Up(1));
    printf("%d\n", Down(num));
    return 0;
}
