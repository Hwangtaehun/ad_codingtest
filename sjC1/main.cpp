#include <cstdio>

int yaksu [100000];
int size = 0;
int n;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
}

int Divisor1(){
    int i, tot = 0;
    for(i = 1; i <= n; i++){
        if(n % i == 0){
            tot += i;
        }
    }

    return tot;
}

int Divisor2(){
    int i, bound = n / 2, tot = 1 + n;
    for(i = 2; i <= bound; i++){
        if(n % i == 0){
            tot += i;
        }
    }

    return tot;
}

int Divisor3(){
    int i, tot = 0;
    for(i = 1; i * i < n; i++){
        if(n % i == 0){
            tot += (i + n / i);
        }
    }

    if(i * i == n){
        tot += i;
    }

    return tot;
}

void Yaksu(){
    int i = n;
    while(i != 0){
        if(n%i == 0){
            yaksu[size] = i;
            size++;
        }
        i--;
    }
}

void Hak(){
    int result = 0;
    for(int i = 0; i < size; i++){
        result += yaksu[i];
    }
    printf("%d", result);
}

int main()
{
    Input();
    /*
    Yaksu();
    Hak();
    */
    printf(" %d\n", Divisor1());
    printf(" %d\n", Divisor2());
    printf(" %d\n", Divisor3());
    return 0;
}
