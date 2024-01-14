#include <cstdio>
#include <vector>

using namespace std;

int vertex, edge;
int NodeColor[200];
vector<int> data[200];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        data[s].push_back(e);
        data[e].push_back(s);
    }
}

void Solve(int v, int c){
    NodeColor[v] = c;

    for(int i = 0; i < data[v].size(); i++){
        if(NodeColor[data[v][i]] == c){
            NodeColor[v] = 0;
            return;
        }
    }

    for(int i = 0; i < data[v].size(); i++){
        if(NodeColor[data[v][i]] == 0){
            Solve(data[v][i], 1);
            Solve(data[v][i], 2);
        }
    }
}

int main()
{
    Input();
    Solve(0, 1);
    for(int i = 0; i < vertex; i++){
        if(NodeColor[i] == 0){
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    printf("OK");
    return 0;
}
