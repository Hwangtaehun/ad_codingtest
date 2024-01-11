#include <cstdio>

int cost, kind, eff = 0;
int data[21];

void Input(){
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

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", eff);
    fclose(stdout);
}

int main()
{
    Input();
    Buget(0, 0);
    Output();
    return 0;
}
