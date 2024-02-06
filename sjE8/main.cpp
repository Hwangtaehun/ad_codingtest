#include <cstdio>
#include <queue>

using namespace std;

char data[1<<19];
int sz, result[18];

//solve
char sa[1<<19], sb[1<<19], sc[1<<19];
int n, p, i = 1;
queue <char> q;

void Solve1(int k, int s){
    char val = sa[p++];

    /*
    printf("%d¹øÂ° k = %d, s = %d\n", i, k, s);
    i++;
    */

    if(val == NULL)
        return;

    if(val == '-'){
        Solve1(k, s/2);
        Solve1(k+s/2, s/2);
    }else{
        for(int i = k; i < k + s; i++){
            sb[i] = val;
        }
    }
}

void Solve2(int k, int s, char v){
    printf("s = %d\n", s);

    if(q.empty())
        return;

    if(v == '-'){
        q.pop();
        Solve2(k, s/2, q.front());
        q.pop();
        Solve2(k + s/2, s/2, q.front());
    }else{
        for(int i = k; i < k + s; i++){
            sc[i] = v;
        }
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    scanf("%s", data);
    fclose(stdin);
}

void Out(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < sz; i++){
        printf("%d", result[i]);
    }
    fclose(stdout);
}

void Print(){
    int i = 0;

    while(1){
        if(data[i] == '\0'){
            break;
        }

        printf("%c", data[i]);
        i++;
    }
}

void Decoding(){
    int sp = sz, i = 0, j = 0;

    while(1){
        if(data[i] == '\0'){
            break;
        }

        if(data[i] == '-'){
            if(sp > 2){
                sp /= 2;
            }
            i++;
        }else{
            if(data[i+1] == '-' || data[i+1] == '\0'){
                int cnt = 0;
                while(cnt < sp){
                    result[j] = data[i] - '0';
                    j++;
                    cnt++;
                }
                i++;
            }else{
                result[j] = data[i] - '0';
                j++;
                i++;
            }
        }
    }
}

int main()
{
    scanf("%d %s", &n, sa);
    Solve1(0, n);
    printf("%s\n", sb);

    for(int i = 0; sa[i]; i++){
        q.push(sa[i]);
    }
    Solve2(0, n, q.front());
    printf("%s", sc);
    //In();
    //Decoding();
    //Out();
    return 0;
}
