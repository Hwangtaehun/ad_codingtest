#include <cstdio>

int price, kind, cnt, change[10];
//solve
int n, m, coin[10], debugCnt, ans = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", coin + i);
    }
}

int Greedy(int mon){
    int cnt = 0;

    for(int i = n - 1; i >= 0; i--){
        cnt += mon / coin[i];
        mon %= coin[i];
        printf("mon = %d, coin = %d, cnt =  %d\n", mon, coin[i], cnt);
    }

    if(mon == 0){
        ans = cnt;
    }

    return mon;
}

void Solve1(int mon, int cnt){
    if(cnt > ans)
        return;

    if(mon > m)
        return;

    debugCnt++;

    if(mon == m){
        if(cnt < ans){
            ans = cnt;
        }
        return;
    }

    for(int i = 0; i < n; i++){
        Solve1(mon+coin[i], cnt + 1);
    }
}

void Solve2(int mon, int k, int cnt){
    if(cnt > ans){
        return;
    }

    if(k == n || mon > m){
        return;
    }

    debugCnt++;

    if(mon == m){
        printf("mon = %d, k = %d, cnt = %d\n", mon, k, cnt);

        if(ans > cnt){
            ans = cnt;
        }

        return;
    }

    for(int i = 0; mon+coin[k]*i <= m; i++){
        Solve2(mon+coin[k] * i, k + 1, cnt + i);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &price);
    scanf("%d", &kind);
    for(int i = 0; i < kind; i++){
        scanf("%d", &change[i]);
    }
}

void Print(){
    printf("%d\n%d\n", price, kind);
    for(int i = 0; i < kind; i++){
        printf("%d ", change[i]);
    }
}

void Rest(){
    int focus, rest;

    for(int i = kind - 1; i > -1; i--){
        if(price > change[i]){
            focus = i;
            break;
        }
    }

    rest = price;

    while(rest != 0){
        cnt += rest / change[focus];
        rest = rest % change[focus];
        focus--;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    //In();
    //Rest();
    //Out();

    Input();
    if(Greedy(m) != 0){
        //Solve1(0,0);
        Solve2(0,0,0);
    }
    printf("%d\n", ans);
    printf("debugCnt = %d\n", debugCnt);
    return 0;
}
