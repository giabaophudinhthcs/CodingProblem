#include <bits/stdc++.h>

using namespace std;

int k[10];

int main(){
	string s;
	int n, m = 0, t, a = 0, v;
	cin >> n >> s;
	if (n == 0 && s == "0"){
	    cout << "OK";
	    return 0;
	}
	else if (s[0] == '0'){
		cout << "WRONG_ANSWER";
		return 0;
	}
	for (int i = 0; i < int(s.length()); ++i){
		char t = s[i];
		int x = int(t) - 48;
		m = 10 * m + x;
	}
	t = n;
	while (t != 0){
		k[t % 10]++;
		t /= 10;
	}
	for (int i = 1; i <= 9; ++i){
		if (k[i]){
			v = i;
			break;
		}
	}
	a = 10 * a + v;
	k[v]--;
	for (int i = 1; i <= k[0]; ++i) a *= 10;
	for (int i = 1; i <= 9; ++i){
		if (k[i]){
			for (int j = 1; j <= k[i]; ++j) a = 10 * a + i;
		}
	}
	cout << (a == m ? "OK" : "WRONG_ANSWER");
}
