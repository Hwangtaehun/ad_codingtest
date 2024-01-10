#include <cstdio>

int col, row, hours;
int data[100][100];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &col, &row);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            scanf("%d", &data[i][j]);
        }
    }
}

void Print(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Air(int x, int y){
    if(x < 0 || x >= row || y < 0 || y >= col || data[y][x] != 0){
        return;
    }

    data[y][x] = 2;

    Air(x+1, y);
    Air(x-1, y);
    Air(x, y+1);
    Air(x, y-1);
}

bool Checking(int x, int y){
    int cnt = 0;

    if(data[y][x-1] == 2){
        cnt++;
    }

    if(data[y][x+1] == 2){
        cnt++;
    }

    if(data[y-1][x] == 2){
        cnt++;
    }

    if(data[y+1][x] == 2){
        cnt++;
    }

    if(cnt > 1){
        return true;
    }else{
        return false;
    }
}

bool Exist(){
    for(int i = 0; i < col; i++){
       for(int j = 0; j < row; j++){
            if(data[i][j] == 1){
                return true;
            }
       }
   }
   return false;
}

void Melt(){
    for(int i = 0; i < col; i++){
       for(int j = 0; j < row; j++){
            if(data[i][j] == 1){
                if(Checking(j, i)){
                    data[i][j] = 3;
                }
            }
       }
   }

   for(int i = 0; i < col; i++){
       for(int j = 0; j < row; j++){
            if(data[i][j] == 3){
                data[i][j] = 2;
            }
       }
   }

   for(int i = 0; i < col; i++){
       for(int j = 0; j < row; j++){
            if(data[i][j] == 0){
                Air(j, i);
            }
       }
   }
}

void Ageing(){

   Air(0, 0);

   while(Exist()){
        Melt();
        hours++;
   }

   printf("%d\n", hours);
}

int main()
{
    Input();
    Ageing();
    return 0;
}
