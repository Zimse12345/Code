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

const int N=1e4+7,Mod=998244353,INF=1e9+7;

int T,n,a[N];
priority_queue<int> Q;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i]>=0){
			sum+=a[i],++ans;
			if(a[i]<0)Q.push(-a[i]);}
		else if(!Q.empty()){
			int p=-Q.top();
			if(a[i]>p){
				Q.pop(),Q.push(-a[i]);
				sum-=p,sum+=a[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

