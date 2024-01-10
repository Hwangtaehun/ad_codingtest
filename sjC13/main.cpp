#include <cstdio>
#include <vector>
#include <string>

using namespace std;

std::vector<int> data[200];
int node, edge;
bool possible = true;

void Input(){
    int x, y;

    freopen("input.txt", "r", stdin);
    scanf("%d", &node);
    scanf("%d", &edge);

    for(int i = 0; i < edge; i++){
        scanf("%d %d", &x, &y);
        data[x].push_back(y);
        data[y].push_back(x);
    }
}

void Color(){
    int rb[node]; //1은 빨간색, 2는 검은색

    for(int i = 0; i< node; i++){
        rb[i] = 0;
    }

    for(int i = 0; i < node; i++){
        if(data[i].size() != 0 && rb[i] == 0){
            rb[i] = 1;
            for(int j = 0; j < data[i].size(); j++){
                rb[data[i][j]] = 2;
            }
        }
    }

    //check
    for(int i = 0; i < node; i++){
        for(int j = 0; j < data[i].size(); j++){
            if(rb[i] == rb[data[i][j]]){
                possible = false;
                return;
            }
        }
    }
}

void Print(){
    for(int i = 0; i < node; i++){
        printf("node %d : ", i);
        for(int j = 0; j < data[i].size(); j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Output(){
    string context = "IMPOSSIBLE";

    if(possible){
        context = "OK";
    }

    freopen("output.txt", "w", stdout);
    printf("%s", context.c_str());
}

int main()
{
    Input();
    Color();
    Output();
    return 0;
}
