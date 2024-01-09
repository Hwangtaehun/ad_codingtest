#include <cstdio>
int data[2][100];
bool visited[100];
int minum, n, mc, i, M;

//Ç®ÀÌ
int m[101], c[101];

int Min(int a, int b){
    return a < b ? a : b;
}

int f(int i, int r){
    if(r <= 0){
        return 0;
    }
    printf("%d,%d \n", i, r);

    if(i == 0){
        return 99999;
    }
    else{
        return Min(f(i-1,r), f(i-1,r-m[i])+c[i]);
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &mc);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Close(){
    int hap = 0, cnt = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(data[0][i] < data[0][j]){
                int temp_n = data[0][i];
                int temp_m = data[1][i];
                data[0][i] = data[0][j];
                data[1][i] = data[1][j];
                data[0][j] = temp_n;
                data[1][j] = temp_m;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(data[1][j+1] < data[1][j]){
                int temp_n = data[0][j+1];
                int temp_m = data[1][j+1];
                data[0][j+1] = data[0][j];
                data[1][j+1] = data[1][j];
                data[0][j] = temp_n;
                data[1][j] = temp_m;
            }
        }
    }

    while(hap < mc){
        hap += data[0][cnt];
        minum += data[1][cnt];
        cnt++;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", minum);
    fclose(stdout);
}

int main()
{
    //Input();
    //Close();
    //Output();

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &M);

    for(i = 1; i <= n; i++){
        scanf("%d", &m[i]);
    }

    for(i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }

    printf("%d", f(n,M));
    return 0;
}
