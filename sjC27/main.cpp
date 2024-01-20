#include <cstdio>

int data[20][3], area, endSw, kind;

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

void boolPrint(bool a[]){
    for(int i = 0; i < area; i++){
        printf("chk[%d] = %d\n", i, a[i]);
    }
    printf("\n");
}

void Move(int index, int weight, int cnt, bool chk[]){
    int minimum, maxium;
    bool whole = true;
    minimum = data[index][0] - data[index][1];
    maxium = data[index][0] + data[index][1];
    chk[index] = true;
    chk[0] = false;

    boolPrint(chk);

    if(minimum < 0){
        if(index == 0){
            minimum = 1;
        }else{
            minimum = 0;
        }
    }

    if(maxium > 15){
        maxium = 15;
    }

    if(endSw){
        return;
    }

    if(cnt > area*2){
        printf("cnt > area\n");
        endSw = 1;
        return;
    }

    if(index == 0){
        if(chk[area-1]){
            kind++;
            printf("kind = %d\n", kind);
            return;
        }
    }

    if(index == area - 1){
        weight = 1;
    }

    for(int i = 1; i < area; i++){
        if(!chk[i]){
            whole = false;
            break;
        }
    }

    if(whole){
        return;
    }

    for(int i = 0; i < area; i++){
        if(minimum <= data[i][0] && data[i][0] <= maxium && weight <= data[i][2] && !chk[i]){
            Move(i, weight, cnt+1, chk);
        }
    }
}


int main()
{
    In();
    //Print();
    bool chk[area];
    for(int i = 0; i < area; i++){
        chk[i] = false;
    }
    Move(1, 0, 0, chk);
    /*
    for(int i = 1; i < area; i++){
        if(0 < data[i][0] || data[i][0] < 8){
            printf("i = %d\n", i);
            Move(i, 0, 0, chk);
        }
    }
    */
    return 0;
}
