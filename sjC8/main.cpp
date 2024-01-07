#include <cstdio>
#include <cstdlib>
int start, finish, cnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &start, &finish);
    fclose(stdin);

    if(start < 0 || 40 < start){
        printf("현재 온도가 불가능한 숫자 입니다.");
        exit(0);
    }

    if(finish < 0 || 40 < finish){
        printf("목표 온도가 불가능한 숫자 입니다.");
        exit(0);
    }
}

void Solve(){
    int gap = finish - start;

    if(gap < 0){
        gap = -gap;
    }

    cnt += gap / 10;
    gap = gap % 10;

    if(7 < gap){
        gap = 10-gap;
        cnt += 1;
    }else if(2 < gap && gap < 5){
        gap = -(gap - 5);
        cnt += 1;
    }else{
        cnt += gap / 5;
        gap = gap % 5;
    }

    cnt += gap/1;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    Input();
    Solve();
    Output();

    return 0;
}
