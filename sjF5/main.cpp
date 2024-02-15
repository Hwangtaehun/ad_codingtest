#include <cstdio>

int many, weight, data[100][2], maximum = 0;
bool used[100];

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
    In();
    Bring(0, 0);
    Out();
    return 0;
}
