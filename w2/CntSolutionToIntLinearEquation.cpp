#include<bits/stdc++.h>

using namespace std;

int n, M, temp;
vector<int> a;

int res = 0;

void input(){
	cin >> n >> M;
	for( int i = 0; i<n; ++i){
		int x;
		cin >> x;
		a.push_back(x);
		temp += x;
	}
}
void solution(){
	res += 1;
}

void Try(int k){
	for( int i = 1; i <= (M - temp)/a[k - 1] + 1 ; ++i){
		temp += (i - 1) * a[k - 1];
		
		if( k == n && temp == M) solution();
		else if( k < n) Try( k + 1);
		
		temp -= (i - 1) * a[k - 1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	input();
	Try(1);
	cout << res;
	return 0;
}
