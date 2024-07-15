// For random

#include <bits/stdc++.h>

using namespace std;

const auto seed = chrono::steady_clock::now().time_since_epoch().count();

long long n;
int m;

int main(){
	cout << "For int:\n";
	mt19937 g1(seed);
	for (int i = 1; i <= 10; ++i){
		m = g1();
		cout << m << "\n";
	}
	cout << "\nFor long long:\n";
	mt19937_64 g2(seed);
	for (int i = 1; i <= 10; ++i){
		n = g2();
		cout << n << "\n";
	}
}
