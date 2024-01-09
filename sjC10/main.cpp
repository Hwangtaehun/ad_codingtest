#include <cstdio>
#define N 11

//기존
int data[N][N];
bool visited[N][N];
int num, cnt;
int mn = 10000000000;

//풀이
int m[11][11];
int col_check[11];
int n, min_sol = 0x7fffffff;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

void ArrayPrn(int row, int col, int score){
    for(int i = 0; i < n; i++){
        printf("%d ", col_check[i]);
    }
    printf("\t%d %d %d %d\n", row, col, score, min_sol);
}

void Solve(int row, int score){
    if(row == n){
        if(score < min_sol){
            min_sol = score;
        }
        return;
    }

    for(int i = 0; i < n; i++){
        if(col_check[i] == 0){
            col_check[i] = 1;
            ArrayPrn(row, i, score);
            Solve(row+1, score+m[row][i]);
            col_check[i]=0;
        }
    }
    return;
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}


int Minum(int col, int hap){
    if(col == num){
        if(hap < mn){
            mn = hap;
        }
        return mn;
    }

    for(int i = 0; i < num; i++){
        if(!visited[col][i]){
            for(int j = 0; j <num; j++){
                visited[col][j] = true;
            }

            for(int j = 0; j < num; j++){
                visited[j][i] = true;
            }

            hap += data[col][i];
            col++;
            return Minum(col, hap);
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", mn);
    fclose(stdout);
}

int main()
{
    /*
    In();
    if(Minum(0, 0) != 0){
        Out();
    }
    */

    Input();
    Solve(0, 0);
    printf("%d", min_sol);
    return 0;
}
