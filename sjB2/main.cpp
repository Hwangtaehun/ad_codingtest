#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define N 30

using namespace std;

int data [N+1][N+1];
int size [N+1];
int n, cnt; //Å©±â, ±¼ÀÇ ¼ö
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

struct VERTEX{
    int x, y;
};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%d\n", size[i]);
    }
    fclose(stdout);
}

bool isSafe(int col, int row){
    return ( col >= 0 && col < n ) && ( row >= 0 && row < n );
}

bool compare(int left, int right){
    return left > right;
}

void Bfs(int r, int c, int no){
    std::queue <VERTEX> q;
    q.push((VERTEX){r,c});
    data[r][c] = no;

    while(!q.empty()){
        VERTEX node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(isSafe(node.x + dx[i], node.y + dy[i]) && data[node.x + dx[i]][node.y + dy[i]] == 1){
                data[node.x + dx[i]][node.y + dy[i]] = no;
                q.push((VERTEX){node.x + dx[i], node.y + dy[i]});
            }
        }
    }
}

void Solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(data[i][j] == 1){
                cnt++;
                Bfs(i, j, cnt+1);
            }
        }
    }
    for(int i = 0;  i <  n; i++){
        for(int j = 0; j < n; j++){
            if(data[i][j]){
                    size[data[i][j]-2]++;

            }
        }
    }

    std::sort(size, size+cnt, compare);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
