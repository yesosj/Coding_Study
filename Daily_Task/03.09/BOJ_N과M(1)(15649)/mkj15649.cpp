#include<iostream>

using namespace std;

int n, m;

void number(int cur, int depth){
    cout << cur << '\n';

    if(depth < m)
        number(cur+1, depth+1);
    if(depth == m)
        return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    number(1, 1);    
}