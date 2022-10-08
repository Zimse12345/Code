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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,x,a[N],mx[N],mi[N],t,c[N];

signed main(){
	n=read(),k=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	
	int l=1;
	for(int r=2;r<=n;r++){
		if(a[r]-a[r-1]>x)mi[++t]=a[l],mx[t]=a[r-1],l=r;
	}mi[++t]=a[l],mx[t]=a[n];
	
	for(int i=1;i<t;i++){
		c[i]=(mi[i+1]-mx[i]-1)/x;
	}sort(c+1,c+t);
	
	int L=0;
	for(int i=1;i<t;i++){
		if(k-c[i]>=0)k-=c[i],L=i;
		else break;
	}
	int rm=t-L;
	printf("%lld\n",rm);
	
	return 0;
}
