#include <cstdio>

int data[128][128], sz, w, b;
//solve
int s[1<<7][1<<7], n, gray, white;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &s[i][j]);
        }
    }
    fclose(stdin);
}

void Solve(int a, int b, int n){
    bool isOne = true;
    for(int i = a; i < a + n; i++){
        for(int j = b; j < b + n; j++){
            if(s[a][b] != s[i][j])
                isOne = false;
        }
    }

    if(isOne){
        if(s[a][b] == 1)
            gray++;
        else
            white++;
        return;
    }
    else{
        Solve(a, b, n/2);
        Solve(a + n/2, b, n/2);
        Solve(a, b + n/2, n/2);
        Solve(a + n/2, b + n/2, n/2);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Print(){
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Fill(int sp){
    int re = (sz / sp) * (sz / sp), a = 0, col = 0, row = 0;

    while(a != re){
        int bk = 0;

        for(int i = col; i < col + sp; i++){
            for(int j = row ; j < row + sp; j++){
                if(data[i][j] != 1){
                    bk = 1;
                    break;
                }
            }
        }

        if(!bk){
            for(int i = col; i < col + sp; i++){
                for(int j = row ; j < row + sp; j++){
                    data[i][j] = sp;
                }
            }
        }

        row += sp;

        a++;
        if(a % (sz / sp) == 0){
            col += sp;
            row = 0;
        }
    }

    a = 0, col = 0, row = 0;

    while(a != re){
        int bk = 0;
        for(int i = col; i < col + sp; i++){
            for(int j = row ; j < row + sp; j++){
                if(data[i][j] != 0){
                    bk = 1;
                    break;
                }
            }
        }

        if(!bk){
            for(int i = col; i < col + sp; i++){
                for(int j = row ; j < row + sp; j++){
                    data[i][j] = -sp;
                }
            }
        }

        row += sp;

        a++;
        if(a % (sz / sp) == 0){
            col += sp;
            row = 0;
        }
    }
}

void Space(){
    int sp = sz / 2;

    while(sp != 1){
        Fill(sp);
        sp /= 2;
    }

    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            if(data[i][j] == 0){
                data[i][j] = -1;
            }
        }
    }

    sp = sz / 2;

    while(sp != 0){
        int cnt = 0;

        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                if(data[i][j] == sp){
                    cnt++;
                }
            }
        }

        b += (cnt / sp / sp);
        sp /= 2;
    }

    sp = sz / 2;

    while(sp != 0){
        int cnt = 0;

        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                if(data[i][j] == -sp){
                    cnt++;
                }
            }
        }

        w += (cnt / sp / sp);
        sp /= 2;
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d\n%d", w, b);
    fclose(stdout);
}

int main()
{
    Input();
    Solve(0, 0, n);
    printf("%d\n%d\n", white, gray);
    /*
    In();
    Space();
    Out();
    */
    return 0;
}
