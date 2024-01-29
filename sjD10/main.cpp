#include <cstdio>

using namespace std;

int data[15], sz, mi = 0x0fffffff, am = 0x0fffffff, storge[3];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &sz);
    for(int i = 0; i < sz; i++){
        scanf("%d", &data[i]);
    }
    fclose(stdin);
}

void Divide(int a, int b, int c, int index){
    if(sz > index){
        Divide(a + data[index], b, c, index + 1);
        Divide(a, b + data[index], c, index + 1);
        Divide(a, b, c + data[index], index + 1);
    }else if(a >= b && b >= c && (a - c) <= mi && a <= am){
        mi = a - c;
        am = a;
        storge[0] = a;
        storge[1] = b;
        storge[2] = c;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d %d %d", storge[0], storge[1], storge[2]);
    fclose(stdout);
}

int main()
{
    Input();
    Divide(0, 0, 0, 0);
    Output();
    return 0;
}
