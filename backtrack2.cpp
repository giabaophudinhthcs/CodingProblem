#include <bits/stdc++.h>

using namespace std;

int n;
bool use[22];

void printPer(){
    for (int i = 1; i <= n; ++i){
        if (use[i]) cout << i << " ";
    }
    cout << "\n";
}

void back(int i){
    if (i == n + 1){
        printPer();
        return;
    }
    use[i] = false;
    back(i + 1);
    use[i] = true;
    back(i + 1);
}

int main(){
    cin >> n;
    back(1);
    return 0;
}
