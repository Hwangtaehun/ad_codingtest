#include <cstdio>

char data[1<<19];
int sz, result[18];

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
    In();
    Decoding();
    Out();
    return 0;
}
