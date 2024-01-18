#include <cstdio>

using namespace std;

int s[81], n, endSw = 0;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    fclose(stdin);
}

bool isSame(int a, int b){
    int i;
    for(i = a; i < a + b; i++){
        if(s[i] != s[i+b]){
            return false;
        }
    }
    return true;
}

bool isGood1(int pos){
    for(int i = 1; i <= pos/2; i++){
        for(int j = 1; j <= pos - i; j++){
            printf("aa  %d %d\n", j, i);
            if(isSame(j, i))
                return false;
        }
    }
    return true;
}

bool isGood2(int pos){
    int i, j;
    for(j = pos - 1, i = 1; j >0; j -= 2, i++){
        if(isSame(j, i)){
            return false;
        }
    }
    return true;
}

void Solve(int pos){
    if(pos > n){
        endSw = 1;
        return;
    }

    for(int i = 1; i <= 3; i++){
        s[pos] = i;

        if(isGood2(pos)){
            Solve(pos + 1);
        }

        if(endSw == 1){
            return;
        }

        s[pos] = 0;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    for(int i = 1; i <= n; i++){
        printf("%d", s[i]);
    }
    fclose(stdout);
}

int main()
{
    In();
    Solve(1);
    Out();
    return 0;
}
