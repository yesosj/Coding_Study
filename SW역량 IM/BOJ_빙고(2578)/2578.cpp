/*
    1. 2차원 벡터로 빙고 저장
    2. 숫자 불릴 때마다 해당 칸 -1로 표시
    3. 열 5개, 행 5개, 대각선 2개 빙고인지 확인
    4. 3줄 이상 빙고면 종료
*/
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> binggo(5, vector<int> (5));

void checkNumbers(int num){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(binggo[i][j] == num){
                binggo[i][j] = -1;
                return;
            }
        }
    }
}

bool checkColumns(int cl){
    if(binggo[0][cl] == binggo[1][cl] && binggo[1][cl] == binggo[2][cl] && 
    binggo[2][cl] == binggo[3][cl] && binggo[3][cl] == binggo[4][cl])
        return true;
    return false;
}

bool checkRows(int rw){
    if(binggo[rw][0] == binggo[rw][1] && binggo[rw][1] == binggo[rw][2] &&
    binggo[rw][2] == binggo[rw][3] && binggo[rw][3] == binggo[rw][4])
        return true;
    return false;
}

bool cntBinggos(void){
    int cnt = 0;
    
    for(int i=0; i<5; i++){
        if(checkColumns(i))
            cnt++;
        if(checkRows(i))
            cnt++;
    }
    if(binggo[0][0] == binggo[1][1] && binggo[1][1] == binggo[2][2] &&
    binggo[2][2] == binggo[3][3] && binggo[3][3] == binggo[4][4])
        cnt++;
    if(binggo[0][4] == binggo[1][3] && binggo[1][3] == binggo[2][2] &&
    binggo[2][2] == binggo[3][1] && binggo[3][1] == binggo[4][0])
        cnt++;

    if(cnt>=3){
        return true;
    }
    else
        return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int temp;
            cin >> temp;
            binggo[i][j] = temp;
        }
    }

    for(int i=0; i<25; i++){
        int temp;
        cin >> temp;

        checkNumbers(temp);

        if(cntBinggos()){
            cout << i+1;
            return 0;
        }
    }
}