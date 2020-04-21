#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pi std::pair<int, int>
#define vi std::vector<int>
#define pq std::priority_queue<int>
#define vii std::vector<std::vector<int> >
#define db1(x) cout<<#x<<" = "<<x<<endl;
#define db2(x,y) cout<<#x<<" = "<<x<<"\t"<<#y<<" = "<<y<<endl;
#define db3(x,y,z) cout<<#x<<" = "<<x<<"\t"<<#y<<" = "<<y<<"\t"<<#z<<" = "<<z<<endl;
#define rep(i,n) for(int i = 0; i < n; i++)
#define repL(s,n) for(int i = s; i < n; i++)


int binary_search(int *a, pi range, const int& key)
{
	int ans = -1;
	if (range.first <= range.second)
	{
		int mid = (range.first + range.second) / 2;
		if (a[mid] == key) // key found
			ans = mid;
		else if (a[mid] > key) // go left
			ans = binary_search(a, {range.first, mid - 1}, key);
		else ans = binary_search(a, {mid + 1, range.second}, key);
	}
	return ans;
}

int findHigherPos(int *a, const int& n, const int& key)
{
	int l = 0, h = 1;
	while(h < n && key > a[h])
	{
		h = min(2*h, n);
	}
	return h;
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, key;
		cin >> n >> key;
		int a[n];
		int i = 0;
		rep(i,n)
			cin >> a[i];

		int l = 0;
		int h = findHigherPos(a, n, key);
		cout << "item found at location : "<< binary_search(a, {l, h}, key) << endl;
	}
	return 0;
}