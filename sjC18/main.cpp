#include <cstdio>

int kind, weight, mxpr = 0;
int data[100][2];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &kind, &weight);
    for(int i = 0; i < kind; i++){
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void Cost(int i, int sum, int price){
    if(sum > weight){
        return;
    }
    //printf("i = %d, sum = %d, price = %d\n", i, sum, price);
    if(i == kind){
        if(mxpr < price){
            mxpr = price;
        }
        return;
    }

    Cost(i+1, sum+data[i][0], price+data[i][1]);
    Cost(i+1, sum, price);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", mxpr);
    fclose(stdout);
}

int main()
{
    Input();
    Cost(-1, 0, 0);
    Output();
    return 0;
}
