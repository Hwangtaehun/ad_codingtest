#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int size;
int data[1000000];
int key;

void read(){
    FILE* inf;

    if((inf = fopen("input.txt", "r")) == 0){
        printf("read file open fail\n");
        exit(0);
    }

    fscanf(inf, "%d\n", &size);
    for(int i = 0; i < size; i++){
        fscanf(inf, "%d ", &data[i]);
    }
    fscanf(inf, "\n%d", &key);

    fclose(inf);
}

void write(){
    FILE* outf;

    if((outf = fopen("output.txt", "w")) == 0){
        printf("write file open fail\n");
        exit(0);
    }

    fprintf(outf, "\n%d\n", key);

    fclose(outf);
}


void upper(){
    int i = 0;

    while(1)
    {
        if(size <= i){
            key = i + 1;
            break;
        }
        if(data[i] > key){
            key = i + 1;
            break;
        }
        i++;
    }
}

void input(){
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        scanf("%d ", &data[i]);
    }
    printf("\n");
    scanf("%d", &key);
}

void print(){
    printf("\n%d\n", key);
}

int main()
{
    read();
    upper();
    write();
    return 0;
}
