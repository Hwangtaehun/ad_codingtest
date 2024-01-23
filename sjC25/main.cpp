#include <cstdio>
#include <cmath>

double data[10][2];
int charge, scale, minimum = 0x0fffffff, endSw;

//solve
int n, k, visit[11], dmin = 0x0fffffff;

struct airport{
    int x;
    int y;
} a[11];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    a[0].x = 0, a[0].y = 0;

    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    a[n+1].x = 10000, a[n+1].y = 10000;
    visit[0] = 1;
}

int Distance(int p1, int p2){
    return (a[p1].x - a[p2].x)*(a[p1].x - a[p2].x) + (a[p1].y - a[p2].y)*(a[p1].y - a[p2].y);
}

void Solve(int p, int c, int d){
    int d2;

    if(c == k){
        d2 = Distance(p, n + 1);

        if(d < d2){
            d = d2;
        }

        if(dmin > d){
            dmin = d;
        }

        return;
    }

    for(int i = 0; i <= n + 1; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            d2 = Distance(p, i);

            if(d < d2){
                d = d2;
            }

            Solve(i, c + 1, d);
            visit[i] = 0;
        }
    }
}

void In(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &scale, &charge);
    for(int i = 0; i < scale; i++){
        scanf("%lf %lf", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

int Oil(double dis){
    int portion = dis / 10;
    int rest = int(dis) % 10;

    if(rest == 0){
        return portion;
    }else{
        return portion + 1;
    }
}

void Predict(int index, int crg, double x, double y, int oil){
    double dis_x, dis_y, tot_dis;

    if(crg == 0){
        dis_x = 10000 - x;
        dis_y = 10000 - y;
        tot_dis = sqrt(pow(dis_x, 2) + pow(dis_y, 2));

        if(oil < Oil(tot_dis)){
            oil = Oil(tot_dis);
        }

        if(oil < minimum){
            minimum = oil;
        }
        return;
    }

    if(index > scale){
        endSw = 1;
        return;
    }

    if(endSw){
        return;
    }

    //printf("%d\n", oil);

    Predict(index+1, crg, x, y, oil);

    dis_x = data[index][0] - x;
    dis_y = data[index][1] - y;
    tot_dis = sqrt(pow(dis_x, 2) + pow(dis_y, 2));
    if(oil < Oil(tot_dis)){
        oil = Oil(tot_dis);
    }
    crg--;

    Predict(index+1, crg, data[index][0], data[index][1], oil);
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", minimum);
    fclose(stdout);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%.f\n", ceil(sqrt(dmin)/10));
    fclose(stdout);
}

int main()
{
    //In();
    //Predict(0, charge, 0, 0, 0);
    //Out();
    Input();
    Solve(0, 0, 0);
    Output();
    return 0;
}
