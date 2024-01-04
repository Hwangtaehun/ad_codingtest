#include <cstdio>

int data[100];
int pond, net, maxium;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &pond);
    scanf("%d", &net);
    for(int i = 0; i < pond; i++){
        scanf("%d", &data[i]);
    }
}

void Solve(){
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
    Solve();
    Output();
    return 0;
}
