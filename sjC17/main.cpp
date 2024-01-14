#include <cstdio>

int cost, kind, eff = 0;
int data[21];

//solve
int B, n, act[23], res;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &B, &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &act[i]);
    }
}

void Solve(int i, int sum){
    if(sum > B){
        return;
    }
    printf("%d, %d, %d\n", i, sum, res);
    if(i == n + 1){
        if(sum <= B && sum > res){
            res = sum;
        }
        return;
    }
    Solve(i + 1, sum + act[i]);
    Solve(i + 1, sum);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &cost);
    scanf("%d", &kind);
    for(int i = 0; i < kind; i++){
        scanf("%d", &data[i]);
    }
    fclose(stdin);
}

void Buget(int i, int sum){
    if(sum > cost){
        return;
    }
    //printf("i = %d, sum = %d\n", i, sum);

    if(i == kind){
        if(sum ==  cost || sum > eff){
            eff = sum;
        }
        return;
    }

    Buget(i+1, sum+data[i]);
    Buget(i+1, sum);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", eff);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Buget(0, 0);
    Out();
    */
    Input();
    Solve(1, 0);
    printf("%d", res);
    return 0;
}
