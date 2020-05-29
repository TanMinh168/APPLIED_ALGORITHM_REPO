#include <bits/stdc++.h>
using namespace std;
int main() {
	int T,n,tmp;
	long long int res;
	cin >> T;
	int cnt = 0;
	while(T--)
	{
		res = 0;
		cin >> n;
		vector<int> a1,a2;
		for(int i=0; i < n; ++i)
		{
			cin >> tmp;
			a1.push_back(tmp);
		}
		for(int i=0; i < n; ++i)
		{
			cin >> tmp;
			a2.push_back(tmp);
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		for(int i=0; i < n; ++i)
		{res+=(((long long)a1[i])*((long long)a2[n-i-1]));}
		printf("Case #%d: %lld\n", ++cnt, res);
	}
	return 0;
}
