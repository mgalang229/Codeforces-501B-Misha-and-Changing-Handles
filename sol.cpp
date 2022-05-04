#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	set<string> s;
	vector<pair<string, string>> vec(q);
	for (int i = 0; i < q; i++) {
		cin >> vec[i].first >> vec[i].second;
		s.insert(vec[i].first);
		s.insert(vec[i].second);
	}
	vector<string> usernames;
	for (auto& e : s) {
		usernames.push_back(e);
	}
	int n = usernames.size();
	auto Convert = [&](string username) {
		for (int i = 0; i < n; i++) {
			if (username == usernames[i]) {
				return i;
			}
		}
		return -1;
	};
	vector<vector<int>> a(n);
	for (int i = 0; i < q; i++) {
		int u = Convert(vec[i].first);
		int v = Convert(vec[i].second);
		a[u].push_back(v);
	}
	vector<bool> visited(n, false);
	string partner = "";
	function<void(int)> Dfs = [&] (int u) {
		visited[u] = true;
		partner = usernames[u];
		for (int v : a[u]) {
			if (!visited[v]) {
				Dfs(v);
			}
		}
	};
	vector<pair<string, string>> ans;
	for (int i = 0; i < q; i++) {
		int u = Convert(vec[i].first);
		if (!visited[u]) {
			partner = "";
			Dfs(u);
			ans.push_back(make_pair(vec[i].first, partner));
		}
	}
	cout << (int) ans.size() << '\n';
	for (auto& e : ans) {
		cout << e.first << " " << e.second << '\n';
	}
	return 0;
}
