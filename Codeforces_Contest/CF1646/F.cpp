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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N][N],s[N];
int ans[N*N][N],tot;

signed main(){
	n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)++a[i][read()];
    }
    while(1){
        int pos=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)if(a[i][j]>1){pos=i;break;}
        }
        if(!pos)break;
        int pre=0;
        for(int i=pos;i<=n;i++){
            s[i]=pre;
            for(int j=1;j<=n;j++)if(a[i][j]>1){s[i]=j,pre=j;break;}
        }
        for(int i=1;i<pos;i++){
            s[i]=pre;
            for(int j=1;j<=n;j++)if(a[i][j]>1){s[i]=j,pre=j;break;}
        }
        ++tot;
        for(int i=1;i<=n;i++)ans[tot][i]=s[i],--a[i][s[i]],++a[i<n?i+1:1][s[i]];
    }
    for(int i=n;i>=2;i--){
        for(int j=i;j<=n;j++){
            ++tot;
            int pos=0;
            for(int k=i;k<=n;k++)ans[tot][++pos]=k;
            for(int k=1;k<i;k++)ans[tot][++pos]=k;
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++){
        for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);
        printf("\n");
    }
	return 0;
}
