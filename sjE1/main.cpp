#include <cstdio>
#include <ctime>

char data[6], result[6];
int re_size;
bool bFirst = false;

void Solve1(int n){
    if(n == 0){
        return;
    }
    printf("%d", n%10);
    Solve1(n/10);
}

void Solve2(int n){
    if(n == 0){
        return;
    }

    if(bFirst || (n % 10) != 0){
        printf("%d", n%10);
        bFirst = true;
    }

    Solve2(n/10);
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%s", data);
    fclose(stdin);
}

void Print(){
    int n = 0;
    for(int i = 0; i < 5; i++){
        if(data[i] == '\0'){
            break;
        }
        else if(data[i] == '0'){
            n++;
        }
        printf("%c", data[i]);
    }
    printf("\nn = %d\n", n);
}

void Reverse(){
    int m_size, n = 0;

    for(int i = 0; i < 6; i++){
        if(data[i] == '\0'){
            m_size = i - 1;
            break;
        }
    }

    for(int i = m_size; i >= 0; i--){
        if(data[i] != '0'){
            result[n] = data[i];
            n++;
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 5; i++){
        if(result[i] == '\0')
            break;
        printf("%c", result[i]);
    }
    fclose(stdout);
}

int main()
{
    int n;
    scanf("%d", &n);
    Solve1(n);
    printf("\n");
    Solve2(n);
    /*In();
    Reverse();
    Out();*/
    return 0;
}
