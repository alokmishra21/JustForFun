#include <bits/stdc++.h>
using namespace std;

#define us unsigned short
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

int main()
{
	ios::sync_with_stdio(0);
    string s;
    cin >> s;
    s += "$";
    int n = s.length();
    vector<int> c(n), p(n);
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            p[i] = a[i].second;
        // assign classes
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
    }
    int k = 0;
    while((1 << k ) < n)
    {
        std::vector<pair<pair<int,int>, int> > a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].first.first = c[i];
            a[i].first.second = c[(i + (1 << k)) % n];
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
            if (a[i].first.first == a[i - 1].first.first && a[i].first.second == a[i - 1].first.second)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        k++;
    }
    // print the suffices
    for (int i = 0; i < n; i++)
        cout << p[i] << "\t" << s.substr(p[i], n - p[i]) << endl;
	return 0;
}

/*
 * TC : O( n log ^2 n )
 * input : ababba
 * output : 6	$
 *          5   a$
 *          0	ababba$
 *          2	abba$
 *          4	ba$
 *          1	babba$
 *          3	bba$
 */
