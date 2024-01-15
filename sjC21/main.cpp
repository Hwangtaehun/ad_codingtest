#include <cstdio>

int data[16], separate, cnt, person, end;
int cho[16] = {0,};

void In(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &cnt);
    for(int i = 1; i <= cnt; i++){
        scanf("%d", &data[i]);
    }

    person = 3;
}

void Choose(int num, int sum, int user){
    if(end){
        return;
    }

    if(sum == separate){
        for(int i = 1; i <= cnt; i++){
            printf("if¹® choice[%d] = %d\n", i, cho[i]);
        }
        end = 1;
        return;
    }


    if(cho[num] == 0){
        cho[num] = user;
        Choose(num+1, sum + data[num], user);
        cho[num] = 0;
        Choose(num+1, sum, user);
    }
}

void Process(){
    bool out = true;
    while(out){
        if(person == 0){
            break;
        }

        int sum = 0;

        for(int i = 1; i <= cnt; i++){
            if(cho[i] == 0){
                sum += data[i];
            }
        }

        separate = sum / person;
        printf("separate = %d\n", separate);

        Choose(0, 0, person);
        for(int i = 1; i <= cnt; i++){
            printf("choice[%d] = %d\n", i, cho[i]);
        }

        for(int i = 1; i <= cnt; i++){
            if(cho[i] != 0){
                out = false;
            }
        }

        if(out){
            int big = 0, index = 0;

            for(int i = 1; i <= cnt; i++){
                if(big < data[i]){
                    big = data[i];
                    index = i;
                }
            }
            cho[index] = person;
            person--;
        }
    }
    //Choose(0, 0, 2);
}

int main()
{
    In();
    //Process();
    separate = 12;
    Choose(0, 0, 1);
    //for(int i = 1; i <= cnt; i++){
        //printf("data[%d] = %d\n", i, data[i]);
    //}
    return 0;
}
