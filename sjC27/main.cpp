#include <cstdio>

int n, cases;
int p[500], d[500], g[500];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &p[i], &d[i], &g[i]);
    }
    fclose(stdin);
}

bool isGo(int a, int k){
    return p[k] <= p[a] + d[a];
}

bool isBack(int b, int k){
    return (p[k] <= p[b] + d[k]) && g[k];
}

int Solve(int a, int b, int k){
    int c = 0;

    if(k == n-1){
        if(isGo(a, k) && isBack(b, k)){
            c = 1;
        }else{
            c = 0;
        }
    }else{
        if(isGo(a,k)){
            c += Solve(k, b, k + 1);
        }

        if(isBack(b,k)){
            c += Solve(a, k, k + 1);
        }

        c += Solve(a, b, k + 1);
    }

    return c;
}

void Output(){
    int in = cases % 1000;
    freopen("output.txt", "w", stdout);
    printf("%d", in);
    fclose(stdout);
}

int main(){
    Input();
    cases = Solve(0, 0, 1);
    Output();
    return 0;
}
