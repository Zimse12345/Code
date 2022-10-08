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

const int N=1e5+7,Mod=998244353,INF=1e9+7;

int T,len,m,a[N];
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		len=read(),m=read();
		scanf("%s",s+1);
		int t=0;
		for(int i=1;i<=len;i++)if(s[i]=='1')a[++t]=i;
		if(t>=2)for(int i=1;i<t;i++){
			int L=a[i]+1,R=a[i+1]-1;
			for(int j=1;j<=m;j++){
				if(L>=R)break;
				s[L]=s[R]='1';
				++L,--R;
			}
		}
		
		if(t>=1)for(int i=a[1]-1;i>=1&&i>=a[1]-m;i--)s[i]='1';
		if(t>=1)for(int i=a[t]+1;i<=len&&i<=a[t]+m;i++)s[i]='1';
		for(int i=1;i<=len;i++)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}

