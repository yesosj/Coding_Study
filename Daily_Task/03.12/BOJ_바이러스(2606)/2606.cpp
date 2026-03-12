/*
    1. DFS/BFS 이용해서 1번 노드와 연결된 다른 모든 노드 탐색
    2. 노드 방문 할 때마다 cnt 증가
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
queue<int> q;
int N=100, M;
int cnt = 0;

void dfs(int cur){
    visited[cur] = 1;

    for(int i=0; i<adj[cur].size(); i++){
        int nxt = adj[cur][i];

        if(visited[nxt] == 0){
            visited[nxt] = 1;
            cnt++;
            dfs(nxt);
        }
    }
}

void bfs(int start){
    visited[start] = 1;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][i];

            if(visited[nxt] == 0){
                visited[nxt] = 1;
                q.push(nxt);
                cnt++;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    adj.assign(N+1, vector<int> ());
    visited.assign(N+1, 0);

    for(int i=0; i<M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

    //dfs(1);
    bfs(1);
    cout << cnt;
}