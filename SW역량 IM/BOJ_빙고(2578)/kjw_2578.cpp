/*
	1. 2중 for문으로 돌면서, 부른 값에 대한 index에 해당하는 배열을 1로 만들기
	2. 부를 때마다 빙고 개수 check
*/

#include <iostream>

using namespace std;

int arr[26][26];
int call[26][26];


int check(){
	int bingo = 0;
	for(int i = 0 ; i < 5; i++){
		int check_row = 0;
		for(int j = 0 ; j < 5 ; j++){
			if(call[i][j] == 1){
				check_row++;
			}
		}
		if(check_row == 5) bingo++;
	}
	for(int i = 0 ; i < 5; i++){
		int check_col = 0;
		for(int j = 0 ; j < 5 ; j++){
			if(call[j][i] == 1){
				check_col++;
			}
		}
		if(check_col == 5) bingo++;
	}
	int check_cross = 0;
	for(int i = 0 ; i < 5; i++){;
		if(call[i][i] == 1) check_cross++;
		if(check_cross == 5) bingo++;
	}
	
	check_cross = 0;
	for(int i = 4 ; i >= 0; i--){
		if(call[4-i][i] == 1) check_cross++;
		if(check_cross == 5) bingo++;
	}

	if(bingo >= 3) return 1;
	else return 0;
}

int main(void){
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++){
			int a;
			cin >> a;
			int pass = 0;
			for(int row= 0 ; row < 5; row++){
				for(int col = 0 ; col < 5 ; col++){
					if(arr[row][col] == a){
						call[row][col] = 1;
						pass = 1;
						break;
					}
				}
				if(pass) break;
			}
			if(check() == 1){ 
				cout << (i)*5 + j+1 << '\n';
				return 0;
			}
		}
	}
}
