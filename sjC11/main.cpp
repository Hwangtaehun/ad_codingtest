#include <cstdio>
int data[2][100];
bool visited[100];
int minum, n, m;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
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

    while(hap < m){
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
    Input();
    Close();
    Output();
}
