#include <cstdio>

int n, r, result;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &r);
    fclose(stdin);
}

int Factorial(int num){
    if(num == 1){
        return 1;
    }

    return num * Factorial(num - 1);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

int main()
{
    //In();
    scanf("%d %d", &n, &r);
    result = Factorial(n) / (Factorial(n-r) * Factorial(r));
    printf("%d", result);
    //Out();
    return 0;
}
