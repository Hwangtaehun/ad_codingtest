#include <cstdio>
#include <cmath>

using namespace std;

int data[1002][2], di[1002][1002], sz, index, mi = 0x0fffffff;
//Solve
int n, m, debugCnt, ans = 0x7fffffff;

void ArrayPrn(){
    int a, b;

    for(a=0; a < m+2; a++){
        for(b = 0; b < 2; b++){
            printf("%3d", di[a][b]);
        }
        printf("\n");
    }
    printf("\n");

    for(a=0; a < m + 2; a++){
        for(b = 0; b < m + 2; b++){
            printf("%3d", di[a][b]);
        }
        printf("\n");
    }
    printf("\n");
}

void Distance(){
    for(int i = 0; i < m + 2; i++){
        for(int j = 0; j < m + 2; j++){
            di[i][j] = abs(data[i][0] - data[j][0]) + abs(data[i][1] - data[j][1]);
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = n;
    for(int i = 2; i < m + 2; i++){
        scanf("%d%d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Greedy(int a, int b){
    ans = 0;

    for(int i = 2; i < m + 2; i++){
        if(di[i][a] > di[i][b]){
            ans += di[i][b], b = i;
        }else{
            ans += di[i][a], a = i;
        }
    }
}

void Solve(int a, int b, int d){
    int next = (a > b ? a: b) + 1;

    if(d > ans){
        return;
    }

    printf("%d %d %d %3d %3d\n", a, b, next, d, di[a][next]);
    debugCnt++;

    if(next >= m + 2){
        if(d < ans){
            ans = d;
        }

        return;
    }

    Solve(next, b, d+di[a][next]);
    Solve(a, next, d+di[b][next]);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &sz, &index);
    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = sz;
    for(int i = 2; i < index + 2; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
    Distance();
}

void Print(){
    printf("data의 값\n");
    for(int i = 0; i < index + 2; i++){
        printf("%d %d\n", data[i][0], data[i][1]);
    }
    printf("\n");
    printf("di의 값\n");
    for(int i = 0; i < index + 2; i++){
        for(int j = 0; j < index + 2; j++){
            printf("%2d ",di[i][j]);
        }
        printf("\n");
    }
}

void Path(int car1, int car2, int dis){
    int next;

    if(car1 > car2){
        next = car1 + 1;
    }
    else{
        next = car2 + 1;
    }

    if(next == index + 2){
        if(dis < mi){
            mi = dis;
        }
        //printf("mi = %d\n", mi);
        return;
    }

    Path(car1, next, dis + di[car1][next]);
    Path(next, car2, dis + di[car2][next]);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", mi);
    fclose(stdout);
}

int main()
{
    Input();
    Distance();
    ArrayPrn();
    Greedy(0, 1);
    Solve(0, 1, 0);
    printf("%d", ans);
    printf("\ndebugCnt = %d\n", debugCnt);
    //In();
    //Path(0, 1, 0);
    //Output();
    return 0;
}
