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
int _lg[N];

struct SA{
int len,sz,height[N],x[N],y[N],c[N],sa[N],rk[N],h[20][N];
char str[N];

void get_sa(){
	sz=128;
	for(int i=1;i<=len;i++)x[i]=str[i];
	for(int i=1;i<=sz;i++)c[i]=0;
	for(int i=1;i<=len;i++)c[x[i]]++;
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
	for(int j=1;j<20;j++)for(int i=(1<<j);i<=len;i++)h[j][i]=min(h[j-1][i],h[j-1][i-(1<<(j-1))]);
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
int n,d,lencnt[N];
char s[N];
ll tot,a[N],b[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};

node find(ll k){
	int len=1;
	while(lencnt[len]<k)k-=lencnt[len],++len;
	for(int i=1;i<=sa.len;i++)if(sa.sa[i]<=n&&a[i]&&b[i]+1<=len){
		--k;
		if(!k)return node(sa.sa[i],sa.sa[i]+len-1);
	}
	return node(0,0);
}

bool check(ll k){
	node p=find(k);
	int len=p.y-p.x+1;
	for(int be=1,ed=n;be<=len;be++,ed++){
		int pos=be;
		int rm=d;
		while(rm--){
			if(pos+len-1>ed)return true;
			if(sa.lcp(pos,p.x)>=len||sa.rk[pos]<sa.rk[p.x])pos+=len;
			else pos+=len-1;
			if(pos>ed)return true;
		}
	}
	return false;
}

signed main(){
	for(int i=2;i<N;i++)_lg[i]=_lg[i/2]+1;
	n=read(),d=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)sa.str[++sa.len]=s[i];
	for(int i=1;i<=n;i++)sa.str[++sa.len]=s[i];
	sa.get_sa();
	sa.get_height();
	for(int i=1,pre=0;i<=sa.len;i++)if(sa.sa[i]<=n){
		int lcp=pre?sa.lcp(pre,sa.sa[i]):0;
		pre=sa.sa[i],b[i]=lcp;
		a[i]=max(0,n-lcp);
		if(a[i])lencnt[lcp+1]++;
		tot+=a[i];
	}
	for(int i=2;i<=n;i++)lencnt[i]+=lencnt[i-1];
	ll L=1,R=tot,ans=0;
	while(L<=R){
		ll M=(L+R)/2;
		if(check(M))ans=M,R=M-1;
		else L=M+1;
	}
	node p=find(ans);
	for(int i=p.x;i<=p.y;i++)printf("%c",sa.str[i]);
	printf("\n");
	return 0;
}

