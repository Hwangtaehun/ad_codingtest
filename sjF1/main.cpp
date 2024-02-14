#include <cstdio>

char data[5], result[5];
int sz = 5;

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

int main()
{
    In();
    Reverse();
    Out();
    return 0;
}
