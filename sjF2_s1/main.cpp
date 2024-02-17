#include <cstdio>

int N, K, ans;

void Solve(int n, int k){
    if(k == K){
        ans++;
        return;
    }

    if(n == N){
        return;
    }

    Solve(n + 1, k + 1);
    Solve(n + 1, k);
}

int main()
{
    scanf("%d %d", &N, &K);
    Solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
