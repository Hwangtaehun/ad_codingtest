#include <stdio.h>

int data[30], result[30], cnt, number, re_sz;

//solve
int a[30];

void Solve(int n, int k){
    int min;

    if(n == 0){
        for(int i = 0; i < cnt; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    min = n < k ? n : k;

    for(int i = min; i >= 1; i--){
        a[cnt++] = i;
        Solve(n-i, i);
        cnt--;
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &number);
    fclose(stdin);
}

int minimum(int a, int b)
{
    return a > b ? b:a;
}

int Total(int n, int c){
    n = 10 * n + data[cnt - c];

    if(c == 1){
        return n;
    }

    return Total(n, c - 1);
}

void Partition(int num1, int num2)
{
    if(num1==0)
    {
        result[re_sz] = Total(0, cnt);
        re_sz++;
        return;
    }

    for(int i = minimum( num1 , num2 ); i >= 1; i--)
    {
        data[cnt++]=i;
        Partition(num1 - i, i);
        cnt--;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < re_sz; i++){
        char str[number];
        int j = 0;
        sprintf(str, "%d", result[i]);
        while(str[j] != '\0'){
            printf("%c ", str[j]);
            j++;
        }
        printf("\n");
    }

    fclose(stdout);
}

int main()
{
    int n;
    scanf("%d", &n);
    Solve(n, n);
    /*
    In();
    Partition(number, number);
    Out();
    */
    return 0;
}
