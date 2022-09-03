#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define MAX_N 3000004
int q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

int main() {
	long long n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i], arr[i] += arr[i - 1];
	}
	head = tail = 0;
	q[tail++] = 0;
	long long ans = arr[1];
	for (int i = 0; i <= n; i++) {
		ans = max(ans, arr[i] - arr[q[head]]);
		while (tail - head && arr[q[tail - 1]] >= arr[i])
			tail--;
		q[tail++] = i;
		if (q[head] == i - m)
			head++;
	}
	cout << ans << endl;
	return 0;
}
//6 4
//1 -3 5 1 -2 3
//7