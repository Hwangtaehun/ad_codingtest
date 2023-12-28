#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge;
std::vector<int> v[100];

void input(){
    int a, b;

    //freopen("g1.txt", "r", stdin);
    //freopen("g2.txt", "r", stdin);
    freopen("B01.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void output(){
    printf("\n ��������Ʈ \n");
    for(int i = 1; i <= vertex; i++){
        printf("node %d : ", i);
        for(int j = 0; j < v[i].size(); j++){
            printf("%5d", v[i][j]);
        }
        printf("\n");
    }
}

bool visitedDFS[101];
void dfs1(int node){
    visitedDFS[node] = true;
    printf("%d ", node);

    for(int i = 0; i < v[node].size(); i++){
        if(!visitedDFS[v[node][i]])
            dfs1(v[node][i]);
    }
    return;
}

bool visitedBFS[101];
void bfs1(int node){
    std::queue <int> q;
    int currentNode;

    q.push(node);
    visitedBFS[node] = true;

    while(!q.empty()){
        currentNode = q.front();
        q.pop();
        printf("%d ", currentNode);
        for(int i = 0; i < v[currentNode].size(); i++){
            if(!visitedBFS[ v[currentNode][i] ]){
                visitedBFS[ v[currentNode][i] ] = true;
                q.push(v[currentNode][i]);
            }
        }
    }
}

int main()
{
    input();
    output();
    printf("\n DFS \n");
    dfs1(1);
    printf("\n BFS \n");
    bfs1(1);
    return 0;
}
