#include<bits/stdc++.h>

using namespace std;

int n, r;
int c[1000][1000];

vector<int> List[1000];
vector<int> visited;

int r_now;
int start, target, curr;
vector<int> route;

int min_c;

void input(){
	cin >> n >> r;
	for( int i = 1; i<=n; ++i){
		for(int j = 1; j<=n; ++j){
			cin >> c[i][j];
		}
	}
	string s; 
	getline(cin, s);
	for( int i = 1 ; i <= r; ++i){
		getline(cin, s);
		std::istringstream iss (s);
		
		int x;
		while( iss >> x ) {
//			cout << x << " ";
			List[i].push_back(x);
		}
//		cout << endl;
			
	}
}

bool check(int k, int x){
	if( c[route[k-1]][x] == 0 ) return false;
	
	if( k + 1 == List[r_now].size() && x == target ) 
		return true;

	if( !visited[x] && x != target) return true;
	return false;
	
}

void solution(){
	if( curr < min_c ) min_c = curr;
}
void Try(int k){
	for( int i = 1; i < List[r_now].size() ; ++i){
		int x = List[r_now][i];
		if( check(k, x) ){
			route.push_back(x);
			visited[x] = 1;
			curr += c[ route[k - 1]][ route[k]];
			
			if( k + 1 == List[r_now].size() ) solution();
			else if( curr < min_c) Try(k + 1);
			
			visited[x] = 0;
			curr -= c[ route[k - 1]][ route[k]];
			route.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	for( r_now = 1; r_now <= r; ++r_now){
		min_c = INT_MAX;
		curr = 0;
		
		route.clear();
		visited.assign(n + 1, 0);
		
		start = List[r_now][0];
		target = List[r_now][List[r_now].size() - 1];
		
		route.push_back(start);
		Try(1);
		
		if( min_c == INT_MAX )cout << 0 << endl;
		else cout << min_c << endl;
	}

	return 0;
}
