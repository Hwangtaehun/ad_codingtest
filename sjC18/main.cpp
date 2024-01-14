#include <cstdio>

int kind, weight, mxpr = 0;
int data[100][2];

//solve
int W, n, i, j, w[102], v[102];

int Max(int a, int b){
    return a > b ? a : b;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &W);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    fclose(stdin);
}

int f(int i, int r){
    printf("%d, %d, %d\n", i, r, w[i]);

    if(i == n + 1){
        return 0;
    }else if(r < w[i]){
        return f(i + 1, r);
    }else{
        return Max(f(i + 1, r), f(i + 1, r - w[i]) + v[i]);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &kind, &weight);
    for(int i = 0; i < kind; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Cost(int i, int sum, int price){
    if(sum > weight){
        return;
    }
    //printf("i = %d, sum = %d, price = %d\n", i, sum, price);
    if(i == kind){
        if(mxpr < price){
            mxpr = price;
        }
        return;
    }

    Cost(i+1, sum+data[i][0], price+data[i][1]);
    Cost(i+1, sum, price);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", mxpr);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Cost(-1, 0, 0);
    Out();
    */
    Input();
    printf("%d", f(1,W));
    return 0;
}
