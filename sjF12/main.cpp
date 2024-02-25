#include <cstdio>

int price, cnt, data[10][2], memory[10], minimum;

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
    In();
    Rest();
    Out();
    return 0;
}
