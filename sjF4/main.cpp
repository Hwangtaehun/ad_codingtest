#include <cstdio>

int row, col, data[200][200], maxinum = 0;

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
    In();
    Dig(0, 0, 0);
    Out();
    return 0;
}
