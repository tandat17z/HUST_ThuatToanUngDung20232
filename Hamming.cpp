#include<bits/stdc++.h>

using namespace std;

int t, n, h;
vector<int> res;

bool check0(int k){
	if( h == 0 || n - k >= h) return true;
	return false;
}

bool check1(int k){
	if( h > 0 ) return true;
	return false;
}
void solution(){
	for( int i : res) cout << i ;
	cout << endl;
}

void Try(int k){
	if( check0(k) ){
		res.push_back(0);
		
		if( n == k ) solution();
		else Try(k + 1);
		
		res.pop_back();
	}
	
	if( check1(k) ){
		res.push_back(1);
		h -= 1;
		
		if( n == k ) solution();
		else Try(k + 1);
		
		h += 1;
		res.pop_back();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while( t-- ){
		cin >> n >> h;
		Try(1);
		cout << endl;
	}
	return 0;
}
