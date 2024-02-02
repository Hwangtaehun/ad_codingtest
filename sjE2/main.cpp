#include <cstdio>
#define MAX 10000

int num;
char str[MAX + 1];

void Solve1(int n){
    if(n == 1){
        putchar('*');
        putchar('\n');
    }else{
        Solve1(n-1);
        for(int i = 0; i < n; i++){
            putchar('*');
        }
        putchar('\n');
    }
}

void Solve2(int n){
    if(n > 0){
        Solve2(n-1);
        for(int i = 0; i < n; i++){
            putchar('*');
        }
        putchar('\n');
    }
}

void Solve3(int n){
    if(n > 0){
        Solve3(n-1);
        str[n] = '*';
        printf("%s\n", str + 1);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &num);
    fclose(stdin);
}

void Star(){
    freopen("output.txt", "w", stdout);
    for(int i = 1; i <= num; i++){
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    fclose(stdout);
}

int main()
{
    int n;
    scanf("%d", &n);
    Solve1(n);
    Solve2(n);
    Solve3(n);
    //In();
    //Star();
    return 0;
}
