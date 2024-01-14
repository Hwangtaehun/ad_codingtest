#include <cstdio>
#include <vector>
#include <string>

using namespace std;

std::vector<int> Data[200];
int node, edge;
bool possible = true;

//풀이
int vertex;
int data[200][200], NodeColor[200];

void Input(){
    int s, e;

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &vertex, &edge);

    for(int i = 0; i < edge; i++){
        scanf("%d%d", &s, &e);
        data[s][e] = data[e][s] = 1;
    }
}

void ArrayPrn(int v, int c){
    printf("\t");
    for(int i = 0; i < vertex; i++){
        printf("%d ", NodeColor[i]);
    }
    printf(", %d %d\n", v, c);
}

void ArrayPrn2(){
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Solve(int v, int color){
    NodeColor[v] = color;
    ArrayPrn(v, color);

    for(int i = 0; i < vertex; i++){
        if(data[v][i] && NodeColor[i] == color){
            NodeColor[v] = 0;
            return;
        }
    }

    for(int i = 0; i < vertex; i++){
        if(data[v][i] && NodeColor[i] == 0){
            Solve(i, 1);
            Solve(i, 2);
        }
    }
}

void In(){
    int x, y;

    freopen("input.txt", "r", stdin);
    scanf("%d", &node);
    scanf("%d", &edge);

    for(int i = 0; i < edge; i++){
        scanf("%d %d", &x, &y);
        Data[x].push_back(y);
        Data[y].push_back(x);
    }
    fclose(stdin);
}

void Color(){
    int rb[node]; //1은 빨간색, 2는 검은색

    for(int i = 0; i< node; i++){
        rb[i] = 0;
    }

    for(int i = 0; i < node; i++){
        if(Data[i].size() != 0 && rb[i] == 0){
            rb[i] = 1;
            for(int j = 0; j < Data[i].size(); j++){
                rb[Data[i][j]] = 2;
            }
        }
    }

    //check
    for(int i = 0; i < node; i++){
        for(int j = 0; j < Data[i].size(); j++){
            if(rb[i] == rb[Data[i][j]]){
                possible = false;
                return;
            }
        }
    }
}

void Print(){
    for(int i = 0; i < node; i++){
        printf("node %d : ", i);
        for(int j = 0; j < Data[i].size(); j++){
            printf("%d ", Data[i][j]);
        }
        printf("\n");
    }
}

void Out(){
    string context = "IMPOSSIBLE";

    if(possible){
        context = "OK";
    }

    freopen("output.txt", "w", stdout);
    printf("%s", context.c_str());
    fclose(stdout);
}

int main()
{
    /*
    In();
    Color();
    Out();
    */

    Input();
    ArrayPrn2();

    Solve(0, 1);
    ArrayPrn(0, 0);
    for(int i = 0; i < vertex; i++){
        if(NodeColor[i] == 0){
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    printf("OK");
    return 0;
}
