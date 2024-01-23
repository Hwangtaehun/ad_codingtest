#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int data[1002][2];
int event, sz, distance = 0x0fffffff;

//solve
int di[1002][1002], n, m, ans = 0x0fffffff;

void Distance(){
    for(int a = 0; a < m + 2; a++){
        for(int b = 0; b < m + 2; b++){
            di[a][b] = std::abs(data[a][0] - data[b][0]) + std::abs(data[a][1] - data[b][1]);
        }
    }
}

int dis(int a, int b){
    int d;
    d = abs(data[a][0] - data[b][0]) + abs(data[a][1] - data[b][1]);

    return d;
}

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = n;
    for(int i = 2; i < m +2; i++){
        scanf("%d%d", &data[i][0], &data[i][1]);
    }
}

void Solve(int a, int b, int d){
    int next = (a > b? a : b) + 1;

}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    scanf("%d", &event);
    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = sz;
    for(int i = 2; i < event + 2; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Drive(int car1, int car2, int d){
    int next = ( car1 > car2? car1 : car2) + 1;
    printf("%d,%d,%d,%d : %d,%d\n", car1, car2, next, d, dis(car1, next), dis(car2, next));

    if(next >= event + 2){
        if(d < distance)
            distance = d;
        return;
    }

    Drive(next, car2, d + dis(car1, next));
    Drive(car1, next, d+dis(car2, next));
}

int main()
{
    In();
    Drive(0,1,0);
    printf("%d", distance);
    return 0;
}
