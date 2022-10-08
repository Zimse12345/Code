#include <bits/stdc++.h>
#include "silent.h"

const int N=200;
int TAG,q[N],fa[N],sz[N],p;
int s1[N],s2[N],t1,t2,vis[N][N];
char s[N];
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}
std::vector<int> qu;
std::string ans;

void my_init(int n){
	TAG=1,t1=t2=p=0,s[n]='\0';
	qu.clear();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)vis[i][j]=0;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,qu.push_back(0),s[i-1]='0';
	return;
}

void link(int x,int y,int n){
	x=F(x),y=F(y);
	if(x^y)fa[y]=x,sz[x]+=sz[y];
	if(sz[x]*2>n)p=1;
	return;
}

void solve(int n, char tp){
	srand(time(0));
	if(n==1){
		s[0]='1';
		s[1]='\0';
		ans=s;
		answer(ans);
		return;
	}
	if(!TAG)my_init(n);
	
	for(int t=1;t<=100;t++){
		for(int i=1,j;i<=n;i++){
			q[i]=i,j=rand()%i+1;
			std::swap(q[i],q[j]);
			int T=100000;
			while(T>0&&i>2&&i%2==0&&(vis[q[i]][q[i-1]]||vis[F(q[i])][F(q[i-1])]||F(q[i])==F(q[i-1])))--T,j=rand()%i+1,std::swap(q[i],q[j]);
		}
		for(int i=1;i*2<=n;i++){
			qu[q[i*2]-1]=q[i*2-1],vis[q[i*2-1]][q[i*2]]=1,vis[F(q[i*2-1])][F(q[i*2])]=1;
			qu[q[i*2-1]-1]=q[i*2],vis[q[i*2]][q[i*2-1]]=1,vis[F(q[i*2])][F(q[i*2-1])]=1;
		}
		if(n&1)qu[q[n]-1]=0;
		std::string str=query(qu);
		for(int i=1;i*2<=n;i++){
			if(str[q[i*2]-1]=='1'&&str[q[i*2-1]-1]=='1')link(q[i*2-1],q[i*2],n);
		}
		if(p)break;
	}
	
	for(int i=1;i<=n;i++){
		if(sz[F(i)]*2>n)s1[++t1]=i,s[i-1]='1';
		else s2[++t2]=i;
	}
	for(int i=0;i<n;i++)qu[i]=0;
	for(int i=1;i<=t2;i++)qu[s1[i]-1]=s2[i];
	std::string str=query(qu);
	for(int i=1;i<=t2;i++){
		if(str[s1[i]-1]=='1')s[s2[i]-1]='1';
	}
	ans=s;
	answer(s),TAG=0;
	return;
}
