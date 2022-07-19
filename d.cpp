#pragma optimize("g", on)
#pragma GCC optimize("inline", "Ofast", "unroll-loops", "03")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
using namespace std;

/*
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2> using ordered_map = tree<T1, T2, less<T1>, rb_tree_tag, tree_order_statistics_node_update>;
*/

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define x first
#define y second
#define debug(x) cerr << '[' << #x << '=' << x << "]\n"

long long read() {
	bool Minus = false;
	long long result = 0;
	char ch = getchar();
	while (true) {
		if (ch == '-')  break;
		if (ch >= '0' && ch <= '9')  break;
		ch = getchar();
	}
	ch == '-' ? Minus = true : result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9')  break;
		result = result*10+ch-'0';
	}
	return Minus ? -result : result;
}
 
typedef long long LL;
 
void solve(void);

int main(void) {
	#ifdef local
		freopen("stdin", "r", stdin);
		// freopen("stdout", "w", stdout);
	#endif
	// freopen("stderr", "w", stderr);
	solve();
	return 0;
}

const int oo = 0x7fffffff, MaxN = 1e5, Mod = 1e9+7;

#define int LL

void solve(void) {
	int n = read();
	set<pair<pair<int, int>, int>> s;
	map<int, pair<int, int>> id;
	for (int i = 0; i < n; ++i) {
		int t = read();
		if (t == 1) {
			int a = read(), d = read(), x = read();
			id[x] = {a, d};
			s.insert({{a, x}, d});
		}
		else if (t == 2) {
			int x = read();
			s.erase(s.find({{id[x].first, x}, id[x].second}));
			id.erase(id.lower_bound(x));
		}
		else {
			auto now = *s.begin();
			cout << now.first.first << endl;
			s.erase(s.begin());
			now.first.first += now.second;
			s.insert(now);
			id[now.first.second] = {now.first.first, now.second};
		}
	}
}

#undef int

/*
stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/