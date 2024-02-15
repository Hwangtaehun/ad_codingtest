#include <cstdio>

int many, enough, data[100][2], minimum = 0x7fffffff;
bool used[100];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &many, &enough);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < many; j++){
            scanf("%d", &data[j][i]);
        }
    }
    fclose(stdin);
}

void Find(int cnt, int volume, int price){
    if(cnt == many - 1){
        return;
    }

    if(enough <= volume){
        if(price < minimum){
            minimum =  price;
        }
    }

    for(int i = 0; i < many; i++){
        if(!used[i]){
            used[i] = true;
            Find(cnt + 1, volume + data[i][0], price + data[i][1]);
            used[i] = false;
        }
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
    Find(0, 0, 0);
    Out();
    return 0;
}
