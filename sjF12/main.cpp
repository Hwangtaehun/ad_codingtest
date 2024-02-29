#include <cstdio>

int price, cnt, data[10][2], memory[10], minimum;

//solve
int n, m, coin[10], DT[10001];

int Min(int a, int b){
    return a > b ? b : a;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d\n%d", &m, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", coin + i);
    }
    fclose(stdin);
}

void Print(){
    printf("m = %d, n = %d\n", m, n);
    for(int i = 0; i < n; i++){
        printf("%d ", coin[i]);
    }
    printf("\n");
}

int f1(int c){
    if(c == m){
        return DT[c] = 0;
    }

    if(DT[c] == 0){
        DT[c] = 987654321;

        for(int i = 0; i < n; i++){
            if(c + coin[i] <= m){
                DT[c] = Min(DT[c], f1(c + coin[i]) + 1);
            }
        }
    }

    return DT[c];
}

void f2(){
    for(int i = 0; i < cnt; i++){
        DT[coin[i]] = 1;
    }

    for(int i = coin[0]; i <= m; i++){
        if(DT[i] == 0){
            DT[i] = 987654321;

            for(int j = 0; j < n; j++){
                if(i - coin[j] > 0){
                    DT[i] = Min(DT[i], DT[i - coin[j]] + 1);
                }
            }
        }
    }
}

int f3(int c){
    for(int i = 0; i < n; i++){
        if(coin[i] == c){
            return 1;
        }
    }

    if(DT[c] == 0){
        DT[c] = 987654321;

        for(int i = 0; i < n; i++){
            if(c - coin[i] > 0){
                DT[c] = Min(DT[c], f3(c - coin[i]) + 1);
            }
        }

        return DT[c];
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d\n%d", &price, &cnt);
    for(int i = 0; i < cnt; i++){
        scanf("%d", &data[i][0]);
    }
    fclose(stdin);

    for(int i = 0; i < cnt; i++){
        data[i][1] = data[i][0] / data[0][0];
    }
}

void Rest(){
    int many = price / data[0][0];
    memory[0] = many;

    for(int i = cnt - 1; i >= 0; i--){
        if(many > data[i][1]){
            memory[i] = many / data[i][1];
            many = many % data[i][1];
            printf("many = %d\n", many);
        }
    }


    for(int i = 0; i < cnt; i++){
        minimum += memory[i];
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
    Print();
    printf("%d\n", f1(0));
    f2();
    printf("%d\n", DT[m]);
    printf("%d\n", f3(0));
    return 0;
}
