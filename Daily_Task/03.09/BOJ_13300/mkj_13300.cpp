#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> student(7, vector<int> (2, 0));
    int cnt = 0;
    for(int i=0; i<n; i++){
        int s, g;
        cin >> s >> g;
        student[g][s]++;

        if(student[g][s]%k == 1 || student[g][s] == 1)
            cnt++;
    }

    cout << cnt;
}