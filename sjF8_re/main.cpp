#include <stdio.h>

int k;
char str, strvalue[30], data[300], tree[1500000];

void print(){
    for(int i = 0; i < 300; i++){
        if(data[i] == '\0'){
            break;
        }

        printf("%c", data[i]);
    }
    printf("\n");
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%c %s", &str, strvalue);

        for(int idx = 0; strvalue[idx] != '\0'; idx++){
            if(strvalue[idx] == '0'){
                idx = idx * 2;
            }else{
                idx = idx * 2 + 1;
            }
            tree[idx] = str;
        }
    }
    fclose(stdin);
}

int main(){
    int idx = 1;
    scanf("%s", data);
    In();
    //print();

    for(int i = 0; i < 300; i++){
        if(data[i] == '\0'){
            break;
        }
        printf("%c", data[i]);
    }
    printf("\n");

    for(int i = 0; data[i] != '\0'; i++){
        if(data[i] == '0'){
            idx = 2 * idx;
        }else{
            idx = 2 * idx + 1;
        }

        if(tree[idx] != 0){
            printf("%c", tree[idx]);
            idx = 1;
        }
    }

    return 0;
}
