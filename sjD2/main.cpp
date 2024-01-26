#include <cstdio>
#include <ctime>

int number, sz = 0;
int all[100000];

//solve
int n, result;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    fclose(stdin);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

bool isPrime(int k){
    for(int i = 2; i * i <= k; i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

void Prime1(){
    int i, cnt = 0;

    for(i = 2; i < 100000; i++){
        if(isPrime(i)){
            cnt++;
            if(cnt == n){
                break;
            }
        }
    }

    result = i;
    printf("%d\n", i);
}

void Prime2(){
    int i, j, num, array[100001] = {0}, cnt = 0;

    for(i = 2; i < 100000; i++){
        array[i] = i;
    }

    for(i = 2; i < 100000; i++){
        if(array[i] != 0){
            cnt++;

            if(cnt >= n){
                break;
            }

            for(j = i + i; j <= 100000; j += i){
                array[i] = 0;
            }
        }
    }

    result = i;
    printf("%d\n", i);
}

bool Sosu(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &number);
    fclose(stdin);

    for(int i = 2; i <= 100000; i++){
        if(Sosu(i)){
            all[sz] = i;
            sz++;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", all[number-1]);
    fclose(stdout);
}

int main()
{
    In();
    Prime1();
    //Prime2();
    Out();
    return 0;
}
