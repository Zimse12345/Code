#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,m,n,k,a[N],cnt[N],tag;
stack<int> pre,suf;
deque<int> p[N];
set<int> mid;

signed main(){
	T=read();
	while(T--){
		m=read(),n=read(),k=read(),tag=1;
		mid.clear();
		while(!pre.empty())pre.pop();
		while(!suf.empty())suf.pop();
		
		for(int i=1;i<=n;i++)a[i]=read(),++cnt[a[i]];
		for(int i=n;i>=1;i--)suf.push(i);
		
		for(int R=k;R<=m;R++){
			while(p[R].size()){
				int x=p[R].front();
				p[R].pop_front(),mid.erase(x);
				--cnt[a[x]];
			}
			
			while(cnt[R-k+1]&&suf.size()){
				if(signed(mid.size())==k){
					int x=*mid.begin();mid.erase(x);
					pre.push(x),p[a[x]].pop_back();
				}
				int x=suf.top();suf.pop();
				if(a[x]<=R)--cnt[a[x]];
				else p[a[x]].push_front(x),mid.insert(x);
			}
			while(cnt[R-k+1]&&pre.size()&&signed(mid.size())<k){
				int x=pre.top();pre.pop();
				if(a[x]<=R)--cnt[a[x]];
				else p[a[x]].push_back(x),mid.insert(x);
			}
			if(cnt[R-k+1]){tag=0;break;}
		}
		
		for(int i=1;i<=m;i++)p[i].clear(),cnt[i]=0;
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

