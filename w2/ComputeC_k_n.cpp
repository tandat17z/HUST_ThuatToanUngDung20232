#include<bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

int k, n;
int M[1000][1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	cin >> k >> n;
	for( int i = 1; i<=n; ++i){
		M[i][0] = 1;
		M[i][i] = 1;
		for( int j = 1; j < i ; ++j){
			M[i][j] = (M[i - 1][j - 1]%P + M[i - 1][j]%P) %P;
		}
	}
	cout << M[n][k]; 
	
	return 0;
}
