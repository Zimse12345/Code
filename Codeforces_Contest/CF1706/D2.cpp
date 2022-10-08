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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,k,a[N],p[N],pre[N],t[N],vis[N];
vector<int> v[N];

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			v[a[i]].push_back(i);
			vis[i]=pre[i]=0;
		}
		int cnt=0,ans=INF;
		for(int l=100000,r=100000;l>=0;l--){
			for(unsigned i=0;i<v[l].size();i++){
				int x=v[l][i];
				if(!vis[x])vis[x]=1,++cnt;
				else --t[pre[x]];
				pre[x]=l,++t[l];
				if(!l)continue;
				int _p=a[x]/l+1;
				if(_p<=k)v[a[x]/_p].push_back(x);
			}
			while(r>l&&!t[r])--r;
			if(cnt==n)ans=min(ans,r-l);
			vector<int> sb;
			swap(sb,v[l]);
		}
		for(int i=0;i<=100000;i++){
			t[i]=vis[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}

