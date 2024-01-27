#include <cstdio>

int data[11][11], node, total, minium = 0x0fffffff, visited[11];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &node, &total);
    for(int i = 0; i < total; i++){
        int s, e, p;
        scanf("%d %d %d", &s, &e, &p);
        data[s][e] = data[e][s] = p;
    }
    fclose(stdin);
}

void Print(){
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 7; j++){
            printf("%3d ", data[i][j]);
        }
        printf("\n");
    }
}

void Path(int n, int sum){
    if(sum > minium){
        return;
    }
    if(n == node){
        if(sum < minium){
            minium = sum;
        }
        //printf("%d\n", minium);
    }

    for(int i = 1; i <= node; i++){
        if(!visited[i] && data[n][i]){
            visited[i] = 1;
            Path(i, sum+data[n][i]);
            visited[i] = 0;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", minium);
    fclose(stdout);
}

int main(){
    In();
    //Print();
    Path(1, 0);
    Out();
    return 0;
}
