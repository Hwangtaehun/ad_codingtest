#include <cstdio>
#include <cmath>

using namespace std;

int data[1002][2], di[1002][1002], sz, index, mi = 0x0fffffff;

void Distance(){
    for(int i = 0; i < index + 2; i++){
        for(int j = 0; j < index + 2; j++){
            di[i][j] = abs(data[i][0] - data[j][0]) + abs(data[i][1] - data[j][1]);
        }
    }
}

void Input(){
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
    Path(0, 1, 0);
    Output();
    return 0;
}
