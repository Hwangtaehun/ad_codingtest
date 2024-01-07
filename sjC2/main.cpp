#include <cstdio>

int data[9][9];
int m, mi, mj;

void Input(){
    freopen("input.txt", "r", stdin);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Compare(){
    m = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(m < data[i][j]){
                m = data[i][j];
                mi = i;
                mj = j;
            }
        }
    }
}

int Maximum(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(m < data[i][j]){
                m = data[i][j];
                mi = i + 1;
                mj = j + 1;
            }
        }
    }
}

int Maximum2(){
    mi = mj = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(data[mi][mj] < data[i][j]){
                mi = i;
                mj = j;
            }
        }
    }
}

void Output(){
    mi++;
    mj++;
    freopen("output.txt", "w", stdout);
    printf("%d", m);
    printf("\n");
    printf("%d %d", mi, mj);
}

int main()
{
    Input();
    Maximum();
    printf("%d\n%d %d\n", m, mi, mj);
    Maximum2();
    printf("%d\n%d %d\n", data[mi][mj], mi + 1, mj + 1);
    //Compare();
    //Output();
    return 0;
}
