#include <cstdio>
#include <queue>

struct VERTEX{
    int row, col;
};
int h, w;
char maze[101][101];
int visited[101][101];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int sRow, sCol, gRow, gCol;

bool isSafe(int row, int col){
    return (row >= 0 && row < h) && (col >= 0 && col < w);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i++){
        scanf("%s", maze[i]);
        for(int j = 0; j < w; j++){
            if(maze[i][j] == 'S'){
                sRow = i, sCol = j;
            }
            else if(maze[i][j] == 'G'){
                gRow = i, gCol = j, maze[i][j] = '.';
            }
        }
    }
}

void TestPrn(std::queue <VERTEX> q1, VERTEX cur){
    printf("%2d,%d Ã³¸® ÈÄ queue : ", cur.row, cur.col);
    while(!q1.empty()){
        printf("%d,%d", q1.front().row,q1.front().col);
        q1.pop();
    }
    printf("\n");
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%2d", visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Solve(){
    std::queue <VERTEX> q;

    q.push((VERTEX){sRow, sCol});
    visited[sRow][sCol] = 0;

    while(!q.empty()){
        VERTEX cur = q.front();
        q.pop();

        if(cur.row == gRow && cur.col == gCol)
            break;

        for(int i = 0; i < 4; i++){
            int row = cur.row + dx[i], col = cur.col + dy[i];
            if(isSafe(row, col) && !visited[row][col] && maze[row][col]=='.'){
                    visited[row][col] = visited[cur.row][cur.col] + 1;
                    q.push((VERTEX){row, col});
            }
        }
       TestPrn(q, cur);
    }
    return visited[gRow][gCol];
}

int main()
{
    Input();
    printf("%d\n", Solve());
    return 0;
}
