#include <cstdio>

int choo[7] = {1, 3, 9, 27, 81, 243, 729};
int chk[7], data[9], weight, endsw, sz;

//solve
int scale[7] = {1, 3, 9, 27, 81, 243, 729};
int outScale[9], three[7], n, x;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    fclose(stdin);
}

void ArrayPrn(){
    for(int i = 6; i >= 0; i--){
        printf("%d ", three[i]);
    }
    printf("\n");
}

void toThree(int num){
    printf(" %d \t", num);
    for(int i = 0; num != 0; i++){
        three[i] = num % 3;
        num /= 3;
    }
    ArrayPrn();
}

bool isTwo(){
    for(int i = 0; i < 7; i++){
        if(three[i] == 2){
            n = n + scale[i];
            outScale[x++] =  scale[i];
            return true;
        }
    }
    return false;
}

void Solve(){
    outScale[x++] = n;

    do{
        toThree(n);
    }while(isTwo());

    x++;

    for(int i = 0; i < 7; i++){
        if(three[i] == 1){
            outScale[x++] = scale[i];
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < x; i++){
        printf("%d ", outScale[i]);
    }
    fclose(stdout);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &weight);
    fclose(stdin);
}

void Balance(int num, int sum){
    if(endsw){
        return;
    }
    if(num == sum){
        data[sz] = weight;
        endsw = sz = 1;
        for(int j = 2; j > 0; j--){//여기부분 빼지말기
            for(int i = 0; i < 7; i++){
                if(chk[i] == j){
                    data[sz] = choo[i];
                    sz++;
                }
            }
            if(j == 2){
                data[sz] = 0;
                sz++;
            }
        }
        return;
    }
    for(int i = 0; i < 7; i++){
        if(chk[i] == 0){//여기부분 빼지말기
            chk[i] = 1;
            Balance(num, sum+choo[i]);
            chk[i] = 2;
            Balance(num+choo[i], sum);
            chk[i] = 0;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < sz; i++){
        printf("%d ", data[i]);
    }
    fclose(stdout);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
