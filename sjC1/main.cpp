#include <cstdio>

int yaksu [100000];
int size = 0;
int num;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &num);
}

void Yaksu(){
    int i = num;
    while(i != 0){
        if(num%i == 0){
            yaksu[size] = i;
            size++;
        }
        i--;
    }
}

void Hak(){
    int result = 0;
    for(int i = 0; i < size; i++){
        result += yaksu[i];
    }
    printf("%d", result);
}

int main()
{
    Input();
    Yaksu();
    Hak();
    return 0;
}
