#include <cstdio>

int data[20][3], area, endSw, kind;
bool chk[20];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &area);
    for(int i = 0; i < area; i++){
        scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
    }
}

void Print(){
    for(int i = 0; i < area; i++){
        printf("%d %d %d\n", data[i][0], data[i][1], data[i][2]);
    }
}

void Move(int index, int weight, int cnt){
    int minimum, maxium;
    minimum = data[index][0] - data[index][1];
    maxium = data[index][0] + data[index][1];
    chk[index] = true;
    chk[0] = false;

    if(minimum < 0){
        minimum = 0;
    }

    if(maxium > 15){
        maxium = 15;
    }

    if(endSw){
        return;
    }

    if(cnt > area*2){
        endSw = 1;
        return;
    }

    if(index == 0){
        if(chk[area-1]){
            kind++;
            return;
        }
    }

    if(index == area - 1){
        weight = 1;
    }

    for(int i = 0; i < area; i++){
        if(minimum <= data[i][0] && data[i][0] <= maxium && weight <= data[i][2] && !chk[i]){
            Move(i, weight, cnt+1);
        }
    }
}

int main()
{
    In();
    //Print();
    for(int i = 1; i < area; i++){
        if(0 < data[i][0] || data[i][0] < 8){

        }
    }
    return 0;
}
