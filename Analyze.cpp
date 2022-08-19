#include <bits/stdc++.h>
using namespace std;

const int Max = 1e6 + 10;

bool isPrime[Max];
vector<int> prime;
int analyze[Max];

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
    int i = 0;
    while (a > 1){
        if (a % prime[i] == 0){
            while (a % prime[i] == 0){
                a /= prime[i];
                analyze[prime[i]]++;
            }
        }
        i++;
    }
}

int main(){
	eratos();
    int a;
    cin >> a;
    analyzeNumber(a);
    for (int i = 0; i <= 1e6; ++i){
        if (isPrime[i] && analyze[i]){
            cout << i << " " << analyze[i] << "\n";
        }
    }
}
