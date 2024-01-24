#include <cstdio>

int number, sz = 0;
int all[100000];

bool Sosu(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &number);
    fclose(stdin);

    for(int i = 2; i <= 100000; i++){
        if(Sosu(i)){
            all[sz] = i;
            sz++;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", all[number-1]);
    fclose(stdout);
}

int main()
{
    Input();
    Output();
    return 0;
}
