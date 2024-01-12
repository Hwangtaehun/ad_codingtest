#include <cstdio>
#include <string>

int weight, root, sz, num = 0;
int chu[7] = {1, 3, 9, 27, 81, 243, 729};
int hap[126];
int data[9];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &weight);
    fclose(stdin);
}

int Combination(int many, int num){
    int diff, up, down;
    if(many == num){
        return 1;
    }

    diff = many - num;

    if(diff == 1 || num == 1){
        return many;
    }

    up = 1, down = 1;

    for(int i = many; i > many - diff; i--){
        up *= i;
    }

    for(int i = 1; i <= diff; i++){
        down *= i;
    }
    return up/down;
}

void Kindhap(int i, int sum){
    if(i == root - 2){
        printf("i = %d, sum = %d\n", i, sum);
        hap[num] = sum;
        num++;
        return;
    }

    Kindhap(i+1, sum+chu[i+1]);
    Kindhap(i+1, sum);
}

void Sort(){
    for(int i = 0; i < num - 1; i++){
        for(int j = i; j < num; j++){
            if(hap[i] < hap[j]){
                int temp = hap[i];
                hap[i] = hap[j];
                hap[j] = temp;
            }
        }
    }
}

int Exist(int find_num){
    int check = 0;

    for(int i = 0; i < num; i++){
        if(find_num == hap[i]){
            check = i;
        }
    }

    return check;
}

void Balance(){
    int sum, diff, arrsz;
    for(int i = 6; i >= 0; i--){
        if(weight >= chu[i]){
            root =  i + 1;
            break;
        }
    }

    if(weight == chu[root-1]){
        data[0] = weight;
        data[1] = 0;
        data[2] = chu[root - 1];
        sz = 3;
    }else{
        for(int i = 0; i < root; i++){
            sum += chu[i];
        }

        if(sum == weight){
            data[0] = weight;
            data[1] = 0;

            for(int i = 0; i < root; i++){
                data[i+2] = chu[i];
            }

            sz = root + 2;
        }else{
            int no = root - 1;

            while(no != 0){
                arrsz += Combination(root - 1, no);
                no--;
            }

            Kindhap(-1, 0);
            num--;
            Sort();

            if(sum > weight){
                diff = chu[root] - weight;
                if(weight == diff){
                    int i;
                    data[0] = weight;

                    for(i = 1; i < root + 1; i++){
                        data[i] = chu[i-1];
                    }

                    data[i] = 0;
                    data[i+1] = chu[root];
                }else{
                    if(Exist(data[root-1]) != 0){

                    }
                }
            }else{

            }
        }
    }
}

int main()
{
    //Balance();
    /*
    root = 5;
    int no = root - 1, arrsz = 0;

    while(no != 0){
        arrsz += Combination(root - 1, no);
        no--;
    }

    Kindhap(-1, 0);
    num--;
    Sort();

    for(int i = 0; i < arrsz; i++){
        printf("hap[%d] = %d\n", i, hap[i]);
    }

    int temp = Exist(chu[root-2]);

    printf("temp = %d\n", temp);
    printf("hap[%d] = %d\n", temp, hap[temp]);
    */
}
