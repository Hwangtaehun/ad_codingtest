#include <cstdio>

int data[100][100];
int pond_col, pond_row, net_col, net_row, maxium;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &pond_col, &pond_row);
    scanf("%d %d", &net_col, &net_row);
    for(int i = 0; i < pond_col; i++){
        for(int j = 0; j < pond_row; j++){
            scanf("%d", &data[i][j]);
        }
    }

}

void Solve(){
    maxium = 0;
    for(int i = 0; i < pond_col; i++){
        for(int j = 0; j < pond_row; j++){
            if(i + net_col <= pond_col && j + net_row <= pond_row){
                int hak = 0;
                for(int x = i; x < i + net_col; x++){
                    for(int y = j; y < j + net_row; y++){
                        hak += data[x][y];
                    }
                }

                if(maxium < hak){
                    maxium = hak;
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("\n%d\n", maxium);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
