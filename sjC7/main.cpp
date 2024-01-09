#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge, cost;
int vertex_cost[9];//여기에 들어가는 값은 0과 1를 제외 시작은 2 즉 2 = 0, 3 = 1
bool visit[11];
std::vector< pair <int, int> > v[60];//data 데이터

//풀이 데이터터
int n, m, data[11][11], wmin = 0x7fffffff, visited[11];

void ArrayPrn(int w){
    printf("\t");
    for(int i = 1; i <= n; i++){
        printf("%d ", visited[i]);
    }
    printf(" %5d\n", w);
}

void Print(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%3d ", data[i][j]);
        }
        printf("\n");
    }
}

void Solve(int v, int w){
    if( w > wmin)
        return;

    if(v == n){
        if(w < wmin){
            wmin = w;
        }
        ArrayPrn(w);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i] && data[v][i]){
            visited[i] = 1;
            printf("%d,%d ", v, i);
            Solve(i, w + data[v][i]);
            visited[i] = 0;
        }
    }
}

void Input(){
    int s, e, w;

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &s, &e, &w);
        data[s][e] = data[e][s] = w;
    }
    fclose(stdin);
}


void In(){
    int a, b, w;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
    }
}


void Move(){
    std:queue <int> q;
    int pre_cost = 0;
    int currentNode;

    q.push(1);
    visit[1] = true;

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
            if(vertex_cost[i] != 0 && !visit[i+2]){
                if(vertex_cost[i] < value){
                    node = i + 2;
                    value = vertex_cost[i];
                }
            }
        }

        visit[node] = true;
        q.push(node);
    }

    cost = vertex_cost[currentNode-2];
}

void Out(){
    freopen("output.txt", "w", stdout);
    printf("%d", cost);
}

int main()
{
    //In();
    //Move();
    //Out();

    Input();
    Print();
    visited[1] = 1;
    Solve(1, 0);

    printf("%d\n", (wmin == 0x7fffffff) ? -1 : wmin);
    return 0;
}
