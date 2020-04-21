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
int lower_bound(int *a, pi range, const int &key)
{
	int start_index = -1;
	while( range.first <= range.second )
	{
		int mid = (range.first + range.second) / 2;
		if (a[mid] == key)
		{
			start_index = mid;
			range.second = mid - 1;
		}
		else if (a[mid] > key)
		{
			range.second = mid - 1;
		}
		else range.first = mid + 1;
	}
	return start_index;
}
int upper_bound(int *a, pi range, const int& key)
{
	int end_index = -1;
	while(range.first <= range.second)
	{
		int mid = (range.first + range.second) / 2;
		if (a[mid] == key)
		{
			end_index = mid;
			range.first = mid + 1;
		}
		else if (a[mid] < key)
		{
			range.first = mid + 1;
		}
		else range.second = mid - 1;
	}
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

		// cout << binary_search(a, {0, n - 1}, key) << endl;
		cout << "first occurence : " << lower_bound(a, {0, n - 1}, key) << endl;
		cout << "last occurence : " << upper_bound(a, {0, n - 1}, key) << endl;
	}
	return 0;
}