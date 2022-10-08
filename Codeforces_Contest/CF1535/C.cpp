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

int T,n;
char s[N];

signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),s[0]='2';
		int ans=0;
		
		int rw=0,rz;
		char la='2';
		for(int i=1;i<=n;i++){
			if(s[i]!=la)++rw;
			if(s[i]=='?')++rz;
			if(s[i]!='?'&&s[i]==la){
				ans+=(rw*(rw+1))/2;   //  printf("(%d)",rw);
				ans-=(rz*(rz+1))/2;
				rw=rz+1;
				la=s[i];
				if(s[i]!='?')rz=0;
				continue;
			}
			
			if(s[i]!='?')rz=0;
			if(la=='0')la='1';
			else if(la=='1')la='0';
			else if(s[i]!='?')la=s[i];
			else la='2';
		}
		ans+=(rw*(rw+1))/2;         //    printf("(%d)",rw);
		
		printf("%lld\n",ans);
	}
	return 0;
}

