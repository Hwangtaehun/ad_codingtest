#include <cstdio>

int N, K, DT[31][31];

int Solve(int n, int k){
    if(k == K){
        return 1;
    }

    if(n == N){
        return 0;
    }

    if(!DT[n][k]){
        DT[n][k] = Solve(n + 1, k + 1) + Solve(n + 1, k);
    }

    return DT[n][k];
}

int main()
{
    scanf("%d %d", &N, &K);
    printf("%d\n", Solve(0,0));
    return 0;
}
