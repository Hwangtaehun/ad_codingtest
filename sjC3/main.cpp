#include <cstdio>

int round;
int kind;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &round);
}

void Triangle(){
    int big;
    int middle;
    int small;
    for(int i = round/3; i < round; i++){
        big = i;
        int other = round - i;
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
    Triangle();
    Output();
    return 0;
}
