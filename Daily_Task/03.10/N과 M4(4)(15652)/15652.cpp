#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> path;

void dfs(int depth){
    if(depth == M){
        for(int i=0; i<path.size(); i++)
            cout << path[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){
        if(path.empty())
            path.push_back(i);
        else{
            if(path.back() <= i)
                path.push_back(i);
            else
                continue;
        }

        dfs(depth+1);

        path.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    dfs(0);
}