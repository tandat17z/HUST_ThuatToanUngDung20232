#include<bits/stdc++.h>

using namespace std;

string s;
string cmd;
unordered_map<string, bool> mapping;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while( cin >> s){
		if( s == "*") break;
		mapping[s] = true;
	}
	
	while( cin >> cmd){
		if( cmd == "***") break;
		cin >> s;
		if( cmd == "find" && mapping[s] == true) cout << 1 <<endl;
		else if( cmd == "find" && mapping[s] == false ) cout << 0 << endl;
		else if( cmd == "insert" && mapping[s] == false ){
			cout << 1 << endl;
			mapping[s] = true;
		}
		else if( cmd == "insert" && mapping[s] == true ){
			cout << 0 << endl;
		}
	}
	return 0;
}
