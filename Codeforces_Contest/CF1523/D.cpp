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

namespace zdt{
	const int N=40;
	int n,m;
bool G[N][N];
int cnt[N];
int group[N];
int vis[N];
int res;
bool dfs(int pos,int num){
    for(int i=pos+1;i<=n;i++){
        if(cnt[i]+num<=res)
            return false;
 
        if(G[pos][i]){
            int j;
            for(j=0;j<num;j++)
                if(!G[i][vis[j]])
                    break;
            if(j==num){
                vis[num]=i;
                if(dfs(i,num+1))
                    return true;
            }
        }
    }
 
    if(num>res){
        for(int i=0;i<num;i++)group[i]=vis[i];
        res=num;
        return true;
    }
    return false;
}
void maxClique(){
    res=-1;
    for(int i=n;i>0;i--){
        vis[0]=i;
        dfs(i,1);
        cnt[i]=res;
    }
}
int ppre(){
	 memset(G,0,sizeof(G));
}
int pre(){
        maxClique();
 
        if(res<0)res=0;
    }
    int add(int x,int y){
    	G[x][y]=1;
        G[y][x]=1;
	}
}

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,p,can[63],t,ans[63];
char s[N][63];
vector<int> h[63];

int main(){
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(s[j][i]=='1')h[i].push_back(j);
	for(int i=1;i<=m;i++)if(h[i].size()*2>=n)can[++t]=i;
	
	zdt::n=t;zdt::ppre();
	
	for(int i=1;i<=t;i++)for(int j=i+1;j<=t;j++)if(i!=j){
		int A=can[i],B=can[j],cnt=0,k1=0,k2=0;
		while(1){
//			printf("[%d %d %d %d]",k,K,h[A][k],h[B][K]);
			while(k1+1<=h[A].size()&&h[A][k1]<h[B][k2])++k1;
			while(k2+1<=h[B].size()&&h[A][k1]>h[B][k2])++k2;
			if(h[A][k1]==h[B][k2])++k1,++k2,++cnt;
			if(k1>=h[A].size()||k2>=h[B].size())break;
		}
//		printf("(%d %d %d)\n",i,j,cnt);
		if(cnt*2>=n)zdt::add(i,j);
	}
	zdt::pre();
	
	for(int i=0;i<zdt::res;i++)ans[can[zdt::group[i]]]=1;
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}

