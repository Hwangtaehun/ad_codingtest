#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#define N 10

//기존
int data[100];
int cnt = 0;
double mx = 11, mn = 0, in;

//풀이
int n;

int isprime1(int x){
    if(x < 2){
        return 0;
    }

    if(x == 2){
        return 1;
    }

    if(x % 2 == 0){
        return 0;
    }

    for(int i = 3; i*i <= x; i += 2){
        if(x % i == 0){
            return 0;
        }
    }

    return 1;
}

void f1(int num, int len){
    if(len == n){
        if(num == 0){
            return;
        }

        int flag = 1;
        int temp = num;

        while(temp){
            if(!isprime1(temp)){
                return;
            }
            temp /= 10;
        }

        cnt++;
        printf("%d\n", num);
        return;
    }else{
        for(int i = 1; i <= 9; i++){
            f1(num * 10 + i, len + 1);
        }
    }
}

int isprime2(int x){
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}

void f2(int num, int len){
    if(len == n){
        if(isprime2(num)){
            cnt++;
            printf("%d\n", num);
        }
        return;
    }else{
        if(isprime2(num)){
            f2(num*10+1, len+1);
            f2(num*10+3, len+1);
            f2(num*10+7, len+1);
            f2(num*10+9, len+1);
        }
    }
}

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
    //Input();
    //Find();
    //Output();
    scanf("%d", &n);
    int start = clock();

    f1(0, 0);
    printf("%d\n\n", cnt);
    printf("first clock = %d\n", clock() - start);

    start = clock();
    cnt = 0;
    f2(2,1);
    f2(3,1);
    f2(5,1);
    f2(7,1);
    printf("%d\n\n", cnt);
    printf("Second clock %d\n", clock() - start);
    return 0;
}
