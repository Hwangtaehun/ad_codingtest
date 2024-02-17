#include <cstdio>
#define MAX(a,b) ((a) >= (b) ? (a) : (b))

int row, col, data[200][200], maxinum = 0;

//solve
int n, m, mine[220][220], table[220][220];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d ", &mine[i][j]);
        }
    }
    fclose(stdin);
}

int Back(int row, int col){
    if(table[row][col]){
        return table[row][col];
    }

    if(row == n && col == m){
        return mine[row][col];
    }

    if(row > n || col > m){
        return 0;
    }

    return table[row][col] = mine[row][col] + MAX(Back(row + 1, col), Back(row, col + 1));
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &col, &row);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            scanf("%d ", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Print(){
    printf("%d %d\n", col, row);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Dig(int m_row, int m_col, int cnt){
    if(data[m_row][m_col] == 1){
        cnt = cnt + 1;
    }

    if(m_row == row && m_col == col){
        if(maxinum < cnt){
            maxinum = cnt;
            return;
        }
    }

    if(m_row < row){
        Dig(m_row + 1, m_col, cnt);
    }

    if(m_col < col){
        Dig(m_row, m_col + 1, cnt);
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", maxinum);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Dig(0, 0, 0);
    Out();
    */
    Input();
    printf("%d", Back(1, 1));
    return 0;
}
