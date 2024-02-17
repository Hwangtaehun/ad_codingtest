#include <cstdio>

int start, arrive, ability[3], minimum = 0x7fffffff;

//solve
int a, b, able[3], ans=2000;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &a, &b);
    for(int i = 0; i < 3; i++){
        scanf("%d", &able[i]);
    }
    fclose(stdin);
}

void Back(int next, int cnt){
    if(next > b){
        return;
    }

    if(b == next){
        if(cnt < ans){
            ans = cnt;
        }
    }

    for(int i = 0; i < 3; i++){
        Back(next + able[i], cnt + 1);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &start, &arrive);
    for(int i = 0; i < 3; i++){
        scanf("%d", &ability[i]);
    }
    fclose(stdin);
}

void Find(int num, int cnt){
    if(num < 0){
        return;
    }else if(num == 0){
        if(cnt < minimum){
            minimum = cnt;
        }
        return;
    }

    for(int i = 0; i < 3; i++){
        Find(num - ability[i], cnt + 1);
    }
}

void Out(){
    //freopen("output.txt", "w", stdout);
    printf("%d", minimum);
    //fclose(stdout);
}

int main()
{
    Input();
    Back(a, 0);
    if(ans != 2000){
        printf("%d", ans);
    }
    else{
        printf("-1");
    }
    /*
    In();
    Find(arrive - start, 0);
    if(minimum ==  0x7fffffff){
        minimum = -1;
    }
    Out();
    */
    return 0;
}
