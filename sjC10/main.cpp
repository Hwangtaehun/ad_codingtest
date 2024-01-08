#include <cstdio>
#define N 11

int data[N][N];
bool visited[N][N];
int num, cnt;
int mn = 10000000000;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}


int Minum(int col, int hap){
    if(col == num){
        if(hap < mn){
            mn = hap;
        }
        return mn;
    }

    for(int i = 0; i < num; i++){
        if(!visited[col][i]){
            for(int j = 0; j <num; j++){
                visited[col][j] = true;
            }

            for(int j = 0; j < num; j++){
                visited[j][i] = true;
            }

            hap += data[col][i];
            col++;
            return Minum(col, hap);
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", mn);
    fclose(stdout);
}

int main()
{
    Input();
    if(Minum(0, 0) != 0){
        Output();
    }

    return 0;
}
