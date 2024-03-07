#include<bits/stdc++.h>

using namespace std;

int n, k1, k2;
vector<int> res;
int curr = 0; 

void input(){
	cin >> n >> k1 >> k2;
}

bool check0(int k){
	if( k == 1) return true;
	if( curr >= k1 && curr <= k2) 
		if( n - k >= k1 || n == k) return true;
	return false;
}
bool check1(int k){
	if( k == 1) return true;
	if( curr + 1 <= k2) return true;
	return false;
}

void solution(){
	for( auto i: res) cout << i;
	cout << endl;
}
void Try(int k){
	if( check0(k) ){
		res.push_back(0);
		int temp = curr;
		curr = 0;
		
		if( k == n ) solution();
		else Try(k + 1);
		
		curr = temp;
		res.pop_back();
		
	}
	
	if( check1(k) ){
		res.push_back(1);
		curr += 1;
		
		if( k == n ) solution();
		else Try(k + 1);
		
		curr -= 1;
		res.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	Try(1);
	
	return 0;
}
