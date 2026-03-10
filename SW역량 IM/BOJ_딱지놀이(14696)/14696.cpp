#include<iostream>
#include<vector>

using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> itemsA(5, 0);
    vector<int> itemsB(5, 0);
    
    for(int i=0; i<N; i++){
        int numA, numB;
        cin >> numA;
        for(int j=0; j<numA; j++){
            int temp;
            cin >> temp;
            itemsA[temp]++;
        }
        cin >> numB;
        for(int j=0; j<numB; j++){
            int temp;
            cin >> temp;
            itemsB[temp]++;
        }

        for(int type=4; type>=0; type--){
            if(itemsA[type] == itemsB[type]){
                if(type == 0)
                    cout << 'D';
                continue;
            }
            cout << (itemsA[type]>itemsB[type] ? 'A' : 'B');
            break;
        }
        cout << '\n';
        itemsA.assign(5, 0);
        itemsB.assign(5, 0);
    }
    return 0;
}