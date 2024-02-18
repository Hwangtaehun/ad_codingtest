#include <cstdio>
#include <cstdlib>

int n, m, a, b, x, y;
int p[501];
int DT[501][101];

int isIn(int a, int b, int k){
    return ((a <= k && k < b) || (b <= k && k < a)) ? 1:0;
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &x, &y);
    for(int i = 1; i <= m; i++){
        scanf("%d", &p[i]);
    }
    fclose(stdin);
}

void cost_min(){
    int i, j, k;

    for(i = 0; i <= m; i++){
        for(j = 0; j <= n; j++){
            DT[i][j] = 99999999;
        }
    }

    for(j = 1; j <= n; j++){
        DT[0][j] = abs(j-a)*y;
    }

    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            for(k = 1; k <= n; k++){
                if(j == k && (p[i] == k || p[i] + 1 == k)){
                    DT[i][j] = (DT[i - 1][k] + x < DT[i][j]) ? DT[i-1][k] + x : DT[i][j];
                }else if(isIn(j, k, p[i])){
                    DT[i][j] = DT[i-1][k] + (abs(j-k) - 1) * y < DT[i][j] ? DT[i - 1][k] + (abs(j - k) - 1) * y: DT[i][j];
                }else{
                    DT[i][j] = DT[i-1][k] + (abs(j-k)*y) < DT[i][j] ? DT[i-1][k] + (abs(j-k)*y) : DT[i][j];
                }
            }
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", DT[m][b]);
    fclose(stdout);
}

int main(){
    In();
    cost_min();
    Out();
    return 0;
}
