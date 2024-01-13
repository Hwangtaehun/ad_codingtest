#include <cstdio>
#include <string>

int weight, root, sz, num = 0;
int chu[7] = {1, 3, 9, 27, 81, 243, 729};
int hap[126], data[9], hap_arr[7];

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
    if(i == root - 1){
        //printf("i = %d, sum = %d\n", i, sum);
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

void Search(int i, int sum, int find_num, int arr[]){
    //printf("i =%d, sum = %d, find_num = %d\n", i, sum, find_num);
    //printf("sum = %d\n", sum);

    /*
    for(int j = 0; j < root; j++){
        printf("arr[%d] = %d\n", j, arr[j]);
    }
    */

    if(i == root + 1){
        return;
    }

    if(sum == find_num){
        for(int j = 0; j < root; j++){
            hap_arr[j] = arr[j];
        }
        return;
    }

    Search(i+1, sum, find_num, arr);
    arr[i] = chu[i];
    Search(i+1, sum + chu[i], find_num, arr);
}

void Array_Init(int* arr, bool zero){
    if(zero){
        for(int i = 0; i < root; i++){
            arr[i] = 0;
        }
    }else{
        for(int i = 0; i < root; i++){
            arr[i] = hap_arr[i];
        }
    }
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
            int no = root;

            while(no != 0){
                arrsz += Combination(root, no);
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
                    sz = i + 2;
                }else{
                    int i = Exist(weight);
                    if(i != 0){
                        int arr[root];
                        Array_Init(arr, true);
                        Search(0, 0, weight, arr);

                        i = 1;
                        data[0] = weight;
                        for(int j = 0; j < root; j++){
                            if(arr[j] != 0){
                                data[i] = arr[j];
                                i++;
                            }
                        }

                        data[i] = 0;
                        data[i + 1] = chu[root];
                        sz = i + 2;
                    }else{
                        //here
                        int index, temp_diff, bouns[root], base[root];
                    }
                }
            }else{// sum < weight
                int i = Exist(weight);
                if(i != 0){
                    int arr[root];
                    Array_Init(arr, true);
                    Search(0, 0, weight, arr);

                    i = 2;
                    data[0] = weight;
                    data[1] = 0;

                    for(int j = 0; j < root; j++){
                        if(arr[j] != 0){
                            data[i] = arr[j];
                            i++;
                        }
                    }

                    sz = i;
                }
                else{
                    int index, temp_diff, bouns[root], base[root];

                    Array_Init(bouns, true);
                    Array_Init(base, true);

                    for(int i = 1; i < arrsz; i++){
                        if(weight > hap[i]){
                            index = i - 1;
                            break;
                        }
                    }

                    temp_diff = weight - hap[index];
                    while(Exist(temp_diff) == 0){
                        index--;
                        temp_diff = weight - hap[index];
                    }
                    Search(0, 0, temp_diff, bouns);
                    Array_Init(bouns, false);
                    hap_arr[7] = {0,};
                    Search(0, 0, hap[index], base);
                    Array_Init(base, false);

                    int i = 1;
                    data[0] = weight;
                    for(int j = 0; j < root; j++){
                        if(bouns[j] != 0){
                            data[i] = bouns[j];
                            i++;
                        }
                    }
                    data[i] = 0;
                    i++;
                    for(int j = 0; j < root; j++){
                        if(base[j] != 0){
                            data[i] = bouns[j];
                            i++;
                        }
                    }
                    sz = i;
                }
            }
        }
    }
}

int main()
{
    /*
    Input();
    Balance();
    for(int i = 0; i < sz; i++){
        printf("%d ", data[i]);
    }
    */

    root = 4;
    int no = root, arrsz = 0;

    while(no != 0){
        arrsz += Combination(root, no);
        no--;
    }

    Kindhap(-1, 0);
    num--;
    Sort();

    for(int i = 0; i < arrsz; i++){
        printf("hap[%d] = %d\n", i, hap[i]);
    }

    /*
    int temp = Exist(chu[root-1]);

    printf("temp = %d\n", temp);
    printf("hap[%d] = %d\n", temp, hap[temp]);

    int arr[root];
    for(int i = 0; i < root; i++){
        arr[i] = 0;
    }

    Search(0, 0, 36, arr);

    int x = 0, like[4] = {};
    for(int i = 0; i < root; i++){
        if(hap_arr[i] != 0){
            like[x] = hap_arr[i];
            x++;
        }
    }

    for(int j= 0; j < x; j++){
        printf("like[%d] = %d\n", j, like[j]);
    }
    */

    return 0;
}