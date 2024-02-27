#include <cstdio>
#define INF 987654321

int array_size, data[100000], memory[100000], maximum = 0;

//solve
int S[100000], DT[100000], n, ans = -INF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", S+i);
    }
    fclose(stdin);
}

int Max(int a, int b){
    return a < b ? b : a;
}

int f1(int k){
    if(k == 0){
        return S[0];
    }else{
        return Max(f1(k-1) + S[k], S[k]);
    }
}

int f2(int k){
    if(k == 0){
        return DT[k] = S[0];
    }
    else if(!DT[k]){
        DT[k] = Max(f2(k - 1) + S[k], S[k]);
    }

    return DT[k];
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &array_size);
    for(int i = 0; i < array_size; i++){
        scanf("%d", &data[i]);
    }
    fclose(stdin);
}

int Sum(int start, int scale){
    int rs = 0;

    for(int i = start; i <= start + scale; i++){
        rs += data[i];
    }

    return rs;
}

void Find(int scale){

    if(scale == array_size){
        for(int i = 0; i < array_size; i++){
            if(memory[i] > maximum){
                maximum = memory[i];
            }
        }
    }

    for(int i = 0; i < array_size - scale; i++){
        if(!memory[i]){
            memory[i] = data[i];
        }else{
            memory[i] = Max(memory[i], Sum(i, scale));
        }
    }
}

void Print(int cnt){
    for(int i = 0; i < array_size; i++){
        printf("cnt = %d, memory[%d] = %d\n", cnt, i, memory[i]);
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", maximum);
    fclose(stdout);
}

int main()
{
    /*
    int cnt = 0;

    In();
    while(cnt != 7){
        Find(cnt);
        cnt++;
    }
    Out();
    */
    Input();

    for(int i = 0; i < n; i++){
        ans = Max(ans, f1(i));
    }

    printf("%d\n", ans);

    ans = -INF;

    for(int i = 0; i < n; i++){
        ans = Max(ans, f2(i));
    }

    printf("%d\n", ans);

    return 0;
}
