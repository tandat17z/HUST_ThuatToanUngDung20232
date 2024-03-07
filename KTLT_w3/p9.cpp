// dynamic programing
#include<bits/stdc++.h>

using namespace std;

int n, k1, k2;
int M[201]; // M[i] là so chuoi do dai i va bat dau la 1 thoa man

vector<int> seq;
int cur = 0; // so ngay dang lam lien tiep

void input(){
	cin >> n >> k1 >> k2;
}

//int computeM(int k){
//	if( k < 0) return 0;
//	else if( k == 0) return 1;
//	
//	if( M[k] ) return M[k];
//	
//	if( k >= k1 && k <= k2) M[k] = 1;
//	for( int i = k1; i<=k2; ++i){
//		M[k] += computeM(k - i - 1);
//	}
//	return M[k];
//}
void solution(){
	for( auto s: seq){
		cout << s;
	}
	cout << endl;
}
bool check0( int k ){
	if( k == 0) return true;
	
	if( cur >= k1 && cur <= k2) return true;
	
	return false;
	
}
bool check1( int k ){
	if( k == 0) return true;
	
	if( cur + 1 <= k2) return true;
	
	return false;
}

void Try(int k){
	if( check0(k) ){
		seq.push_back(0);
		int temp = cur;
		cur = 0;
		
		if( k == n - 1) solution();
		else Try(k + 1);
		
		cur = temp;
		seq.pop_back();
	}
	if (check1(k) ){
		seq.push_back(1);
		cur += 1;
		
		if( k == n - 1) {
			if( cur >= k1 & cur <= k2) solution();
		}
		else Try(k + 1);
		
		cur -= 1;
		seq.pop_back();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	Try(0);
	
	return 0;
}
