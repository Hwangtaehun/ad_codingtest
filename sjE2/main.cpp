#include <cstdio>

int num;

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
    In();
    Star();
    return 0;
}
