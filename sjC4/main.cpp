#include <cstdio>

int data[100];
int pond, net, maxium; //pond = N, net = W

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &pond);
    scanf("%d", &net);
    for(int i = 0; i < pond; i++){
        scanf("%d", data+i);
    }
}

void Solve1(){
    int tot, maxTot = 0;
    for(int i = 0; i <= pond - net; i++){
        tot = 0;
        for(int j = 0; j < net; j++){
            tot += data[i+j];
            printf("%d ", i+j);
        }
        printf("\n");
        if(tot > maxTot){
            maxTot = tot;
        }
    }
    printf("%d\n", maxTot);
}

void Solve2(){
    int tot, maxTot = 0;
    for(int i = 0; i <= pond - net; i++){
        tot = 0;
        for(int j = i; j < i + net; j++){
            tot += data[j];
            printf("%d ", j);
        }
        printf("\n");
        if(tot > maxTot){
            maxTot = tot;
        }
    }
    printf("%d\n", maxTot);
}

void Fish(){
    maxium = 0;
    for(int i = 0; i < pond; i++){
        if(i + net <= pond){
            int hak = 0;
            for(int j = i; j < i + net; j++){
                hak += data[j];
            }

            if(maxium < hak){
                maxium = hak;
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("\n%d\n", maxium);
}

int main()
{
    Input();
    Solve1();
    printf("\n");
    Solve2();
    //Fish();
    //Output();
    return 0;
}
