#include <cstdio>
#include <algorithm>

using namespace std;

int len, num[6], data[1000], dCnt;

void ArrayPrn(){
    for(int i = 0; i < 6; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}

void ArrayPrn2(){
    for(int i = 0; i < dCnt; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

bool IsPrime(int k){
    for(int i = 2; i*i <=k; i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

void Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int SplitNumber(int n){
    int i = 0;

    while(n != 0){
        num[i] = n % 10;
        n /= 10;
        i++;
    }

    return i;
}

void Permutation(int n, int len){
    int i, k = 0, weight = 1;

    if(n == 0){
        for(i = 0; i <= len; i++){
            k += num[i] * weight;
            weight *= 10;
        }
        ArrayPrn();
        data[dCnt++] = k;
        return;
    }
    for(i = n - 1; i >= 0; i--){
        Swap(&num[i], &num[n-1]);
        printf("i=%d, %d\n", i, n-1);
        Permutation(n-1, len);
        Swap(&num[i], &num[n-1]);
    }
}

void Input(){
    int n;

    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    fclose(stdin);

    len = SplitNumber(n);
}

void Output(){
    int prev = -1;

    freopen("output.txt", "w", stdout);
    for(int i = 0; i < dCnt; i++){
        if(IsPrime(data[i]) && prev != data[i]){
            printf("%d ", data[i]);
            prev = data[i];
        }
    }

    if(prev == -1){
        printf("0");
    }

    fclose(stdout);
}

int main(){
    Input();
    Permutation(len, len);
    ArrayPrn2();
    std::sort(data, data+dCnt);
    ArrayPrn2();
    Output();
    return 0;
}
