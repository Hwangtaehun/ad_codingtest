#include <cstdio>

int data[501][2];
int line;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &line);
    for(int i = 1; i < line; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

int main()
{
    return 0;
}
