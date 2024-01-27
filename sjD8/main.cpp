#include <cstdio>

int price, kind, cnt, change[10];

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
    In();
    Rest();
    Out();
    return 0;
}
