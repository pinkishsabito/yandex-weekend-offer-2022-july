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

bool isbad(char c) {
	return c == '[' || c == ']' || c == ',' || c == ' ' || c == '-';
}

void solve(void) {
	string s; getline(cin, s);
	cout << s << endl;
	map<int, int> cnt;
	for (int i = 0, now = 0, sign = 1; i < s.size(); ++i) {
		if (s[i] == '-')  sign = -1;
		if (isbad(s[i]))  continue;
		now = now * 10 + (s[i] - '0');
		if (isbad(s[i + 1])) {
			now *= sign;
			++cnt[now];
			sign = 1, now = 0;
		}
	}
	map<int, vector<int>> all;
	int maxi = 0;
	for (auto to: cnt) {
		maxi = max(maxi, to.second);
		all[to.second].push_back(to.first);
	}
	sort(all[maxi].begin(), all[maxi].end());
	for (auto to: all[maxi]) {
		cout << to << ' ';
	}
	cout << endl;
}

/*
stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/