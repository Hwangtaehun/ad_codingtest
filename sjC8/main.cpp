#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

//기존
int start, finish, cnt;

//풀이
int a, b, res = 40;

struct ELEMENT
{
    int temp;
    int cnt;
};

queue <ELEMENT> q;

void f1(){
    int cha, bt10, bt5, bt1;
    cha = (a > b) ? a - b: b - a;
    bt10 = cha / 10;
    bt5 = cha % 10 / 5;
    bt1 = cha % 5;
    printf("%d\n", bt10 + bt5 + bt1);
}

void f2(int temp, int cnt){
    if(cnt > res)
        return;

    if(temp == b){
        if(cnt < res){
            res = cnt;
        }
        return;
    }

    if(temp < b){
        f2(temp + 10, cnt + 1);
        f2(temp + 5, cnt + 1);
        f2(temp + 1, cnt + 1);
    }else{
        f2(temp - 10, cnt + 1);
        f2(temp - 5, cnt + 1);
        f2(temp - 1, cnt + 1);
    }
}

void f3(){
    ELEMENT cur;
    q.push((ELEMENT){a, 0});
    while(!q.empty()){
        cur = q.front();
        q.pop();
        printf("%d,%d ", cur.cnt, cur.temp);

        if(cur.temp == b)
            break;
        if(cur.temp < b){
            q.push((ELEMENT){cur.temp + 10, cur.cnt + 1});
            q.push((ELEMENT){cur.temp + 5, cur.cnt + 1});
            q.push((ELEMENT){cur.temp + 1, cur.cnt + 1});
        }else{
            q.push((ELEMENT){cur.temp - 10, cur.cnt + 1});
            q.push((ELEMENT){cur.temp - 5, cur.cnt + 1});
            q.push((ELEMENT){cur.temp - 1, cur.cnt + 1});
        }
    }
    printf("bfs = %d\n", cur.cnt);
}

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

void Remote(){
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
    /*
    Input();
    Remote();
    Output();
    */

    scanf("%d%d", &a, &b);
    f1();
    f2(a,0);
    printf("bfs = %d\n", res);

    f3();
    return 0;
}
