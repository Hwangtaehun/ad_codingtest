#include <cstdio>
#include <cstdlib>
#include <cmath>
#define N 10

int data[100];
int mx = 11, mn = 0, cnt = 0;
double in;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%lf", &in);

    if(in < mx && in > mn){
        mx = pow(N, in);
        mn = pow(N, in-1);
    }else{
        printf("형식에 맞는 수를 입력해주세요.\n");
        exit(0);
    }
    fclose(stdin);
}

bool Sosu(int num){
    if(num != 1){
        for(int i = 2; i < num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    return false;
}

void Find(){
    for(int i = mn; i <= mx; i++){
        bool ok = false;

        if(Sosu(i)){
            double gari = in;

            while(gari != 1){
                gari--;
                int n = pow(N, gari);
                int divid = i / n;
                if(!Sosu(divid)){
                    ok = false;
                }
                else{
                    ok = true;
                }
            }

            if(ok){
                data[cnt] = i;
                cnt++;
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < cnt; i++){
        printf("%d\n", data[i]);
    }
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    Input();
    Find();
    Output();
    return 0;
}
