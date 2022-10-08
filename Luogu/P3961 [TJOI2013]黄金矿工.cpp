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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
struct Gold{
	int x,y,t,v,tag;
	Gold(int x=0,int y=0,int t=0,int v=0,int tag=0):x(x),y(y),t(t),v(v),tag(tag){}
	bool operator < (const Gold& A)const{return x*A.x<y*A.y;}
}g[N]; 
int n,t,f[N],h[N],ans;
vector<int> a[N];

signed main(){
	n=read(),t=read();
	for(int i=1,x,y,t,v;i<=n;i++){
		x=read(),y=read(),t=read(),v=read(),g[i]=Gold(x,y,t,v,i);
		for(int j=1;j<i;j++)if(g[i].y*g[j].x==g[i].x*g[j].y){g[i].tag=j;break;}
		a[g[i].tag].push_back(i);
	}
	for(int i=1;i<=n;i++)if(g[i].tag==i){
		sort(a[i].begin(),a[i].end());
		for(int k=0;k<=t;k++)h[k]=f[k];
		for(int j=0,c=0,v=0;j<signed(a[i].size());j++){
			c+=g[a[i][j]].t,v+=g[a[i][j]].v;
			for(int k=c;k<=t;k++)h[k]=max(h[k],f[k-c]+v);
		}
		for(int k=0;k<=t;k++)f[k]=h[k];
	}
	for(int i=0;i<=t;i++)ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}
