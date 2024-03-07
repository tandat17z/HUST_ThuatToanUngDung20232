#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> seq;

void solution(){
	for( const auto &i : seq){
		cout << i ;
	}
	cout << endl;
}

bool check(int k, int i){
	if( i == 1 && seq[k - 2] == 1) return false;
	return true;
}
void Try(int k){
	for( int i = 0; i<=1 ; ++i){
		if( check( k, i)){
			seq.push_back(i);
		
		if( k == n ) solution();
		else Try(k + 1);
		
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
