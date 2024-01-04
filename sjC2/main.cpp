#include <cstdio>

int data[9][9];
int big, col, row;

void Input(){
    freopen("input.txt", "r", stdin);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &data[i][j]);
        }
    }
}

void Compare(){
    big = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(big < data[i][j]){
                big = data[i][j];
                col = i;
                row = j;
            }
        }
    }
}

void Output(){
    col++;
    row++;
    freopen("output.txt", "w", stdout);
    printf("%d", big);
    printf("\n");
    printf("%d %d", col, row);
}

int main()
{
    Input();
    Compare();
    Output();
    return 0;
}
