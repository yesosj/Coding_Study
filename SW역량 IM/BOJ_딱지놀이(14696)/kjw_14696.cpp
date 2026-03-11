/*
	1. round 입력 받기
	2. 차례대로 A,B가 가진 패를 입력 , 5 round = 10줄 입력
	3. for(i -> round) , 각 라운드별 가진 패를 cnt array에 저장 , 새로운 라운드 시작 시 초기화
	4. cnt array[4] 부터 비교하면서 , 높은 수를 가진 사람이 승리 if(arr1[4] > arr2[4] -> victory 1)
	5. 1 <= N <= 1000 , 1 <= A <= 100 -> 1000 * 100 = 100,000 
*/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int rnd;
int arr1[5] , arr2[5];
vector<char> ret;
int main(void){
	cin >> rnd ; 
	while(rnd--){
		memset(arr1 , 0 , sizeof(arr1));
		memset(arr2, 0 , sizeof(arr2));
		int a,b;
		cin >> a;
		for(int i = 0 ; i< a ; i++){
			int temp;
			cin >> temp;
			arr1[temp]++;
		}
		cin >> b;
		for(int i = 0 ; i < b; i++){
			int temp;
			cin >> temp;
			arr2[temp]++;
		}

		for(int i = 4 ; i > 0 ; i--){
			if(arr1[i] == arr2[i]){
				if(i == 1){
					ret.push_back('D');
				}
				continue;
			}
			else if(arr1[i] > arr2[i]){
				ret.push_back('A');
				break;
			}
			else if(arr1[i] < arr2[i]){
				ret.push_back('B');
				break;
			}
		}
	}
	for(int i = 0 ; i < ret.size() ; i++){
		cout << ret[i] << '\n';
	}
	return 0;
}
