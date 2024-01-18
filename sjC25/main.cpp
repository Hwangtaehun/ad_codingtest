#include <cstdio>
#include <cmath>

double data[10][2];
int charge, scale, minimum = 0x0fffffff, endSw;

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

int main()
{
    In();
    Predict(0, charge, 0, 0, 0);
    Out();
    return 0;
}
