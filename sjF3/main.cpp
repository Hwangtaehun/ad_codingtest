#include <cstdio>

int start, arrive, ability[3], minimum = 0x7fffffff;

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

    Find(num - ability[0], cnt + 1);
    Find(num - ability[1], cnt + 1);
    Find(num - ability[2], cnt + 1);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", minimum);
    fclose(stdout);
}

int main()
{
    In();
    Find(arrive - start, 0);
    if(minimum ==  0x7fffffff){
        minimum = -1;
    }
    Out();
    return 0;
}
