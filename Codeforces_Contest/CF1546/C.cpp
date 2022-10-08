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
int T,n,a[N];
vector<int> v[N];

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		for(int i=1;i<N;i++)v[i].clear();
		for(int i=1;i<=n;i++)a[i]=read(),v[a[i]].push_back(i);
		
		int rk=0,y=1;
		for(int i=1;i<N;i++)if(v[i].size()){
			int cnt=v[i].size();
		
			//rk+1~rk+cnt
			int k1=(rk+cnt+1)/2-(rk+1)/2,k2=(rk+cnt)/2-rk/2;//	printf("[ %d %d %d %d]\n",rk,cnt,k1,k2);
			for(int j=0;j<v[i].size();j++){
				int w=v[i][j];//printf("(%d)\n",w);
				if(w%2)--k1;
				else --k2;
			}
			if(!(k1==0&&k2==0)){
				y=0;
				break;
			}
			rk+=cnt;
		}
		if(y)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

