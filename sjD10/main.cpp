#include <cstdio>
#include <algorithm>

using namespace std;

int data[15], sz, mi = 0x0fffffff, am = 0x0fffffff, storge[3];
//solve
int gift[20], g1, g2, g3, n, d = 0x0fffffff, gd = 0x0fffffff, sum, debugCnt;

void ArrayPrn(){
    for(int i = 0; i < n; i++){
        printf("%d ", gift[i]);
    }
    printf("sum = %d\n", sum);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &gift[i]);
        sum += gift[i];
    }
    fclose(stdin);
}

bool Desc(int left, int right){
    return left > right;
}

void Solve(int no, int a, int b, int c){
    if(c > sum / 3 || b > sum / 2){
        return;
    }

    int restSum = sum - (a + b + c);
    if((restSum + a) < b || (restSum + b) < c){
        return;
    }

    if(a - (c + restSum) > d){
        return;
    }

    debugCnt++;

    if(no < n){
        Solve(no + 1, a, b, c + gift[no]);
        Solve(no + 1, a, b + gift[no], c);
        Solve(no + 1, a + gift[no], b, c);
    }
    else if(a >= b && b >= c && d >= (a-c) && gd > a){
        g1 = a, g2 = b, g3 = c;
        d = a - c;
        gd = a;
        printf("%d %d %d %d\n", g1, g2, g3, d);
    }
}

void In(){
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
    //In();
    //Divide(0, 0, 0, 0);
    //Output();
    Input();
    sort(gift, gift+n, Desc);
    ArrayPrn();
    Solve(0, 0, 0, 0);
    printf("%d %d %d\n", g1, g2, g3);
    printf("\ndebugCnt = %d\n", debugCnt);
    return 0;
}
