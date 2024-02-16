#include <cstdio>
#include <math.h>

char data[5], result[5];
int sz = 5;

//solve
int DT[50001];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%s", data);
    fclose(stdin);

    for(int i = 0; i < 5; i++){
        if(data[i] == '\0'){
            sz = i;
            break;
        }
    }
}

void Reverse(){
    int cnt = 0;
    bool start = false;

    for(int i = sz-1; i >= 0; i--){
        if(data[i] != '0' || start){
            start = true;
            result[cnt] = data[i];
            cnt++;
        }
    }

    cnt++;
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%s", result);
    fclose(stdout);
}

void f1(int n){
    int i;

    for(i = 1; i <= n; i++){
        if(i < 10){
            DT[i] = i;
        }
        else{
            DT[i] = DT[i/10] + DT[i%10]*(int)pow(10, (int)log10(i));
        }
    }
}

int main()
{
    /*In();
    Reverse();
    Out();*/
    int n;
    scanf("%d", &n);
    f1(n);
    printf("%d\n", DT[n]);
    return 0;
}
