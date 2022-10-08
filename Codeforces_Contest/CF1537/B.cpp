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
#define int long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int T,n,m,x,y;
int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),x=read(),y=read();
		int ax1=1,ay1=1,ax2=1,ay2=1,mx=0;
		
		for(int i=1;i<=4;i++)for(int j=1;j<=4;j++){
			int res,x1,y1,x2,y2;
			if(i==1)x1=1,y1=1;
			if(i==2)x1=n,y1=1;
			if(i==3)x1=1,y1=m;
			if(i==4)x1=n,y1=m;
			if(j==1)x2=1,y2=1;
			if(j==2)x2=n,y2=1;
			if(j==3)x2=1,y2=m;
			if(j==4)x2=n,y2=m;
			res=dis(x,y,x1,y1)+dis(x1,y1,x2,y2)+dis(x2,y2,x,y);
			if(res>mx)mx=res,ax1=x1,ax2=x2,ay1=y1,ay2=y2;
		}
		printf("%lld %lld %lld %lld\n",ax1,ay1,ax2,ay2);
	}
	return 0;
}

