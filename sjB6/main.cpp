#include <cstdio>
#include <queue>
using namespace std;
#define N 100

struct ROWCOL{
    int box;
    int row;
    int col;
};
int data[N+1][N+1][N+1];
int n, m, h;
queue <ROWCOL> q;
ROWCOL cur;
ROWCOL di[] = {{0,0,-1}, {0,0,1}, {0,-1,0}, {0,1,0}, {1,0,0}, {-1,0,0}};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &m, &n, &h);
    for (int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &data[k][i][j]);
                if(data[k][i][j] == 1){
                    q.push((ROWCOL){k, i, j});
                }
            }
        }
    }
}

void Output(){
    int mx = 0x80000000;
    for (int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(data[k][i][j] == 0){
                    printf("-1");
                    return ;
                }
                if(mx < data[k][i][j]){
                    mx = data[k][i][j];
                }
            }
        }
    }
    printf("%d", mx -1);
}

void TestPrn(queue <ROWCOL> q1, ROWCOL cur){
    int i = 1;
    printf(" %d, %d, %d 처리 후 queue : ", cur.box, cur.row, cur.col);
    while(!q1.empty()){
        printf("%d번째 %d %d %d ", i, q1.front().box, q1.front().row, q1.front().col);
        q1.pop();
        i++;
    }
    printf("\n");
    for (int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%2d", data[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

void Bfs(){
    int box, row, col, nb, nr, nc;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        box = cur.box;
        row = cur.box;
        col = cur.box;
        nb = 0;
        for(int i = 0; i < 6; i++){
            nb = box + di[i].box;
            nr = row + di[i].row;
            nc = col + di[i].col;
            if(nb < 0 || nb >= h || nr < 0 || nr >= n || nc < 0 || nc >= m || data[nb][nr][nc] != 0)
                continue;
            data[nb][nr][nc] =  data[box][row][col] + 1;
            q.push((ROWCOL){nb, nr, nc});
        }
        TestPrn(q, cur);
    }
}

int main()
{
    Input();
    Bfs();
    Output();
    return 0;
}
