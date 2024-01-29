#include <cstdio>

int data[10][10], sz, chk[10], mininum = 0x0fffffff;

//solve
int m[11][11], col_check[11], n, min_sol = 0x7fffffff, debugCnt, gre_check[11];

void ArrayPrn(int row, int col, int score){
    for(int i = 0; i < n; i++){
        printf("%d", col_check[i]);
    }
    printf("\t%d %d %d %d\n", row, col, score, min_sol);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    fclose(stdin);
}

void Greedy(int row){
    min_sol = 0;

    for(int i = row; i < n; i++){
        int min = 0x7fffffff, k;
        for(int j = 0; j < n; j++){
            if(!gre_check[j] && min > m[i][j]){
                min = m[i][j];
                k = j;
            }
        }
        min_sol += min;
        gre_check[k] = 1;
    }
}

void Solve(int row, int score){
    if(score > min_sol){
        return;
    }

    debugCnt++;

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
            Solve(row + 1, score + m[row][i]);
            col_check[i] = 0;
        }
    }
    return;
}

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
    //In();
    //Print();
    //Sum(0, 0);
    //Out();
    Input();
    Greedy(0);
    Solve(0, 0);
    printf("%d", min_sol);
    printf("\ndebugCnt = %d\n", debugCnt);
    return 0;
}
