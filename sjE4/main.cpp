#include <cstdio>

int sz, rest, kind;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &sz, &rest);
    fclose(stdin);
}

int Fill(int num){
    if(num > 2){
        return Fill(num-1) + 2 * Fill(num-2);
    }
    else if(num == 2){
        return 3;
    }
    else if(num == 1){
        return 1;
    }

    return 0;
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", kind % rest);
    fclose(stdout);
}

int main()
{
    In();
    kind = Fill(sz);
    Out();
    return 0;
}
