#include <bits/stdc++.h>
using namespace std;

const int Max = 1e6 + 10;

bool isPrime[Max];
vector<int> prime;
vector<pair<int, int>> analyze;

void eratos(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= 1e6; ++i){
		if (isPrime[i]){
			for (int j = i * i; j <= 1e6; j += i) isPrime[j] = false;
		}
	}
	
	for (int i = 0; i <= 1e6; ++i){
		if (isPrime[i]) prime.push_back(i);
	}
}

void analyzeNumber(int a){
    int i = 0, j = 0;
    while (a > 1){
        if (a % prime[i] == 0){
            analyze[j].first = prime[i];
            analyze[j].second = 0;
            while (a % prime[i] == 0){
                a /= prime[i];
                analyze[j].second++;
            }
            j++;
        }
        i++;
    }
}

int main(){
	eratos();
    int a;
    cin >> a;
    analyzeNumber(a);
    for (int i = 0; i < analyze.size(); ++i) cout << analyze[i].first << " " << analyze[i].second << "\n";
}
