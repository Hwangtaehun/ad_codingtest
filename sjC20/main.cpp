#include <cstdio>

int data[11][11] = {0,};
int row, col;

//solve
int H, W, wayCnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &H, &W);
    fclose(stdin);
}

void ArrayPrn(){
    int i, j;
    for(i = 0; i <= H; i++){
        for(j = 0; j <= W; j++){
            printf("%d, %d, %lf", i, j, (double)i/(j+1));
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Solve2(){
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 && j == 0){
                data[i][j] = 1;
            }
            else{
                if(i * W >= j * H && j > 0){
                    data[i][j] += data[i][j - 1];
                }
                if((i-1) * W >= j * H && i > 0){
                    data[i][j] += data[i - 1][j];
                }
            }
        }
    }
}

void Solve1(int h, int w){
    if(h > H || w > W){
        return;
    }

    if(h == H && w == W){
        wayCnt++;
        return;
    }

    Solve1(h + 1, w);

    if((double)H/W <= (double)h/(w+1)){
        Solve1(h, w + 1);
    }
}

void In(){
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

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", data[col][row]);
    fclose(stdout);
}

int main()
{
    /*
    In();
    Path();
    Out();
    */
    Input();
    Solve1(0, 0);
    printf("%d\n", wayCnt);
    Solve2();
    ArrayPrn();
    printf("%d\n", data[H][W]);
    return 0;
}
