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

int T,n,mu[N];

int miu(int x){
//	int k=1,y=x,e=0;
//	for(int i=2;i*i<=x;i++)if(x%i==0){
//		k*=i,y/=i;
//		e=i;
//		if(k<N&&y<N)return mu[k]*mu
//	}
//	for(int i=e;i>=2;i++)if(i*i!=x&&x%i){
//		
//	}
return mu[x];
}

int main(){
	mu[1]=-1;
	for(int i=2;i*i<N;i++)for(int j=i*i;j<N;j+=i*i)mu[j]=2;
	for(int i=2;i<N;i++){
		if(mu[i]==2)mu[i]=0;
		else{
			mu[i]=1;
			for(int j=2;j*j<=i;j++)if(i%j==0){
				mu[i]=mu[j]*mu[i/j];
				break; 
			}
		}
	}
	T=read();
	while(T--){
		n=read();
		int v=miu(n);
		if(v==0)printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}

