/*
	1. 전체 학생 수 = N , 방 정원 = K 입력
	2. for(i -> 6){ for j -> 2} ret += arr[i][j] / k , 만약 나머지 있으면 방++; 
*/

#include <iostream>

using namespace std;

int n , k;
int arr[7][2];
int ret;

int main(void){
	cin >> n >> k ;
	for(int i = 0 ; i < n ; i++){
		int a , b;
		cin >> a >> b;
		arr[b][a]++;
	}
	for(int i = 1 ; i <= 6 ; i++){
		for(int j= 0 ; j < 2 ; j++){
			ret += arr[i][j] / k;
			if(arr[i][j] % k ) ret++;
		}
	}
	
	cout << ret;

	return 0;
}
