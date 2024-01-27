#include <cstdio>

int data[10][10], sz, chk[10], mininum = 0x0fffffff;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Print(){
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Sum(int row, int sum){
    if(row == sz){
        if(sum < mininum){
            mininum = sum;
        }
        return;
    }

    for(int i = 0; i < sz; i++){
        if(!chk[i]){
            chk[i] = 1;
            Sum(row+1, sum + data[row][i]);
            chk[i] = 0;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", mininum);
    fclose(stdout);
}

int main()
{
    In();
    //Print();
    Sum(0, 0);
    Out();
    return 0;
}
