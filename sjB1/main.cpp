#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 30

using namespace std;

int data[N+1][N+1], size[N+1];
int n, cnt;

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

void ArrayPrn(){
    printf("탐색 후 배열 내여용 \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Dfs(int r, int c, int no){
    if(r < 0 || r >= n || c < 0 || c >= n || data[r][c] != 1)
        return;

    data[r][c] = no;

    Dfs(r+1, c, no);
    Dfs(r-1, c, no);
    Dfs(r, c+1, no);
    Dfs(r, c-1, no);
}

bool compare(int left, int right){
    return left > right;
}

void Solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(data[i][j] == 1){
                cnt++;
                Dfs(i, j, cnt+1);
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

    ArrayPrn();
    Output();
    return 0;
}
