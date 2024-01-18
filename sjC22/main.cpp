#include <cstdio>
#include <algorithm>

bool chk[501];
int data[501][2];
int line, rm_line = 0;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &line);
    for(int i = 1; i <= line; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Print(){
    for(int i = 1; i <=line; i++){
        printf("%d %d\n", data[i][0], data[i][1]);
    }
    printf("\n");
}

void Sort(){
    for(int i = 1; i <= line-1; i++){
        for(int j = i; j <= line; j++){
            if(data[i][0] > data[j][0]){
                int temp1 = data[i][0];
                int temp2 = data[i][1];
                data[i][0] = data[j][0];
                data[i][1] = data[j][1];
                data[j][0] = temp1;
                data[j][1] = temp2;
            }
        }
    }
}

void Eleicline(){
    Sort();

    for(int i = 1; i <= line; i++){
        if(data[i][0] < data[i][1]){
            chk[i] = true;
        }
    }

    for(int i = 1; i <= line; i++){
        if(!chk[i]){
            for(int j = 1; j <= i; j++){
                if(!chk[j]){
                    if(data[i][1] < data[j][1]){
                        chk[i] = true;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= line; i++){
        if(chk[i]){
            rm_line++;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", rm_line);
    fclose(stdout);
}

int main()
{
    In();
    Eleicline();
    Out();
    return 0;
}
