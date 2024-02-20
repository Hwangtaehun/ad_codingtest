#include <cstdio>

int many, weight, data[100][2], maximum = 0;
bool used[100];

//solve
int DT[102][1002], W, n, i, j, w[102], v[102];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &W);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    fclose(stdin);
}

int max(int a, int b){
    return a > b ? a : b;
}

int solve1(int i, int r){
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 1000; j++){
            DT[i][j] = -1;
        }
    }


    if(DT[i][r] != -1){
        return DT[i][r];
    }

    if(i == n + 1){
        return DT[i][r] = 0;
    }
    else if(r < w[i]){
        return DT[i][r] = solve1(i + 1, r);
    }
    else{
        return DT[i][r] = max(solve1(i + 1, r), solve1(i + 1, r - w[i]) + v[i]);
    }
}

void solve2(){
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= W; j++){
            if(j < w[i]){
                DT[i][j] = DT[i + 1][j];
            }else{
                DT[i][j] = max(DT[i + 1][j], DT[i + 1][j - w[i]] + v[i]);
            }
        }
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &many, &weight);
    for(int i = 0; i < many; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", maximum);
    fclose(stdout);
}

void Bring(int total, int price){
    if(total > weight){
        return;
    }

    if(maximum < price){
        maximum = price;
    }

    for(int i = 0; i < many; i++){
        if(!used[i]){
            used[i] = true;
            Bring(total + data[i][0], price + data[i][1]);
            used[i] = false;
        }
    }
}

int main()
{
    /*In();
    Bring(0, 0);
    Out();*/
    Input();
    //printf("%d", solve1(1,W));
    solve2();
    printf("%d", DT[1][W]);
    return 0;
}
