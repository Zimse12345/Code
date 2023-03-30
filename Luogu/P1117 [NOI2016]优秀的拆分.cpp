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
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e4+7,Mod=998244353,INF=1e9+7;
int T,LG[N],pre[N],nxt[N];
struct SA{
int n,m,height[N],x[N],y[N],sa[N],rk[N],c[N],h[N][16];
char s[N];

inline void SA_init(){
	memset(height,0,sizeof(height));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(sa,0,sizeof(sa));
	memset(rk,0,sizeof(rk));
	memset(c,0,sizeof(c));
	m=122;
	return;
}

inline void Get_SA(){
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>0;i--)sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){
		int it=0;
		for(int i=n-k+1;i<=n;i++)y[++it]=i; 
		for(int i=1;i<=n;i++)if(sa[i]>k)y[++it]=sa[i]-k;
		for(int i=1;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=2;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>0;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y),it=1,x[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=it;
			else x[sa[i]]=++it;
		}
		if(it==n)break;
		m=it;
	}
	return;
}

inline void Get_Height(){
	int k=0;
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	for(int i=1;i<=n;i++){
		if(rk[i]==1)continue;
		if(k)--k;
		int j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])k++;
		height[rk[i]]=k,h[rk[i]][0]=k;
	}
	for(int j=1;j<16;j++)for(int i=1;i<=n;i++)h[i][j]=min(h[i][j-1],h[i-(1<<(j-1))][j-1]);
	return;
}

inline int LCP(int l,int r){
	if(l==r)return sa[l];
	if(r<l)swap(l,r);++l;
	int len=r-l+1,t=LG[len];
	return min(h[r][t],h[l+(1<<t)-1][t]);
}

inline int lcp(int l,int r){
	return LCP(rk[l],rk[r]);
}
}a,b;

signed main(){
	for(int i=2;i<N;i++)LG[i]=LG[i>>1]+1;
	T=read();
	while(T--){
		a.SA_init(),b.SA_init();
		scanf("%s",a.s+1);
		a.n=b.n=strlen(a.s+1);
		int ans=0,n=a.n;
		for(int i=1;i<=n;i++)b.s[i]=a.s[n-i+1];
		a.Get_SA(),b.Get_SA();
		a.Get_Height(),b.Get_Height();
		for(int i=1;i<=n;i++){
			for(int j=i;j+i<=n;j+=i){
				int l=a.lcp(j,j+i),r=b.lcp(n-j+1,n-j-i+1);
				
				if(l+r>=i){
					int k=l+r-i,L,R;
					L=max(j+i+l-k,j+i),R=min(j+i+l-1,j+i*2-1);
					++pre[L],--pre[R+1];
					L=max(j-r+1,j-i+1),R=min(j-r+k,j);
					++nxt[L],--nxt[R+1];
				}
			}
		}
		for(int i=1;i<=n;i++)pre[i]+=pre[i-1],nxt[i]+=nxt[i-1];
		for(int i=1;i<n;i++)ans+=pre[i]*nxt[i+1];
		for(int i=1;i<=n+1;i++)pre[i]=0,nxt[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}

