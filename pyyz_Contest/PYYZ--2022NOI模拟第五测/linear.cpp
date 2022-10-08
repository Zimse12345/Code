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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int k,n,a[N],ans;

signed main(){
    k=read(),n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int s=(1<<k);
    for(int i=1;i<(1<<s);i++){
        int tag=1;
        for(int j=1;j<=n;j++)if(!(i&(1<<a[j]))){tag=0;break;}
        if(!tag)continue;
        for(int x=0;x<s;x++)if(i&(1<<x)){
            for(int y=0;y<s;y++)if(i&(1<<y)){
                if(!(i&(1<<(x&y))))tag=0;
                if(!(i&(1<<(x|y))))tag=0;
            }
        }
        ans+=tag;
    }
    printf("%d\n",ans);
	return 0;
}
