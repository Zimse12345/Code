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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,lc[N][N],f[N][N],vis[N][N],p[N][N],tag[N][N];
char s[N];

int dp(int l,int r){
	if(l==r)return f[l][r]=1;
	if(vis[l][r]++)return f[l][r];
	f[l][r]=INF;
	for(int k=l;k<r;k++){
		int s=dp(l,k)+dp(k+1,r);
		if(s<f[l][r])f[l][r]=s,tag[l][r]=1,p[l][r]=k;
	}
	int len=r-l+1;
	for(int k=1;k<=len;k++)if(len%k==0){
		int y=1;
		for(int i=l+k;i<=r;i++)if(s[i]!=s[i-k]){
			y=0;
			break;
		}
		if(y){
			int s=dp(l,l+k-1)+2,x=len/k;
			while(x>0)++s,x/=10;
			if(s<f[l][r])f[l][r]=s,tag[l][r]=2,p[l][r]=k;
		}
	}
	return f[l][r];
}

void print(int l,int r){
	if(l==r)printf("%c",s[l]);
	else if(tag[l][r]==1)print(l,p[l][r]),print(p[l][r]+1,r);
	else if(tag[l][r]==2){
		printf("%d(",(r-l+1)/p[l][r]);
		print(l,l+p[l][r]-1);
		printf(")");
	}
	return;
}

int main(){
	scanf("%s",s+1),n=strlen(s+1);
	dp(1,n);
//	print(1,n);
//	printf("\n");
	printf("%d\n",f[1][n]);
	return 0;
}
