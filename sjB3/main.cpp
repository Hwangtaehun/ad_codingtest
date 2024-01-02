#include <iostream>
#include <cstdio>

using namespace std;
int n, cnt;
bool colChk[10], incChk[20], decChk[20];

void TestPrn(int no, int row, int col){
    printf("%d,%d,%d %d : ", no, row, col, cnt);

    for(int i = 1; i <= n; i++){
        printf("%d ", colChk[i]);
    }
    printf(" : ");
    for(int i = 1; i <= n*2; i++){
        printf("%d ", incChk[i]);
    }
    printf(" : ");
    for(int i = 1; i <= n*2; i++){
        printf("%d ", decChk[i]);
    }
    printf("\n");
}

void Dfs(int row){
    if(row > n){
        cnt++;
        return;
    }
    for(int col = 1; col <= n; col++){
        if(!colChk[col] && !incChk[row+col] && !decChk[n+(row-col)]){
            colChk[col]=incChk[row+col]=decChk[n+(row-col)]=true;
            TestPrn(1, row, col);

            Dfs(row+1);

            colChk[col]=incChk[row+col]=decChk[n+(row-col)]=false;
            TestPrn(2, row, col);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Dfs(1);
    printf("%d", cnt);
    return 0;
}
