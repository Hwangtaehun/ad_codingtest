#include <cstdio>

int big = -1000;
int data[100];
int num;

//«Æ¿Ã
int n;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", data+i);
    }
    fclose(stdin);
}

void Solve(){
    int s, e, k, sum, maxSum = -1000;

    for(s = 0; s < n; s++){
        for(e = s; e < n; e++){
            sum = 0;
            for(k = s; k <= e; k++){
                sum += data[k];
            }

            if(maxSum < sum){
                maxSum = sum;
            }

            printf("[%d] - [%d] «’ = %3d, %3d\n", s, e, sum, maxSum);
        }
    }
    printf("%d\n", maxSum);
}

void In(){
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

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", big);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Maximum();
    Out();
    */
    Input();
    Solve();
    return 0;
}
