#include <cstdio>
#include <cstring>
#include <queue>

int col, row, hours;
int data[100][100];

//Ç®ÀÌ
int a1[101][101], a2[101][101];
int rowCnt, colCnt;

void ArrayPrn(){
    for(int i = 1; i <= rowCnt; i++){
        for(int j = 1; j <= colCnt; j++){
            printf("%d", a1[i][j]);
        }
        printf("\t");
        for(int j = 1; j <= colCnt; j++){
            printf("%d", a2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Input(void){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &rowCnt, &colCnt);
    for(int i = 1; i <= rowCnt; i++){
        for(int j = 1; j <= colCnt; j++){
            scanf("%d", &a1[i][j]);
            a2[i][j] = a1[i][j];
        }
    }
}

void In(){
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

void Fill1(int x, int y){
    if( x < 1 || x > rowCnt || y < 1 || y > colCnt || a1[x][y] != 0){
        return;
    }

    a1[x][y] = 2;
    Fill1(x + 1, y);
    Fill1(x - 1, y);
    Fill1(x, y + 1);
    Fill1(x, y - 1);
}

int SideCount(int x, int y){
    int cnt = 0;
    if(a1[x + 1][y] == 2)
        cnt++;
    if(a1[x - 1][y] == 2)
        cnt++;
    if(a1[x][y + 1] == 2)
        cnt++;
    if(a1[x][y - 1] == 2)
        cnt++;
    return cnt;
}

void Solve1(){
    int i, j, hour = 0, flag;

    while(1){
        Fill1(1, 1);
        flag = 0;

        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount(i, j) >= 2){
                    a2[i][j] = 0;
                    flag = 1;
                }
            }
        }

        if(flag == 0){
            printf("%d", hour);
            break;
        }
        hour++;

        ArrayPrn();
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
}

void Fill2(int x, int y){
    if( x < 1 || x > rowCnt || y < 1 || y > colCnt || a2[x][y] != 0){
        return;
    }

    a2[x][y] = 2;
    Fill2(x + 1, y);
    Fill2(x - 1, y);
    Fill2(x, y + 1);
    Fill2(x, y - 1);
}

void Solve2(){
    int i, j, hour = 0, flag;

    Fill1(1, 1);
    Fill2(1, 1);
    ArrayPrn();
    printf("aaaa\n");

    while(1){
        flag = 0;
        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount(i, j) >= 2){
                    a2[i][j] = 0;
                    flag = 1;
                }
            }
        }

        ArrayPrn();
        if(flag == 0){
            printf("%d", hour);
            break;
        }

        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && a2[i][j] == 0){
                    Fill2(i, j);
                }
            }
        }
        hour++;
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
}

int SideCount2(int x, int y){
    int cnt = 0;
    if(a2[x + 1][y] == 2)
        cnt++;
    if(a2[x - 1][y] == 2)
        cnt++;
    if(a2[x][y + 1] == 2)
        cnt++;
    if(a2[x][y - 1] == 2)
        cnt++;

    return cnt;
}

void Fill3(int x, int y){
    if(x < 1 || x > rowCnt || y < 1 || y > colCnt)
        return;

    if(a2[x][y] == 3 || a2[x][y] == 0){
        a2[x][y] = 2;

        Fill3(x + 1, y);
        Fill3(x - 1, y);
        Fill3(x, y + 1);
        Fill3(x, y - 1);
    }
}

struct ROWCOL {
    int row;
    int col;
};

std::queue <ROWCOL> q;

void QueuePrn(std::queue <ROWCOL> q1){
    while(!q1.empty()){
        printf("%d%d ", q1.front().row, q1.front().col);
        q1.pop();
    }
    printf("\n");
}

void Solve3(){
    int i, j, hour = 0, flag;
    Fill3(1,1);
    ArrayPrn();
    printf("aaaa\n");
    while(1){
        flag = 0;
        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount2(i, j) >= 2){
                    a2[i][j] = 3;
                    q.push((ROWCOL){i,j});
                    flag = 1;
                }
            }
        }
        ArrayPrn();
        if(flag == 0){
            printf("%d", hour);
            break;
        }

        ROWCOL cur;
        QueuePrn(q);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            Fill3(cur.row, cur.col);
        }
        hour++;
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
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
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", hours);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Ageing();
    Out();
    */

    Input();
    Solve1();

    return 0;
}
