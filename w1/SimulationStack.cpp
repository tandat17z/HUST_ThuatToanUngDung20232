#include<bits/stdc++.h>

using namespace std;

string cmd;
int val;
stack<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while( cin >> cmd){
		if( cmd == "#") break;
		
		if( cmd == "PUSH"){
			cin >> val;
			st.push(val);
		}
		else if( cmd == "POP" ){
			if( st.empty()) cout << "NULL" << endl;
			else{
				cout << st.top() << endl;
				st.pop();
			}
		}
	}
	
	return 0;
}
