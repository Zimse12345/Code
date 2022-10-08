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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=512,Mod=998244353,INF=1e9+7;
int n;
bitset<N> q,p[N],u[N],t,ans[N];
bool vis[N];

signed main(){
    n=read();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)q[j]=read();
        t.reset(),t[i]=1;
        for(int j=0;j<n;j++)if(q[j]==1){
            if(!vis[j]){
                vis[j]=1,p[j]=q,u[j]=t;
                break;
            }
            else q^=p[j],t^=u[j];
        }
    }
    for(int i=0;i<n;i++){
        q.reset();
        for(int j=0;j<n;j++){
            if((i==j&&q[j]==0)||(i!=j&&q[j]==1)){
                if(!vis[j]){
                    printf("-1\n");
                    return 0;
                }
                q^=p[j],ans[i]^=u[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)if(ans[i][j])printf("%d ",j+1);
        printf("\n");
    }
    return 0;
}
