#include <cstdio>

int many, enough, data[100][2], minimum = 0x7fffffff;
bool used[100];

//solve
#define MAXV 999999
int M, n, i, m[101], c[101], DT[101][10001];

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; i++){
        scanf("%d", &m[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    fclose(stdin);
}

int f(int i, int r){
    if(i == 0){
        if(r <= 0){
            return 0;
        }
        else{
            return MAXV;
        }
    }else if(r < 0){
        return f(i - 1, r);
    }else{
        return min(f(i - 1, r), f(i - 1, r - m[i]) + c[i]);
    }
}

int solve(){
    int i, j, res = 0x7fffffff;

    for(i = 1; i <= n; i++){
        for(j = 0; j <= 100 * n; j++){
            if(j >= c[i]){
                DT[i][j] = max(DT[i-1][j], DT[i-1][j-c[i]] + m[i]);
            }else{
                DT[i][j] = DT[i-1][j];
            }
        }
    }

    for(j = 0; j <= 100 * n; j++){
        if(DT[n][j] >= M && res > j){
            res = j;
        }
    }

    return res;
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &many, &enough);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < many; j++){
            scanf("%d", &data[j][i]);
        }
    }
    fclose(stdin);
}

void Find(int cnt, int volume, int price){
    if(cnt == many - 1){
        return;
    }

    if(enough <= volume){
        if(price < minimum){
            minimum =  price;
        }
    }

    for(int i = 0; i < many; i++){
        if(!used[i]){
            used[i] = true;
            Find(cnt + 1, volume + data[i][0], price + data[i][1]);
            used[i] = false;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", minimum);
    fclose(stdout);
}

int main()
{
    Input();
    printf("%d\n", f(n,M));
    printf("%d\n", solve());
    //In();
    //Find(0, 0, 0);
    //Out();
    return 0;
}
