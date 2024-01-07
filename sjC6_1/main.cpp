#include <cstdio>
#define N 19
#define A 4

int a[N+2][N+2];
int di[A] = {0, 1, 1, -1};
int dj[A] = {1, 1, 0,  1};

void Input(){
    int i, j;
    freopen("input.txt", "r", stdin);
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            scanf("%d", &a[i][j]);
        }
    }
    fclose(stdin);
}

int Search(int color, int i, int j, int d){
    int cnt = 0;
    while(color == a[i][j]){
        i += di[d];
        j += dj[d];
        cnt++;
    }
    return cnt;
}

void Solve(){
    int i, j;
    for(i = 1; i <= 19; i++){
        for(j = 1; j <= 19; j++){
            if(a[i][j] != 0){
                for(int d = 0; d < A; d++){
                    if(a[i - di[d]][j - dj[d]] != a[i][j] && Search(a[i][j], i, j, d) == 5){
                        printf("%d\n%d %d", a[i][j], i, j);
                        return;
                    }
                }
            }
        }
    }
    printf("0");
}

int main()
{
    Input();
    Solve();
    return 0;
}
