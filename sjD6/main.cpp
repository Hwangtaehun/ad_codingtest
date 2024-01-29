#include <cstdio>

int data[11][11], node, total, minium = 0x0fffffff, visited[11];

//solve
int n, m, wmin = 0x7fffffff, debugCnt;

void Input(){
    int s, e, w;

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &s, &e, &w);
        data[s][e] = data[e][s] = w;
    }
    fclose(stdin);
}

void ArrayPrn(int w){
    printf("\t");
    for(int i = 1; i <= n; i++){
        printf("%d ", visited[i]);
    }
    printf(" %5d\n", w);
}

void Solve(int v, int w){
    if(w > wmin){
        return;
    }
    debugCnt++;

    if(v == n){
        if(w < wmin){
            wmin = w;
        }
        ArrayPrn(w);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i] && data[v][i]){
            visited[i] = 1;
            printf("%d,%d ", v, i);
            Solve(i, w + data[v][i]);
            visited[i] = 0;
        }
    }
}

int Greedy(int v){
    int i, t, sol = 0;

    while(v != n){
        int min = 0x7fffffff;

        for(i = v; i <= n; i++){
            if(data[v][i] && data[v][i] < min){
                min = data[v][i];
                t = i;
                printf("%d,%d,%d\t", v, i, min);
            }
        }

        sol += data[v][t];
        v = t;
    }
    return sol;
}

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
    //In();
    //Print();
    //Path(1, 0);
    //Out();
    Input();
    visited[1] = 1;

    wmin = Greedy(1);

    printf("\n wmin = %d\n", wmin);

    Solve(1, 0);
    printf("\n%d\n", (wmin == 0x7fffffff) ? -1 : wmin);
    printf("debugCnt = %d\n", debugCnt);
    return 0;
}
