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
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;

int k,q,n,a[N],p1[N],p2[N],p[N],nxt[N];
char s[N];

int main(){
	k=read(),n=1<<k;
	scanf("%s",s+1);
	
	int L=1,R=n/2;a[0]=1;
	for(int i=1;i<=n/2;i++){
		if(s[i]=='?')a[i]=2;
		else a[i]=1;
		p1[i]=p2[i]=0;
	}
	
	for(int i=n/2+1;i<n;i++){
		if(s[i]=='0')a[i]=a[L];
		if(s[i]=='1')a[i]=a[L+1];
		if(s[i]=='?')a[i]=a[L]+a[L+1];
		p1[i]=L,p2[i]=L+1;
		
		nxt[L]=nxt[L+1]=i,L+=2;
	}
	nxt[n-1]=-1;
	
	q=read();
	while(q--){
		int w=read();char c=0;
		while(c!='0'&&c!='1'&&c!='?')c=getchar();
		s[w]=c;
		int nc=w;
		while(nc!=-1){
			if(s[nc]=='0')a[nc]=a[p1[nc]];
			if(s[nc]=='1')a[nc]=a[p2[nc]];
			if(s[nc]=='?')a[nc]=a[p1[nc]]+a[p2[nc]];
			nc=nxt[nc];
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}

