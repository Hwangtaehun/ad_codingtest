#include <cstdio>

int money, kind, cnt = 0;
int data[1000];

//solve
int n, m, coin[10], ans = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", coin + i);
    }
}

void Solve(int mon, int k, int cnt){
    if(k == n || mon > m){
        return;
    }

    if(mon == m){
        if(ans > cnt){
            ans = cnt;
        }
        return;
    }

    for(int i = 0; mon + coin[k] * i <= m; i++){
        Solve(mon+coin[k] * i, k + 1, cnt + i);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &money);
    scanf("%d", &kind);
    for(int i = 0; i < kind; i++){
        scanf("%d", &data[i]);
    }
    fclose(stdin);
}

void Change(){
    int tp_money = money;
    for(int i = kind - 1; i >= 0; i--){
        int tp_cnt = tp_money / data[i];
        cnt += tp_cnt;
        tp_money = tp_money - (data[i] * tp_cnt);
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    Input();
    Solve(0,0,0);
    printf("%d\n", ans);
    //In();
    //Change();
    //Out();
    return 0;
}
