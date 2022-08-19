#include <bits/stdc++.h>
using namespace std;

const int nMax = 4e6 + 40;

class ST_Min{
	public:
		int tree[nMax];
		int minUtil(int stStart, int stEnd, int qStart, int qEnd, int si);
		int minVal(int n, int qStart, int qEnd);
		void initTree(int arr[], int stStart, int stEnd, int si);
    	void print();
};

void ST_Min::print(){
    for (int i = 0; i < 9; ++i){
        cout << this->tree[i] << " ";
    }
    cout << "\n";
}

int ST_Min::minUtil(int stStart, int stEnd, int qStart, int qEnd, int si){
	if (stEnd < qStart || qEnd < stStart) return INT_MAX;
	if (stEnd <= qEnd && qStart <= stStart) return this->tree[si];
	int stMid = stStart + (stEnd - stStart) / 2;
	return min(this->minUtil(stStart, stMid, qStart, qEnd, 2 * si + 1), this->minUtil(stMid + 1, stEnd, qStart, qEnd, 2 * si + 2));
}

int ST_Min::minVal(int n, int qStart, int qEnd){
	if (qStart < 0 || qEnd < 0 || qStart > n - 1 || qEnd > n - 1 || qStart > qEnd){
		cout << "Invalid input!\n";
		return -1;
	}
	return this->minUtil(0, n - 1, qStart, qEnd, 0);
}

void ST_Min::initTree(int arr[], int stStart, int stEnd, int si){
	if (stStart == stEnd){
		this->tree[si] = arr[stStart];
		return;
	}
	int stMid = stStart + (stEnd - stStart) / 2;
	this->initTree(arr, stStart, stMid, 2 * si + 1);
	this->initTree(arr, stMid + 1, stEnd, 2 * si + 2);
	this->tree[si] = min(this->tree[2 * si + 1], this->tree[2 * si + 2]);
}

int main(){
	// Driver code
}
