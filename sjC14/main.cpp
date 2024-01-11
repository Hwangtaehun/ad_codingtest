#include <cstdio>

int big = -1000;
int data[100];
int num;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &data[i]);
    }
    fclose(stdin);
}

void Print(){
    printf("%d\n", num);
    for(int i = 0; i < num; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

void Maximum(){
    int cnt = 1;

    while(cnt <= num){
        for(int i = 0; i < num; i++){
            int hap = 0;
            for(int j = 0; j < cnt; j++){
                hap += data[i+j];
            }

            if(big < hap){
                big = hap;
            }
        }
        cnt++;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", big);
    fclose(stdout);
}

int main()
{
    Input();
    Maximum();
    Output();
    return 0;
}
