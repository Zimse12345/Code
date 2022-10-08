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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int a[3][3],b[3][3];

bool check(){
	for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(a[i][j]!=b[i][j])return 0;
	return 1;
}

void nxt(){
	if(a[1][1]==0)a[1][1]=a[1][2],a[1][2]=0;
	else if(a[1][2]==0)a[1][2]=a[2][2],a[2][2]=0;
	else if(a[2][2]==0)a[2][2]=a[2][1],a[2][1]=0;
	else if(a[2][1]==0)a[2][1]=a[1][1],a[1][1]=0;
	return;
}

bool h(int x){
	for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(b[i][j]==x){
		b[i][j]=0;
		return 1;
	}
	return 0;
}

signed main(){
	int k=0,k2=0;
	for(int i=1;i<=2;i++)for(int j=1;j<=2;j++){
		a[i][j]=read();
		if(a[i][j]==0)++k;
	}
	
	for(int i=1;i<=2;i++)for(int j=1;j<=2;j++){
		b[i][j]=read();
		if(b[i][j]==0)++k2;
	}
	
	if(k!=k2)return !printf("No");
	
	if(k>1){
		for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(a[i][j]!=0){
			if(!h(a[i][j]))return !printf("No");
		}
		printf("Yes");
		return 0;
	}
	
	
	
	for(int i=1;i<=16;i++){
		if(check())return !printf("Yes");
		nxt();
	}
	printf("No");
	return 0;
}
