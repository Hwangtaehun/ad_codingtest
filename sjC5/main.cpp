#include <cstdio>

int data[100][100];
int pond_col, pond_row, net_col, net_row, maxium; //pond_col = N, pond_row = M, net_col = H, net_row = W

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &pond_col, &pond_row);
    scanf("%d %d", &net_col, &net_row);
    for(int i = 0; i < pond_col; i++){
        for(int j = 0; j < pond_row; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Fish(){
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

void Solve1(){
    int tot, maxTot = 0;

    for(int i = 0; i <= pond_col - net_row; i++){
        for(int j = 0; j <= pond_row - net_row; j++){
            tot = 0;
            for(int a = 0; a < net_col; a++){
                for(int b = 0; b < net_row; b++){
                    tot += data[i+a][j+b];
                    printf("%d,%d ", i + a, j + b);
                }
                printf("\n");

                if(tot > maxTot){
                    maxTot = tot;
                }
                printf("\n");
            }
        }
    }
    printf("%d", maxTot);
}

void Solve2(){
    int tot, maxTot = 0;

    for(int i = 0; i <= pond_col - net_row; i++){
        for(int j = 0; j <= pond_row - net_row; j++){
            tot = 0;
            for(int a = i; a < i + net_col; a++){
                for(int b = j; b < j + net_row; b++){
                    tot += data[a][b];
                    printf("%d,%d ", a, b);
                }
                printf("\n");

                if(tot > maxTot){
                    maxTot = tot;
                }
            }
            printf("%d\n", tot);
        }
    }
    printf("%d", maxTot);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("\n%d\n", maxium);
}

void Print(){
    for(int i = 0; i < pond_col; i++){
        for(int j = 0; j < pond_row; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Input();
    Print();
    Solve1();
    printf("\n");
    Solve2();
    //Fish();
    //Output();
    return 0;
}
