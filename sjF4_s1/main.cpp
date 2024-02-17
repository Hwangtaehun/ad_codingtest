#include <cstdio>
#define MAX(a,b) ((a) >= (b) ? (a) : (b))

int n, m, mine[220][220], table[220][220];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d ", &mine[i][j]);
        }
    }
    fclose(stdin);
}

void Solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a = table[i-1][j];
            int b = table[i][j-1];
            table[i][j] = mine[i][j] + MAX(a,b);
        }
    }
    printf("%d", table[n][m]);
}

int main()
{
    Input();
    Solve();
    return 0;
}
