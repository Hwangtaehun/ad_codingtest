#include<cstdio>
#include<queue>
using namespace std;
#define N 1000

struct ROWCOL{
    int row;
    int col;
};

int data[N+1][N+1];
int n, m;
queue <ROWCOL> q;
ROWCOL cur;
ROWCOL di[] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &data[i][j]);
            if(data[i][j] == 1){
                q.push((ROWCOL){i,j});
            }
        }
    }
}

void Output(){
    int mx = 0x80000000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(data[i][j] == 0){
                printf("-1");
                return;
            }

            if(mx < data[i][j]){
                mx = data[i][j];
            }
        }
    }
    printf("%d", mx - 1);
}

void TestPrn(queue <ROWCOL> q1, ROWCOL cur){
    printf("%2d,%d Ã³¸® ÈÄ queue : ", cur.row, cur.col);
    while(!q1.empty()){
        printf("%d,%d ", q1.front().row, q1.front().col);
        q1.pop();
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Bfs(){
    int row, col, nr, nc;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        row = cur.row;
        col = cur.col;

        for(int i = 0; i < 4; i++){
            nr = row + di[i].row;
            nc = col + di[i].col;

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || data[nr][nc] != 0)
                continue;
            data[nr][nc] = data[row][col] + 1;
            q.push((ROWCOL){nr, nc});
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
