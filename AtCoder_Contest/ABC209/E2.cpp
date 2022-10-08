#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 4e5 + 5;
int n, len, tot, d[MAXN], vis[MAXN], a[MAXN], b[MAXN];
vector <int> v[MAXN];
string s, s1, s2;
map <string, int> mp;
queue <int> que;
int main() {
	freopen("d.in","r",stdin);
	freopen("d2.out","w",stdout);
	
	scanf("%d", &n); memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= n; i ++) {
		s.clear(); cin >> s; len = s.length(); s1.clear(); s2.clear();
		s1 += s[0]; s1 += s[1]; s1 += s[2]; s2 += s[len - 3]; s2 += s[len - 2]; s2 += s[len - 1];
//		cout << s1 << ' ' << s2 << endl;
		if(mp.find(s1) == mp.end()) mp[s1] = ++ tot;
		if(mp.find(s2) == mp.end()) mp[s2] = ++ tot;
		a[i] = mp[s1]; b[i] = mp[s2];
		v[b[i]].push_back(a[i]); d[a[i]] ++; 
	}
	for(int i = 1; i <= tot; i ++) if(!d[i]) que.push(i), vis[i] = 0;
	while(!que.empty()) {
		int t = que.front(); que.pop();
		for(int i = 0; i < v[t].size(); i ++) {
			int q = v[t][i]; d[q] --;
			if(vis[q] != 1) {
				if(vis[t] == 0) { vis[q] = 1; que.push(q); continue; }
				if(!d[q]) que.push(q), vis[q] = 0; 	
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(vis[b[i]] == 0) printf("Takahashi\n");
		else if(vis[b[i]] == 1) printf("Aoki\n");
		else printf("Draw\n");
	}
	return 0;
}
