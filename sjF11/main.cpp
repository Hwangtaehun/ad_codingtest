#include <cstdio>

int row, mok, result, memory[100001];

//solve
int m, n, DT[100001];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    fclose(stdin);
}

int f1(int m){
    if(m == 1){
        return DT[m] = 1 % n;
    }else if(m == 2){
        return DT[m] = 3 % n;
    }else{
        if(DT[m] == 0){
            DT[m] = (f1(m - 1) + 2 * f1(m - 2)) % n;
        }
        return DT[m];
    }
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
    Input();
    printf("%d\n", f1(m));
    return 0;
}
