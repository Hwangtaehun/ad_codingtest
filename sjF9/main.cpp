#include <cstdio>
#define MOK 1000000003

int data[1001][2], visited[1001], color, choose, result = 0;
bool possible[1001];

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d\n%d", &color, &choose);
    fclose(stdin);

    for(int i = 1; i <= color; i++){
        if(i == 1){
            data[1][0] = 4;
            data[1][1] = 2;
        }
        else if(i == color){
            data[color][0] = 3;
            data[color][1] = 1;
        }
        else{
            data[i][0] = i - 1;
            data[i][1] = i + 1;
        }
    }
}

void Initalize(){
    for(int i = 1; i <= color; i++){
        visited[i] = 0;
    }
}

void Print(int choice){
    for(int i = 1; i <= color; i++){
        printf("%d: visited[%d] = %d\n", choice, i, visited[i]);
    }
    for(int i = 1; i <= color; i++){
        printf("%d: possible[%d] = %d\n", choice, i, possible[i]);
    }
}

void Visit(bool sw){
    if(sw){
        for(int i = 1; i <= color; i++){
            if(visited[i] != 0){
                possible[i] = 1;
                possible[data[i][0]] = 1;
                possible[data[i][1]] = 1;
            }
        }
    }
    else{
        for(int i = 1; i <= color; i++){
            possible[i] = 0;
        }
    }

}

void Contrast(int choice, int cnt){
    //printf("cnt = %d\n", cnt);
    //Print(choice);

    if(cnt == choose){
        //printf("choice = %d, cnt = %d\n", choice, cnt);
        result++;
        return;
    }
    else if(cnt > choose){
        return;
    }

    for(int i = 1; i <= color; i++){
        if(possible[i] == 0){
            //printf("contract %d\n", i);
            visited[i] = 1;
            Visit(true);
            Contrast(i, ++cnt);
            visited[i] = 0;
            Visit(false);
        }
    }
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

int main()
{
    In();

    if(color / 2 < choose){
        result = 0;
    }else{
        for(int i = 1; i <= color; i++){
            //printf("i = %d\n", i);
            visited[i] = 1;
            Contrast(i, 1);
            Initalize();
        }
    }
    result /= 2;
    result = result % MOK;

    Out();

    return 0;
}
