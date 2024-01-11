#include <cstdio>

int money, kind, cnt = 0;
int data[1000];

void Input(){
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

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    Input();
    Change();
    Output();
    return 0;
}
