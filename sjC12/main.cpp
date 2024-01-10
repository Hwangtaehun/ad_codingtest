#include <cstdio>

int col, row;
int data[100][100];
bool in_data[100][100];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &col, &row);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            scanf("%d", &data[i][j]);
        }
    }
}

void Fill(int x, int y, bool cheese){
    if(x < 0 || x >= row || y < 0 || y >= col || data[y][x] == 1){
        return;
    }

}

void Inside(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            in_data[i][j] = data[i][j];
        }
    }

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if(in_data[i][j]){
                if(!in_data[i][j+1]){

                    int y = i, x = j+1;
                    Fill(j+1, i, 0);
                }
            }
        }
    }
}

void Print(){
    printf("%d %d\n", col, row);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", in_data[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Input();
    Inside();
    Print();

    return 0;
}
