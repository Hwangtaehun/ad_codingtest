#include <cstdio>
#include <algorithm>

bool chk[501];
int data_s[501][2];
int line, rm_line = 0;

//solve
struct DATA{
    int a;
    int b;
}data[101];
int n;

bool AscData(DATA left, DATA right){
    return left.a < right.a;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &data[i].a, &data[i].b);
    }
}

int Solve(int k){
    int i, cnt = 1, cnt2;

    for(i = k - 1; i >= 1; i--){
        if(data[k].b > data[i].b){
            cnt2 = Solve(i) + 1;
            if(cnt < cnt2){
                cnt = cnt2;
            }
        }
    }

    return cnt;
}

int Solve2(int k){
    int i, cnt = 1, cnt2;
    for(i = k + 1; i <= n; i++){
        if(data[k].b < data[i].b){
            cnt2 = Solve2(i) + 1;
            if(cnt < cnt2){
                cnt = cnt2;
            }
        }
    }

    return cnt;
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &line);
    for(int i = 1; i <= line; i++){
        scanf("%d %d", &data_s[i][0], &data_s[i][1]);
    }
    fclose(stdin);
}

void Print(){
    for(int i = 1; i <=line; i++){
        printf("%d %d\n", data_s[i][0], data_s[i][1]);
    }
    printf("\n");
}

void Sort(){
    for(int i = 1; i <= line-1; i++){
        for(int j = i; j <= line; j++){
            if(data_s[i][0] > data_s[j][0]){
                int temp1 = data_s[i][0];
                int temp2 = data_s[i][1];
                data_s[i][0] = data_s[j][0];
                data_s[i][1] = data_s[j][1];
                data_s[j][0] = temp1;
                data_s[j][1] = temp2;
            }
        }
    }
}

void Eleicline(){
    Sort();

    for(int i = 1; i <= line; i++){
        if(data_s[i][0] < data_s[i][1]){
            chk[i] = true;
        }
    }

    for(int i = 1; i <= line; i++){
        if(!chk[i]){
            for(int j = 1; j <= i; j++){
                if(!chk[j]){
                    if(data_s[i][1] < data_s[j][1]){
                        chk[i] = true;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= line; i++){
        if(chk[i]){
            rm_line++;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", rm_line);
    fclose(stdout);
}

int main()
{
    //In();
    //Eleicline();
    //Output();
    int i, cnt = 0, cnt2;
    Input();
    std::sort(data+1, data+n+1, AscData);

    for(i =  1; i <= n; i++){
        cnt2 = Solve(i);
        if(cnt < cnt2){
            cnt = cnt2;
        }
    }
    //printf("%d\n", n - cnt);
    rm_line = n - cnt;
    Output();
    return 0;
}
