#include <cstdio>

int star, kind, cnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &star);
    fclose(stdin);
}

void Solve(int v){
    if(v > star){
        printf("X");
        return;
    }

    if(v == star){
        cnt++;
        printf(" %d\n", v);
        return;
    }

    printf(" %d", v);
    Solve(v + 1);
    printf(" %d", v);
    Solve(v + 2);
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
    Solve(0);
    printf("\n%d\n", cnt);
    //Up();
    //Output();
    return 0;
}
