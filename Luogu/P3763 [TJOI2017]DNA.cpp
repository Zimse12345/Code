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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,_lg[N],ans;
char s0[N],s[N];

struct SA{
int len,sz,height[N],x[N],y[N],sa[N],rk[N],c[N],h[18][N];
char str[N];

inline void get_sa(){
	sz=128;
	for(int i=1;i<=sz;i++)c[i]=0;
	for(int i=1;i<=len;i++)x[i]=str[i],c[x[i]]++;
	for(int i=2;i<=sz;i++)c[i]+=c[i-1];
	for(int i=len;i;i--)sa[c[x[i]]--]=i;
	for(int k=1,it;k<=len;k*=2){
		it=0;
		for(int i=len-k+1;i<=len;i++)y[++it]=i;
		for(int i=1;i<=len;i++)if(sa[i]>k)y[++it]=sa[i]-k;
		for(int i=1;i<=sz;i++)c[i]=0;
		for(int i=1;i<=len;i++)c[x[i]]++;
		for(int i=2;i<=sz;i++)c[i]+=c[i-1];
		for(int i=len;i;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y),it=1,x[sa[1]]=1;
		for(int i=2;i<=len;i++){
			if(sa[i]+k<=len&&sa[i-1]+k<=len&&y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=it;
			else x[sa[i]]=++it;
		}
		if(it==len)break;
		sz=it;
	}
	return;
}

void get_height(){
	for(int i=1;i<=len;i++)rk[sa[i]]=i;
	for(int i=1,j,k=0;i<=len;i++){
		if(rk[i]==1)continue;
		if(k)--k;
		j=sa[rk[i]-1];
		while(j+k<=len&&i+k<=len&&str[i+k]==str[j+k])++k;
		height[rk[i]]=k,h[0][rk[i]]=k;
	}
	for(int j=1;j<18;j++)for(int i=(1<<j);i<=len;i++)h[j][i]=min(h[j-1][i],h[j-1][i-(1<<(j-1))]);
	return;
}

int lcp(int l,int r){
	if(l==r)return len-l+1;
	l=rk[l],r=rk[r];
	if(r<l)swap(l,r);++l;
	int t=_lg[r-l+1];
	return min(h[t][r],h[t][l+(1<<t)-1]);
}
}sa;

signed main(){
	for(int i=2;i<N;i++)_lg[i]=_lg[i/2]+1;
	T=read();
	while(T--){
		scanf("%s %s",s0+1,s+1),ans=0;
		n=strlen(s0+1),m=strlen(s+1);
		sa.len=0;
		for(int i=1;i<=n;i++)sa.str[++sa.len]=s0[i];
		for(int i=1;i<=m;i++)sa.str[++sa.len]=s[i];
		sa.get_sa();
		sa.get_height();
		for(int i=1;i<=n-m+1;i++){
			int len=0;
			for(int j=1;j<=4;j++){
				int p=sa.lcp(n+len+1,i+len);
				len+=p;
				if(j!=4)++len;
				if(len>=m)break;
			}
			if(len>=m)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}

