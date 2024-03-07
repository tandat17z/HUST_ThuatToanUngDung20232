#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000000];
int M[20][1000000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	//input
	cin >> n;
	for( int i = 0; i<n; ++i){
		cin >> a[i];
		M[0][i] = a[i];
	}
	
	for( int j = 1; (1 << j) - 1 < n; ++j){
		for( int i = 0; i + (1 << j) - 1 < n; ++i){
			M[j][i] = min(M[j-1][i], M[j-1][i + (1<<(j -  1))]);
		}
	}
	
	// query
	int m, res = 0;
	cin >> m;
	while( m -- ){
		int u, v;
		cin >> u >> v;
		int k = log2(v - u + 1);
		res += min(M[k][u], M[k][v - (1 << k) + 1]);
	}
	cout << res;
	
	return 0;
}

