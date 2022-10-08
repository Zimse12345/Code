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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;

struct opt{
	int x1,y1,x2,y2;
	opt(int x1=0,int y1=0,int x2=0,int y2=0):x1(x1),y1(y1),x2(x2),y2(y2){}
}ans[N];

int T,n,a[N],b[N];
int vis[N],cnt;
vector<int> to[N],ch[N];

int mt(int rt){
	vis[rt]=1;
	for(int i=0;i<to[rt].size();i++)if(!vis[to[rt][i]])ch[rt].push_back(to[rt][i]),mt(to[rt][i]);
}

int sol(int rt){
	if(ch[rt].size()==0)return rt;
	int T=0;
	for(int i=0;i<ch[rt].size();i++){
		int v=ch[rt][i];
		int vr=sol(v);
		if(i==0){
			T=vr;
			continue;
		}
		if(rt==a[1]&&(i==ch[rt].size()-1))continue;
		ans[++cnt]=opt(rt,v,T,v);
		T=vr;
	}
	return T;
}

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;i++)a[i]=read(),b[i]=read(),to[a[i]].push_back(b[i]),to[b[i]].push_back(a[i]);
		mt(a[1]);
		sol(a[1]);
		
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
		}
		
		for(int i=1;i<=n;i++){
			to[a[i]].resize(0),to[b[i]].resize(0);
			ch[a[i]].resize(0),ch[b[i]].resize(0);
			vis[a[i]]=0,vis[b[i]]=0;
			to[i].resize(0),to[i].resize(0);
			ch[i].resize(0),ch[i].resize(0);
			vis[i]=0,vis[i]=0;
		}
		cnt=0;
	}
	return 0;
}
