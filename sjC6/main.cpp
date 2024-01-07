#include <cstdio>
#define N 19

int data[N][N];
int col, row, color;

void Input(){
    freopen("input.txt", "r", stdin);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &data[i][j]);
        }
    }
}


int Check(int cnt, int color, int m_col, int m_row, int dir){
    if(cnt == 5){
        return cnt;
    }

    if(dir == 0){
        if(m_row + 1 < N && data[m_col][m_row + 1] == color){
            cnt++;
            return Check(cnt, color, m_col, m_row + 1, -2);
        }else if(m_col + 1 < N && m_row - 1 >= 0 && data[m_col + 1][m_row - 1] == color){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row - 1, -1);
        }else if(m_col + 1 < N && data[m_col + 1][m_row] == color){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row, 2);
        }else if(m_col + 1 < N && m_row + 1 < N &&data[m_col + 1][m_row + 1] == color){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row + 1, 1);
        }else{
            return 0;
        }
    }
    else{
        if(m_row + 1 < N && dir == -2){
            cnt++;
            return Check(cnt, color, m_col, m_row + 1, -2);
        }else if(m_col + 1 < N && m_row - 1 >= 0 && dir == -1){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row - 1, -1);
        }else if(m_col + 1 < N && dir == 2){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row, 2);
        }else if(m_col + 1 < N && m_row + 1 < N && dir == 1){
            cnt++;
            return Check(cnt, color, m_col + 1, m_row + 1, 1);
        }else{
            return 0;
        }
    }
}

void Game(){
    color = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(data[i][j] != 0){
                int cnt = Check(1, data[i][j], i, j, 0);
                if(color == 0 && cnt == 5){
                    color = data[i][j];
                    col = i+1;
                    row = j+1;
                }
            }
        }
    }
}

void Output(){
    printf("%d\n", color);
    printf("%d %d", col, row);
}

int main()
{
    Input();
    Game();
    Output();
    return 0;
}
