#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge, cost;
int vertex_cost[9];//여기에 들어가는 값은 0과 1를 제외 시작은 2 즉 2 = 0, 3 = 1
bool visited[11];
std::vector< pair <int, int> > v[60];//data 데이터

void Input(){
    int a, b, w;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
    }
}


void Solve(){
    std:queue <int> q;
    int pre_cost = 0;
    int currentNode;

    q.push(1);
    visited[1] = true;

    while(currentNode != vertex){
        currentNode = q.front();
        q.pop();

        if(currentNode != 1){
            pre_cost = vertex_cost[currentNode-2];
        }

        for(int i = 0; i < v[currentNode].size();i++){
            int pre_value = v[currentNode][i].second + pre_cost;
            int *temp = &vertex_cost[v[currentNode][i].first - 2];
            if(*temp ==0 || pre_value < *temp){
                *temp = pre_value;
            }
        }

        int node = 0;
        int value = 999;

        for(int i = 0; i <= vertex - 2;i++){
            if(vertex_cost[i] != 0 && !visited[i+2]){
                if(vertex_cost[i] < value){
                    node = i + 2;
                    value = vertex_cost[i];
                }
            }
        }

        visited[node] = true;
        q.push(node);
    }

    cost = vertex_cost[currentNode-2];
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", cost);
}

int main()
{
    Input();
    Solve();
    Output();

    return 0;
}
