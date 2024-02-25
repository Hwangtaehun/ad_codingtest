#include <cstdio>

int row, mok, result, memory[100001];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d\n%d", &row, &mok);
    fclose(stdin);
}

void Fill(int num){
    if(num == 1){
        memory[num] = 1;
    }
    else if(num == 2){
        memory[num] = 3;
    }
    else{
        memory[num] = memory[num-1] + 2 * memory[num - 2];
    }

}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

int main()
{
    In();
    for(int i = 1; i <= row; i++){
        Fill(i);
    }
    result = memory[row] % mok;
    Out();
    return 0;
}
