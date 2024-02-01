#include <cstdio>

int data[2][100000], sz, rest, kind, endsw;

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &sz, &rest);
    fclose(stdin);
}

void Fill(int start){
    if(endsw){
        return;
    }

    if(start == sz){
        kind++;
        endsw = 1;
        return;
    }
    else if(start == sz - 1){
        data[start][0] = data[start][1] = 1;
        Fill(start + 1);
    }
    else if(start > sz){
        endsw = 1;
        return;
    }

    data[start][0] = data[start][1] = 1;
    Fill(start + 1);
    data[start][0] = data[start][1] = 0;

    data[start][0] = data[start][1] = 2;
    data[start + 1][0] = data[start + 1][1] = 2;
    Fill(start + 2);
    data[start][0] = data[start][1] = 0;
    data[start + 1][0] = data[start + 1][1] = 0;

    data[start][0] = data[start][1] = 3;
    data[start + 1][0] = data[start + 1][1] = 3;
    Fill(start + 2);
}

int main()
{
    In();
    printf("%d %d", sz, rest);
    Fill(0);
    printf("kind = %d\n", kind);
    return 0;
}
