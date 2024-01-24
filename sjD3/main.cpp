#include <cstdio>

char data[6];
int sz, nsz, num_data[720];

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
    scanf("%s", &data);
    fclose(stdin);

    for(int i = 0; i < 6; i++){
        if(data[i] == '\0'){
            sz = i;
            break;
        }
    }

    nsz = Factorial(sz);
}

int main()
{
    printf("sz = %d, nsz = %d", sz, nsz);
    return 0;
}
