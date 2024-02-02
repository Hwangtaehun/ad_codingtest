#include <cstdio>

int n, r, result;

void Solve1(int n, int k){
    int i, p = 1, q = 1, r = 1;

    for(i = 1; i <= n; i++){
        p = p * i;
    }

    for(i = 1; i <= k; i++){
        q = q * i;
    }

    for(i = 1; i <= n - k; i++){
        r = r * i;
    }
    printf("%dC%d = %d\n", n, k, p/(q*r));

    p = 1;
    for(i = n - k + 1; i <= n; i++){
        p = p * i;
    }
    printf("%dC%d = %d\n", n, k, p/q);

    p = 1;
    for(i = 1; i <= k; i++){
        p = p * (n - i + 1) / i;
    }
    printf("%dC%d = %d\n", n, k, p);
}

int Solve2(int n, int k){
    if(k == n)
        return 1;
    else if(k == 1)
        return n;
    else
        return Solve2(n-1, k-1) + Solve2(n-1, k);
}

int Solve3(int n, int k){
    if(k == n)
        return 1;
    else if(k == 1)
        return n;
    else
        return Solve3(n, k - 1) * (n - k + 1) / k;
}

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
    int n, k;
    scanf("%d %d", &n, &k);
    Solve1(n, k);
    printf("%d\n", Solve2(n, k));
    printf("%d\n", Solve3(n, k));
    /*
    In();
    result = Factorial(n) / (Factorial(n - r) * Factorial(r));
    Out();
    */
    return 0;
}
