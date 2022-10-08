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

const int N=2e3+7,Mod=998244353,INF=1e9+7;

int T,n,a[N],b[N],t;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);}

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();int ans=0;t=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)if((a[i]%2)==0)b[++t]=a[i];
		for(int i=1;i<=n;i++)if((a[i]%2)==1)b[++t]=a[i];
//		printf("(");
//		for(int i=1;i<=n;i++)printf("%d,",b[i]);
//		printf(")\n");
		
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			
			int x=b[i],y=b[j]*2;//printf("[%d %d]\n",x,y);
			if(gcd(x,y)>1)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}

