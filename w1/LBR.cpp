#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1001][1001];
int h[1001];
int res = 0;

void input(){
	cin >> n >> m;
	for( int i = 1; i <= n; ++i){
		for( int j = 1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	
	h[0] = -1; 
	for( int i = 1; i<=n; ++i){
		stack<int> st;
		st.push(0);
		
		for( int j = 1; j<=m; ++j){
			if( a[i][j] == 1) h[j] += 1;
			else h[j] = 0;
//			cout << h[j] << " ";
			if( h[j] >= h[st.top()]) st.push(j);
			else{
				int x = st.top();
				while( h[j] < h[x]){
					st.pop();
					res = max(res, h[x]*( j - st.top() - 1));
					x = st.top();
				}
				st.push(j);
			}
		}
//		cout << endl;
		int x = st.top();
		while( x != 0){
			st.pop();
			res = max(res, h[x]*( m - st.top()));
			x = st.top();
		}
//		cout << i << ": " << res << endl;
	}
	cout << res;
	return 0;
}
