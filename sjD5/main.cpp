#include <cstdio>

int length, cnt;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &length);
    fclose(stdin);
}

void Triangle(){
    for(int a = 1; a <= length; a++){
        for(int b = a; b <= length; b++){
            for(int c = b; c <= length; c++){
                if(a + b + c == length && c < a + b){
                    printf("%d %d %d\n", a, b, c);
                    cnt++;
                }
            }
        }
    }
}

void Solve(){
    int a, b, c;

    for(c = length / 3; c <= length / 2; c++){
        for(a = 1; a <= length / 3; a++){
            b = length - (a + c);

            if(c < a + b && (a <= b && b <= c)){
                printf("%d %d %d\n", a, b, c);
                cnt++;
            }
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

int main()
{
    In();
    Solve();
    Out();
    return 0;
}
