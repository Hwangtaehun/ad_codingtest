#include <stdio.h>
#include <stdlib.h>

int station[11], cars[10], st, ca, line = 0;
bool stchk[11];

//solve
int pCnt, fCnt, pump[100001], fire[100000], pv[100001], mh = 0x7fffffff;

void Input(){
    int i;
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &pCnt, &fCnt);
    for(i = 1; i <= pCnt; i++){
        scanf("%d", &pump[i]);
    }
    for(i = 1; i <= fCnt; i++){
        scanf("%d", &fire[i]);
    }
    fclose(stdin);
}

int abs(int a){
    return a > 0 ? a: -a;
}

void Solve(int p, int f, int h){
    if(f == fCnt){
        mh = (mh > h) ? h : mh;
        return;
    }

    for(int i = 1; i <= pCnt; i++){
        if(pv[i] == 0){
            pv[i] = 1;
            h += abs(pump[i]-fire[f+1]);
            Solve(i, f+1, h);
            h -= abs(pump[i]-fire[f+1]);
            pv[i] = 0;
        }
    }
}

void Output(){
    printf("%d\n", mh);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &st, &ca);
    for(int i = 0; i < st; i++){
        scanf("%d", &station[i]);
    }
    for(int i = 0; i < ca; i++){
        scanf("%d", &cars[i]);
    }
    fclose(stdin);
}

void Solution(){
    for(int i = 0; i < ca; i++){
        int car = cars[i];
        int small = 0x7fffffff;
        int index = 99;

        for(int j = 0; j < st; j++){
            if(!stchk[j]){
                int diff = station[j] - car;
                diff = abs(diff);

                if(diff < small){
                    index = j;
                    small = diff;
                }
            }
        }
        stchk[index] = true;
        line += small;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", line);
    fclose(stdout);
}

int main()
{
    //In();
    //Solution();
    //Out();
    Input();
    Solve(0,0,0);
    Output();
    return 0;
}
