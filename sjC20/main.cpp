#include <cstdio>

int data[11][11] = {0,};
int row, col;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &col, &row);
    fclose(stdin);
}

void Dataprint(){
    for(int i = 0; i <= col; i++){
        for(int j = 0; j <= row; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Path(){
    for(int i = 0; i <= col; i++){
        data[i][0] = 1;
    }

    for(int i = 1; i <= col; i++){
       for(int j = 1; j <= i; j++){
            data[i][j] = data[i-1][j] + data[i][j-1];
        }
        Dataprint();
        printf("\n");
    }

    if((col+row)%2 != 0){
        data[col][row] = data[col-1][row] + data[col][row-1];
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", data[col][row]);
    fclose(stdout);
}

int main()
{
    Input();
    Path();
    Output();
}
