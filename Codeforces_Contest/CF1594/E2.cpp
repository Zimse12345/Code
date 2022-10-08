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

const int N=5e5+7,Mod=1e9+7,INF=1e9+7;
int k,m,f[N],cnt=1,rt=1,ch[N][2],_2[N],d[N],g[N][7],v[N];
int T[N],h;
struct p{
	int x,cl;
	p(int x=0,int cl=0):x(x),cl(cl){};
	bool operator < (const p& A)const{return x<A.x;}
}b[N];
char s[N];

void dfs(int u,int dp){
	if((!ch[u][0])&&(!ch[u][1])){
		if(d[u])g[u][d[u]]=f[dp];
		else for(int i=1;i<=6;i++)g[u][i]=f[dp];
		return;
	}
	if(ch[u][0])dfs(ch[u][0],dp-1);
	if(ch[u][1])dfs(ch[u][1],dp-1);
	int L=ch[u][0],R=ch[u][1];
	for(int i=1;i<=6;i++)g[0][i]=f[dp-1];
	for(int l=1;l<=6;l++){
		for(int r=1;r<=6;r++){
			for(int i=1;i<=6;i++){
				if(d[u]&&i!=d[u])continue; 
				if((i==1||i==2)&&(r==1||r==2||l==1||l==2))continue;
				if((i==3||i==4)&&(r==3||r==4||l==3||l==4))continue;
				if((i==5||i==6)&&(r==5||r==6||l==5||l==6))continue;
				g[u][i]=(g[u][i]+g[L][l]*g[R][r])%Mod;
			}
		}
	}
	return;
}

signed main(){
	k=read(),m=read();
	_2[0]=1;
	for(int i=1;i<=k;i++)_2[i]=_2[i-1]*2ll;
	f[1]=1;
	for(int i=2;i<=k;i++){
		f[i]=f[i-1]*f[i-1]%Mod*16%Mod;
	}
	for(int i=1,x,cl;i<=m;i++){
		x=read();
		scanf("%s",s+1);
		if(s[1]=='w')cl=1;
		if(s[1]=='y')cl=2;
		if(s[1]=='g')cl=3;
		if(s[1]=='b')cl=4;
		if(s[1]=='r')cl=5;
		if(s[1]=='o')cl=6;
		b[i]=p(x,cl);
	}
	sort(b+1,b+m+1);
	v[1]=1;
	for(int i=1;i<=m;i++){
		int val=1;
		int x=b[i].x,id=rt;
		h=0;
		while(x)T[++h]=x&1ll,x/=2;
		for(int j=h-1;j>=1;j--){
			int o=T[j];
			if(!ch[id][o])ch[id][o]=++cnt;
			id=ch[id][o];
			
			if(o==2)val=val*2+1;
			else val=val*2;
			v[id]=val;
			if(val==x)break;
		}
		d[id]=b[i].cl;
	}
	dfs(1,k);
	int ans=0;
	for(int i=1;i<=6;i++)ans=(ans+g[rt][i])%Mod;
	printf("%lld\n",ans);
	return 0;
}
