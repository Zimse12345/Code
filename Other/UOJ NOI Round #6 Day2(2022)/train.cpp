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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,p,a[N],f[N],_f[N];
vector<int> s[N],_s[N];

inline int mod(int x){
	x%=p;
	if(x<0)x+=p;
	return x;
}

void sol(int l,int r){
	for(int i=0;i<p;i++)f[i]=0,s[i].resize(0);
	unsigned cnt=0;
	for(int i=l;i<=r;i++){
		++cnt;
		if(!f[a[i]])f[a[i]]=1,s[a[i]].resize(cnt),s[a[i]][cnt-1]=1;
		if(!f[p-a[i]])f[p-a[i]]=1,s[p-a[i]].resize(cnt),s[p-a[i]][cnt-1]=-1;
		for(int j=0;j<p;j++)if(f[j]&&s[j].size()<cnt){
			if(!f[mod(j+a[i])])f[mod(j+a[i])]=1,s[mod(j+a[i])]=s[j],s[mod(j+a[i])].push_back(1);
			if(!f[mod(j-a[i])])f[mod(j-a[i])]=1,s[mod(j-a[i])]=s[j],s[mod(j-a[i])].push_back(-1);
		}
		for(int j=0;j<p;j++)if(s[j].size()<cnt)s[j].push_back(0);
//		printf("[%lld]\n",i);
//		for(int j=0;j<p;j++){
//			printf("%lld>  ",f[j]);
//			for(unsigned k=0;k<s[j].size();k++)printf("%lld ",s[j][k]);
//			printf("\n");
//		}
//		printf("\n\n");
	}
	return;
}

signed main(){
	n=read(),p=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){
		if(a[1]%p==0)printf("1\n");
		else printf("IMPOSSIBLE\n");
		return 0;
	}
	int m=n/2;
	sol(1,m);
	for(int i=0;i<p;i++)_f[i]=f[i],_s[i]=s[i];
	sol(m+1,n);
//	for(int i=0;i<p;i++)printf("[%lld %lld %lld]\n",i,_f[i],f[i]);
	int sum=0,k=0;
	for(int i=0;i<p;i++)if(f[i]&_f[p-i]){
		for(unsigned j=0;j<_s[p-i].size();j++)printf("%lld ",_s[p-i][j]);
		for(unsigned j=0;j<s[i].size();j++)printf("%lld ",s[i][j]),sum+=a[++k]*s[i][j];
		printf("\n");
		return 0;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}

