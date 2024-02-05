#include <cstdio>

char data[6], result[6];
int last;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%s", data);
    fclose(stdin);

    for(int i = 0; i < 6; i++){
        if(data[i] == '\0'){
            last = i;
            break;
        }
    }
}

void Reverse(){
}

int main()
{
    sprintf("")
    return 0;
}
