#include <cstdio>

int star, kind;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &star);
    fclose(stdin);
}

int Factorial(int num){
    int result = 1;
    for(int i = 1; i <= num; i++){
        result = i * result;
    }
    return result;
}

void Up(){
    int maxTwo = star / 2;
    int two_cnt, one_cnt, total_cnt;
    two_cnt = maxTwo;

    while(two_cnt != -1){
        one_cnt = star - (2 * two_cnt);
        total_cnt = two_cnt + one_cnt;
        kind += Factorial(total_cnt) / Factorial(two_cnt) / Factorial(one_cnt);
        two_cnt--;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", kind);
    fclose(stdout);
}

int main()
{
    Input();
    Up();
    Output();
    return 0;
}
