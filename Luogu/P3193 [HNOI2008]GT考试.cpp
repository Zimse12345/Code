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

const int N=1e2+7,INF=1e9+7;
int n,m,Mod,fa[N];
char s[N];
struct mx{int a[N][N];}x,ans;

mx mul(mx A,mx B){
	mx res;
	for(int i=0;i<m;i++)for(int j=0;j<m;j++){
		res.a[i][j]=0;
		for(int k=0;k<m;k++)res.a[i][j]=(res.a[i][j]+A.a[i][k]*B.a[k][j])%Mod;
	}
	return res;
}

int main(){
	n=read(),m=read(),Mod=read();
	scanf("%s",s+1);
	fa[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j>0&&s[i]!=s[j+1])j=fa[j];
		if(s[i]==s[j+1])++j;
		fa[i]=j;
	}
	for(int i=0;i<=9;i++){
		for(int j=0;j<m;j++){
			int k=j;
			while(k>0&&s[k+1]-'0'!=i)k=fa[k];
			if(s[k+1]-'0'==i)++k;
			++x.a[k][j];
		}
	}
	ans.a[0][0]=1;
	//n=1;
	while(n){
		if(n&1)ans=mul(x,ans);
		x=mul(x,x),n/=2;
	}
	int cnt=0;
	for(int i=0;i<m;i++)cnt=(cnt+ans.a[i][0])%Mod;
	printf("%d\n",cnt);
	return 0;
}
