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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,height[N],x[N],y[N],sa[N],rk[N],c[N];
char s[N];

void Get_SA(){
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
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

void Get_Height(){
	int k=0;
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	for(int i=1;i<=n;i++){
		if(rk[i]==1)continue;
		if(k)--k;
		int j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])k++;
		height[rk[i]]=k;
	}
	return;
}

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1),m=123;
	Get_SA();
	for(int i=1;i<=n;i++)printf("%d ",sa[i]);
	printf("\n");
	return 0;
}

