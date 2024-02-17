#include <cstdio>
#define MIN(a,b) ((a) > (b) ? (b) : (a))

int a, b, able[3], d[1001];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &a, &b);
    for(int i = 0; i < 3; i++){
        scanf("%d", &able[i]);
    }
    fclose(stdin);
}

void Solve(){
    if(a == b){
        printf("0");
    }
    else{
        for(int i = a; i <= b; i++){
            d[i] = 123456789;
        }

        d[a] = 0;

        for(int i = a + 1; i <= b; i++){
            int temp = 123456789;

            for(int k = 0; k < 3; k++){
                if(i - able[k] >= 1){
                    temp = MIN(temp, d[i-able[k]] + 1);
                }
            }
            d[i] = temp;
        }

        if(d[b] != 123456789){
            printf("%d", d[b]);
        }else{
            printf("-1");
        }
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}
