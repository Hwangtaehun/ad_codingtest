#include <cstdio>

int sz;
char data[18],result[18];

//solve
char str[1<<19];
int n;

void Solve(int k, int s){
    int sum = 0;

    if(s == 1){
        printf("%c", str[k]);
        return;
    }

    for(int i = k; i < k + s; i++)
        sum += (str[i] - '0');

    if(sum == 0 || sum == s)
        printf("%d", (bool)sum);
    else{
        printf("-");
        Solve(k, s/2);
        Solve(k+s/2, s/2);
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    scanf("%s", data);
    fclose(stdin);


}

void Print(){
    for(int i = 0; i < sz; i++){
        printf("%c", data[i]);
    }
    printf("\n");
}

void Out(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 18; i++){
        if(result[i] == '\0'){
            break;
        }
        printf("%c", result[i]);
    }
    fclose(stdout);
}

int Check(int start, int pre, int id){
    if(pre != start - 1){
        result[id] = '-';
        id++;
    }

    result[id] = data[start];
    id++;

    return id;
}

void Encrypt(){
    int id = 0, start, pre = 0;
    bool bk = false;

    for(int i = 1; i < sz; i++){
        if(data[0] != data[i]){
            start = i;
            bk = true;
            break;
        }
    }

    if(bk){
        result[id] = '-';
        bk = false;
        id++;
        result[id] = data[0];
        id++;

        //중복
        id = Check(start, pre, id);
    }else{
        result[id] = data[0];
        result[id+1] = '\0';
        return;
    }

    while(start != sz - 1){
        pre = start;

        for(int i = start + 1; i < sz; i++){
            if(data[start] != data[i]){
                start = i;

                //중복
                id = Check(start, pre, id);
            }
        }
        Out();
    }

    result[id] = '\0';
}

int main()
{
    scanf("%d %s", &n, str);
    Solve(0, n);
    /*
    In();
    Encrypt();
    Out();
    */
    return 0;
}
