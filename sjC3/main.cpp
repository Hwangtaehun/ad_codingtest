#include <cstdio>

int n;
int kind;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
}

int Solve(){
    int cnt = 0;

    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            for(int c = b; c <= n; c++){
                if(a+b+c == n && c < a + b){
                    printf("%d %d %d\n", a, b, c);
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int Solve2(){
    int c, cnt = 0;
    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            c = n - (a + b);

            if(c < a + b && (b <= c)){
                printf("%d %d %d\n", a, b, c);
                cnt++;
            }
        }
    }

    return cnt;
}

void Triangle(){
    int big;
    int middle;
    int small;
    for(int i = n/3; i < n; i++){
        big = i;
        int other = n - i;
        if(other/2 > 0){
            for(int j =  1; j < other; j++){
                middle = j;
                small = other - j;
                if(middle <= big){
                    if(small <= middle){
                        if(big < middle +  small){
                            kind++;
                        }
                    }
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", kind);
}

int main()
{
    Input();
    printf("%d\n", Solve());
    printf("%d\n", Solve2());
    //Triangle();
    //Output();
    return 0;
}
