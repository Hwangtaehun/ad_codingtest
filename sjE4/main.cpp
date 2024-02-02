#include <cstdio>

int sz, rest, kind;
//solve
int n, m;

int Solve1(int k){
    if(k <= 1){
        return 1;
    }else{
        return (Solve1(k-1) + 2*Solve1(k-2));
    }
}

int Solve2(int k){
    if(k <= 1){
        return 1;
    }else{
        return (Solve2(k-1) + 2 * Solve2(k-2)) % m;
    }
}

int Solve3(int k){
    if(k <= 1){
        return 1;
    }else if(k % 2){
        return (Solve3(k-1) + 2 * Solve3(k-2)) % m;
    }else{
        return (Solve3(k/2) * Solve3(k/2) + 2 * Solve3(k/2-1) * Solve3(k/2-1)) % m;
    }
}

long long int Solve4(int k){
    if(k <= 1){
        return 1 % m;
    }else if(k % 2){
        return(Solve4(k/2) * Solve4(k/2+1) + 2 * Solve4(k/2) * Solve4(k/2-1)) % m;
    }else{
        return(Solve4(k/2) * Solve4(k/2) + 2 * Solve4(k/2-1) * Solve4(k/2-1)) % m;
    }
}

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
    scanf("%d %d", &n, &m);
    printf("%d\n", Solve1(n));
    printf("%d\n", Solve2(n));
    printf("%d\n", Solve3(n));
    printf("%d\n", Solve4(n));
    /*
    In();
    kind = Fill(sz);
    Out();
    */
    return 0;
}
