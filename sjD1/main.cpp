#include <cstdio>

int number, sum;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &number);
    fclose(stdin);
}

void Yaksu(){
    for(int i = 1; i <= number; i++){
        if(number % i == 0){
            sum += i;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", sum);
    fclose(stdout);
}

int main()
{
    Input();
    Yaksu();
    Output();
    return 0;
}
