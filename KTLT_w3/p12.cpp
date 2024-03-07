#include <iostream>
#include<vector>

using namespace std;

int n, k, m;
bool c[61][61]; 

bool visited[61];
vector<int> x;

int res = 0;

void input(){
	cin >> n >> k
		>> m;
	for( int i = 0; i<m; ++i){
		int u, v;
		cin >> u >> v;
		c[u][v] = true; c[v][u] = true;
	}
}

bool check(int t, int i){
	if ( t == 0) return true;
	
	if( !visited[i] && c[ x[t - 1] ][i]) return true;
	return false;
}

void Try(int t){
	for( int i = 1; i <= n; ++i){
		if( check(t, i) ){
			x.push_back(i);
			visited[i] = true;
			
			if( t == k) {
				for( auto _ : x){
					cout << _ << " ";
				}
				cout << endl;
				res += 1;
			}
			else Try(t + 1);
			
			visited[i] = false;
			x.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
    input();
    Try(0);
    
    cout << res / 2;
    return 0;
}
