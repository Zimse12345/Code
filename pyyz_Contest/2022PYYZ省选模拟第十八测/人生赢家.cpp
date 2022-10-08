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

const int N=2e6+7,Mod=1e9+7,H=1e9+7,HH=19260817;
int n,nd[4],cnt;
char s[N],t[N],p[4]={'A','C','G','T'};
int hd[N],nxt[N*4],hs[N*4],f[N*4],ec;

char g(char l,char r){
	if(r=='A'||r=='C'){
		if(l=='A'||l=='G')return 'A';
		return 'G';
	}
	else{
		if(l=='A'||l=='G')return 'C';
		return 'T';
	}
}

int dfs(int u,int tag){
	if(u>n)return 1;
	int h=0,h2=0;
	if(u>2){
		h=((((((((((t[u-2]*H)+t[u-1])*H)+nd[0])*H)+nd[1])*H)+nd[2])*H+nd[3])*H+tag)*H+u;
		h2=((((((((((t[u-2]*HH)+t[u-1])*HH)+nd[0])*HH)+nd[1])*HH)+nd[2])*HH+nd[3])*HH+tag)*HH+u;
		h=(h%N+N)%N;
		for(int i=hd[h];i;i=nxt[i])if(hs[i]==h2)return f[i];
	}
	int res=0;
	for(int i=0;i<4;i++){
		t[u]=p[i];
		if(u>2&&g(t[u-2],t[u])!=t[u-1])continue;
		if(tag&&t[u]>s[u])continue;
		if(nd[i]==0)continue;
		--nd[i];
		if(tag&&s[u]==t[u])res+=dfs(u+1,1);
		else res+=dfs(u+1,0);
		++nd[i];
	}
	res%=Mod;
	if(u>2)nxt[++ec]=hd[h],hd[h]=ec,hs[ec]=h2,f[ec]=res;
	return res;
}

signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)for(int j=0;j<4;j++)if(s[i]==p[j])++nd[j];
	cnt=dfs(1,1);
	printf("%lld\n",(cnt+Mod)%Mod);
	return 0;
}

