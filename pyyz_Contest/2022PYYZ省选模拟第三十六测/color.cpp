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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],vis[N],s[N],OP[N],X[N],Y[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<=3000){
		while(m--){
			int op=read();
			if(op==1){
				int x=read();
				a[x]=read();
			}
			else{
				int x=read(),ans=0,sum=0;
				if(x>n){
					printf("0\n");
					continue;
				}
				for(int i=1;i<=x;i++){
					if(!vis[a[i]])++sum;
					++vis[a[i]];
				}
				ans+=sum;
				for(int i=x+1;i<=n;i++){
					if(vis[a[i-x]]==1)--sum;
					--vis[a[i-x]];
					if(!vis[a[i]])++sum;
					++vis[a[i]];
					ans+=sum;
				}
				for(int i=n;i>=n-x+1;i--)--vis[a[i]];
				printf("%lld\n",ans);
			}
		}
		return 0;
	}
	int ttag=1;
	for(int I=1;I<=m;I++){
		OP[I]=read(),X[I]=read();
		if(OP[I]==1)Y[I]=read(),ttag=0;
	}
	if(ttag){
		
		return 0;
	}
	for(int x=1;x<=20;x++)if(x<=n){
		int ans=0,sum=0;
		for(int i=1;i<=x;i++){
			if(!vis[a[i]])++sum;
			++vis[a[i]];
		}
		ans+=sum;
		for(int i=x+1;i<=n;i++){
			if(vis[a[i-x]]==1)--sum;
			--vis[a[i-x]];
			if(!vis[a[i]])++sum;
			++vis[a[i]];
			ans+=sum;
		}
		for(int i=n;i>=n-x+1;i--)--vis[a[i]];
		s[x]=ans;
	}
	//m=100;
	for(int I=1;I<=m;I++){
		int op=OP[I];
		if(op==1){
			int pos=X[I],val=Y[I],sum=0;
			for(int x=1;x<=20;x++)if(x<=n){
				sum=0;
				int L=max(pos-x+1,1ll),R=min(n,pos+x-1);
				for(int i=L;i<=L+x-1;i++){
					if(!vis[a[i]])++sum;
					++vis[a[i]];
				}
//				printf("[%d %d %d %d]\n",pos,x,L,L+x-1);
				s[x]-=sum;
				for(int i=L+x;i<=R;i++){
//					printf("[%d %d %d %d]\n",pos,x,i-x+1,i);
					if(vis[a[i-x]]==1)--sum;
					--vis[a[i-x]];
					if(!vis[a[i]])++sum;
					++vis[a[i]];
					s[x]-=sum;
				}
				for(int i=R;i>=R-x+1;i--)--vis[a[i]];
			}
			a[pos]=val;
			for(int x=1;x<=20;x++)if(x<=n){
				sum=0;
				int L=max(pos-x+1,1ll),R=min(n,pos+x-1);
				for(int i=L;i<=L+x-1;i++){
					if(!vis[a[i]])++sum;
					++vis[a[i]];
				}
//				printf("[%d %d %d %d]\n",pos,x,L,L+x-1);
				s[x]+=sum;
				for(int i=L+x;i<=R;i++){
//					printf("[%d %d %d %d]\n",pos,x,i-x+1,i);
					if(vis[a[i-x]]==1)--sum;
					--vis[a[i-x]];
					if(!vis[a[i]])++sum;
					++vis[a[i]];
					s[x]+=sum;
				}
				for(int i=R;i>=R-x+1;i--)--vis[a[i]];
			}
		}
		else printf("%lld\n",s[X[I]]);
	}
	return 0;
}

