#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
vector<bool> visited;
int n, m;
void dfs(int depth){
    if(depth == m){
        for(int i=0; i<path.size(); i++)
            cout << path[i] << ' ';
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == true)
            continue;
        visited[i] = true;
        path.push_back(i);
        dfs(depth+1);
        path.pop_back();
        visited[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    visited.assign(n+1, 0);
    dfs(0);
    return 0;
}