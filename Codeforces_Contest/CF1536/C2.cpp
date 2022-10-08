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
 
const int N=5e5+7,Mod=998244353,INF=1e9+7;
 
int T,n,d[N],k[N],a[N];
char s[N];
 int tot;
 
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);}
 
int main(){
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		n=read();
		scanf("%s",s+1);
		int D=0,K=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='D')d[++D]=i;
			else k[++K]=i;
			if(D==0||K==0){
				a[i]=i;
				continue;
			}
			
			int g=gcd(D,K);
			if(g==1){
				a[i]=1;
				continue;
			}
			int _d=0,_k=0;
			a[i]=1;
			while(1){++tot;
				_d+=D/g,_k+=K/g;
				if(_d>D)break;
				int ld=d[D-_d+1],lk=k[K-_k+1];
				int m=min(ld,lk),G=_d+_k;
				if(i-m+1==G){
					a[i]=a[m-1]+1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d \n",a[i]);
		printf("\n");
	}
	printf("[%d]",tot);
	return 0;
}
