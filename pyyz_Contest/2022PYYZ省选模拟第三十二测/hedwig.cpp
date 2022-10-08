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
int n,d,q,typ,a[N],b[N],c[N],ans[N],vis[N],Ans[N];
struct qu{int id,pos;qu(int id=0,int pos=0):id(id),pos(pos){}};
vector<qu> Q[N];

signed main(){
	n=read(),d=read(),q=read(),typ=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r;i<=q;i++){
		l=read(),r=read();
		Q[r].push_back(qu(i,l));
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]%d;
		c[i]=a[i]/d;
		for(unsigned j=0;j<Q[i].size();j++){
			int l=Q[i][j].pos,ans=0;
			for(int r=i;r>=l;r--){
				int mx=-INF,mn=INF,ct=0;
				for(int p=r;p>=l;p--){
					if(b[p]!=b[r])break;
					mx=max(mx,c[p]),mn=min(mn,c[p]);
					if(!vis[c[p]])vis[c[p]]=1,++ct;
					ans+=(mx-mn+1-ct);
				}
				for(int p=r;p>=l;p--){
					if(b[p]!=b[r])break;
					vis[c[p]]=0;
				}
			}
			Ans[Q[i][j].id]=ans;
		}
//		if(Q[i].size()){
//			int mx=-INF,mn=INF,ct=0;
//			ans[i+1]=0;
//			for(int j=i;j>=1;j--){
//				if(b[j]!=b[i])break;
//				mx=max(mx,c[i]),mn=min(mn,c[i]);
//				if(!vis[c[i]])vis[c[i]]=1,++ct;
//				ans
//			}
//		}
	}
	for(int i=1;i<=q;i++)printf("%lld\n",Ans[i]);
	return 0;
}

