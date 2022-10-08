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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],ans;
int L1[N],L2[N],R1[N],R2[N],s[N],w[N],t,to[N];

signed main(){
	scanf("%d",&T);
	
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){
			printf("1\n");
			continue;
		}
		if(n==2){
			printf("3\n");
			continue;
		}
		
		t=0,s[t]=-INF,w[0]=0;
		for(int i=1;i<=n;i++){
			while(a[i]<s[t])--t;
			L1[i]=w[t];
			s[++t]=a[i],w[t]=i;
		}
		t=0,s[t]=-INF,w[0]=n+1;
		for(int i=n;i>=1;i--){
			while(a[i]<s[t])--t;
			R1[i]=w[t];
			s[++t]=a[i],w[t]=i;
		}
		
		t=0,s[t]=INF,w[0]=0;
		for(int i=1;i<=n;i++){
			while(a[i]>s[t])--t;
			L2[i]=w[t];
			s[++t]=a[i],w[t]=i;
		}
		t=0,s[t]=INF,w[0]=n+1;
		for(int i=n;i>=1;i--){
			while(a[i]>s[t])--t;
			R2[i]=w[t];
			s[++t]=a[i],w[t]=i;
		}
		
		for(int i=1;i<=n;i++)to[i]=0;
		for(int i=1;i<=n;i++)to[R2[i]]=max(L1[i],to[R2[i]]),to[R1[i]]=max(L2[i],to[R1[i]]);
		for(int i=1;i<=n;i++)to[i]=max(to[i-1],to[i]),ans+=i-to[i];
		printf("%lld\n",ans);
	}
	return 0;
}

