#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ull a, b;
	cin >> a >> b;
	
	ull a0 = a % 10, b0 = b % 10;
	ull c = a / 10 + b / 10 + (a0 + b0)/ 10;
	
	if( c == 0) cout << a + b;
	else cout << c << (a0 + b0) % 10;
	return 0;
}
