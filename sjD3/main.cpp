#include <cstdio>

char data[6];
int sz, nsz, num_data[720];

void Print(){
    for(int i = 0; i < sz; i++){
        printf("%c ", data[i]);
    }
    printf("\n");
}

bool Sosu(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int Factorial(int num){
    if(num == 1){
        return 1;
    }
    return num * Factorial(num-1);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%s", data);
    fclose(stdin);

    for(int i = 0; i < 6; i++){
        if(data[i] == '\0'){
            sz = i;
            break;
        }
    }

    for(int i = 0; i < sz - 1; i++){
        for(int j = i; j < sz; j++){
            if(data[j] < data[i]){
                char temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void Kind(){
    int du1 = 1, du2 = 1, du3 = 1, j = 0, temp;

    for(int i = j + 1; i < sz; i++){
        if(data[j] == data[i]){
            du1++;
            temp = i;
        }
    }

    j = temp + 1;

    for(int i = j + 1; i < sz; i++){
        if(data[j] == data[i]){
            du2++;
            temp = i;
        }
    }

    j = temp + 1;

    for(int i = j + 1; i < sz; i++){
        if(data[j] == data[i]){
            du3++;
            temp = i;
        }
    }

    nsz = Factorial(sz) / Factorial(du1) / Factorial(du2) / Factorial(du3);
}

void Combination(int n, int len){
}

int main()
{
    Input();
    Kind();
    return 0;
}
