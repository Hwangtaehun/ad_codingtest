#include <cstdio>

int array_size, data[100000], memory[100000], maximum = 0;

int Max(int a, int b){
    return a < b ? b : a;
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
    int cnt = 0;

    In();
    while(cnt != 7){
        Find(cnt);
        cnt++;
    }
    Out();

    return 0;
}
