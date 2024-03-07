#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long

string cmd;
bool checkNum = true;
int cnt = 0;
unordered_map<string, int> numCallsFrom;
unordered_map<string, ull> cntTimeCallsFrom;


ull computeTime(string t1, string t2){
	int h1 = stoi(t1.substr(0, 2)),
		m1 = stoi(t1.substr(3, 2)), 
		s1 = stoi(t1.substr(6, 2));
		
	int h2 = stoi(t2.substr(0, 2)),
		m2 = stoi(t2.substr(3, 2)), 
		s2 = stoi(t2.substr(6, 2));
		
	ull t = 0;
	if( h2 > h1) {
		t = 60*60*(h2 - h1 - 1) 
			+ 60*( 60 - m1 - 1) + (60 - s1)
			+ 60*m2 + s2;
	}
	else if( m2 > m1){
		t = 60*(m2 - m1 - 1) + 60 - s1 + s2;
	}
	else {
		t = s2 - s1;
	}
	return t;
		
}
bool check(string std){
	if( std.size() != 10) return false;
	for( auto c: std){
		if( c < '0' || c >'9')  return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input/data1.txt", "r", stdin);
	while( cin >> cmd){
		if( cmd == "call" ){
			cnt += 1;
			string sdt1, sdt2, date, t1, t2;
			cin >> sdt1 >> sdt2 >> date >> t1 >> t2;
			
			if( check(sdt1) && check(sdt2)){
				numCallsFrom[sdt1] += 1;
				cntTimeCallsFrom[sdt1] += computeTime(t1, t2);
			}
			else checkNum = false;
			
		}
		else if( cmd == "?check_phone_number"){
			if( checkNum ) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if( cmd == "?number_calls_from"){
			string sdt;
			cin >> sdt;
			cout << numCallsFrom[sdt] << endl;
		}
		else if( cmd == "?number_total_calls"){
			cout << cnt << endl;
		}
		else if( cmd == "?count_time_calls_from"){
			string sdt;
			cin >> sdt;
			cout << cntTimeCallsFrom[sdt] << endl;
		}
		
	}
	return 0;
}
