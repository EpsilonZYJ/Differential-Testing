#include<iostream>
using namespace std;
using ll = unsigned long long;
const int N = 998244353;

ll solve(ll n, ll f1, ll f2, ll a, ll b, ll c)
{
	if (n == 1)
	{
		return f1;
	}
	else if (n == 2)
	{
		return f2;
	}
	else
	{
		return ((((a % N) * (solve(n - 1, f1, f2, a, b, c) % N) + (((b % N)) * (solve(n - 2, f1, f2, a, b, c) % N)) % N) + c) % N);
	}
}

int main()
{
    freopen("data.txt","r",stdin);
    freopen("1.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, f1, f2, a, b, c;
	cin >> n >> f1 >> f2 >> a >> b >> c;
	ll ans;
	ans = solve(n, f1, f2, a, b, c);

	cout << ans << endl;

	return 0;
}