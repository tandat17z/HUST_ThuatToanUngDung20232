#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;
int chk[10000 + 1];

void solution(){
	for( const auto &i : seq){
		cout << i << " " ;
	}
	cout << endl;
}

void Try(int k){
	for( int i = 1; i<=n ; ++i){
		if( !chk[i] ){
			seq.push_back(i);
			chk[i] = true;
			
			if( k == n) solution();
			else Try( k + 1);
			
			chk[i] = false;
			seq.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	cin >> n;
	Try(1);
	
	return 0;
}
