#include<bits/stdc++.h>

using namespace std;

int n, K_place;
int c[50][50];
int min_c = INT_MAX;
int x[50];
bool visited[50];

int cur_d = 0;
int cur_load = 0;
int res = INT_MAX;

void input(){
	scanf("%d %d", &n, &K_place);
	for( int i = 0;  i <= (n << 1); ++i){
		for( int j = 0; j<= (n << 1); ++j){
			scanf("%d", &c[i][j]);
			if( i != j && min_c > c[i][j]) min_c = c[i][j];
		}
	}
}

bool check(int k, int i){
	if( visited[i] ) return false;
	if( cur_load >= K_place && i <= n) return false;
	if( i > n && !visited[i - n] ) return false;
	
	return true;
}
void solution(){
	if( res > cur_d + c[x[n << 1]][0]) {
		res = cur_d + c[x[n << 1]][0];
	}
}
void Try(int k){
	for( int i = 1; i<=2*n; ++i){
		if( check(k, i) ){
			x[k] = i;
			visited[i] = true;
			cur_d += c[x[k-1]][i];
			if( i <= n) cur_load += 1;
			else cur_load -= 1;
			
			if( k == (n << 1) ) solution();
			else if( cur_d + min_c*((n << 1) +1 - k) < res) Try(k + 1);
			
			visited[i] = false;
			cur_d -= c[x[k-1]][i];
			if( i <= n) cur_load -= 1;
			else cur_load += 1;
		}
	}
}

int main(){
	input();
	
	x[0] = 0;
	Try(1);
	cout << res;
	
	return 0;
}
