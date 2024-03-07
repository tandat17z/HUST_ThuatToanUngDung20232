#include<bits/stdc++.h>

using namespace std;

int cell[9][9];
bool chk_row[9][10],
	 chk_col[9][10],
	 chk_sub_square[3][3][10];
int res = 0;

void input(){
	for( int i = 0; i<9; ++i){
		for( int j = 0; j<9; ++j){
			cin >> cell[i][j];
			
			if( cell[i][j] ){
				chk_row[i][ cell[i][j] ] = true;
				chk_col[j][ cell[i][j] ] = true;
				chk_sub_square[i/3][j/3][ cell[i][j] ] = true;
			}
		}
	}
}

bool check(int r, int c, int i){
	if( !chk_row[r][i] && !chk_col[c][i] 
		&& !chk_sub_square[r/3][c/3][i]) return true;
		
	return false;
}

void solution(){
//	cout << "solution" << endl;
	res += 1;
}

void Try(int k){
	int r = k / 9, c = k % 9;
	if( cell[r][c] ) {
		Try(k + 1);
		return;
	}
	
	for( int i = 1; i<= 9; ++i){
		if( check(r, c, i)){
			cell[r][c] = i;
			
			chk_row[r][i] = true;
			chk_col[c][i] = true;
			chk_sub_square[r/3][c/3][i] = true;
			
			if( k == 9 * 9 - 1) solution();
			else Try(k + 1);
			
			
			chk_row[r][i] = false;
			chk_col[c][i] = false;
			chk_sub_square[r/3][c/3][i] = false;
			cell[r][c] = 0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	input();
	Try(0);
	cout << res;
	
	return 0;
}
