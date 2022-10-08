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

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int T,n,a[N],b[N];

int main(){
	T=read();
	while(T--){
		n=read();
		int sa=0,sb=0;
		for(int i=1;i<=n;i++)a[i]=read(),sa+=a[i];
		for(int i=1;i<=n;i++)b[i]=read(),sb+=b[i];
		if(sa!=sb)printf("-1\n");
		else{
			int m=0;
			for(int i=1;i<=n;i++)m+=abs(a[i]-b[i]);
			m/=2;
			printf("%d\n",m);
			
			int j=1;
			for(int i=1;i<=n;i++)while(a[i]>b[i]){
				while(a[j]>=b[j])++j;
				int c=min(a[i]-b[i],b[j]-a[j]);
				a[j]+=c,a[i]-=c;
				for(int k=1;k<=c;k++)printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}

