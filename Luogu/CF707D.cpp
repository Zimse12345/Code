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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e3+7,M=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,a[N][N],b[N],c[N],ans;
vector<int> ch[M];

struct opt{
	int ty,i,j,ans;
	opt(int ty=0,int i=0,int j=0):ty(ty),i(i),j(j){}
}op[M];

void dfs(int u){
	int ty=op[u].ty,x=op[u].i,y=op[u].j,c1=0,c2=0;
	if(ty==1)if((a[x][y]^b[x])==0)a[x][y]^=1,++ans,++c[x],c1=1;
	if(ty==2)if((a[x][y]^b[x])==1)a[x][y]^=1,--ans,--c[x],c2=1;
	if(ty==3)b[x]^=1,ans+=m-c[x]*2,c[x]=m-c[x];
	op[u].ans=ans;
	
	for(int i=0;i<int(ch[u].size());i++)dfs(ch[u][i]);
	
	if(ty==2&&c2)a[x][y]^=1,++ans,++c[x];
	if(ty==1&&c1)a[x][y]^=1,--ans,--c[x];
	if(ty==3)b[x]^=1,ans+=m-c[x]*2,c[x]=m-c[x];
	return;
}

int main(){
	n=read(),m=read(),q=read();
	
	for(int i=1,ty,x,y;i<=q;i++){
		ty=read(),x=read(),y=0;
		if(ty==4){
			op[i]=opt(4,0,0);
			ch[x].push_back(i);
		}
		else{
			if(ty<3)y=read();
			op[i]=opt(ty,x,y);
			ch[i-1].push_back(i);
		}
	}
	dfs(0);
	for(int i=1;i<=q;i++)printf("%d\n",op[i].ans);
	return 0;
}
