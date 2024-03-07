#include<bits/stdc++.h>

using namespace std;

string cmd;
int val;
queue<int> qu;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while( cin >> cmd){
		if( cmd == "#") break;
		
		if( cmd == "PUSH"){
			cin >> val;
			qu.push(val);
		}
		else if( cmd == "POP" ){
			if( qu.empty()) cout << "NULL" << endl;
			else{
				cout << qu.front() << endl;
				qu.pop();
			}
		}
	}
	
	return 0;
}
