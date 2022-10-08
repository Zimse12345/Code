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
int a[N],b[N],p,q=36;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

signed main(){
    for(int i=1;i<=6;i++)a[i]=read();
    for(int i=1;i<=6;i++){
        b[i]=read();
        for(int j=1;j<=6;j++)if(a[j]>b[i])++p;
    }
    int g=gcd(p,q);
    p/=g,q/=g;
    printf("%d/%d\n",p,q);
    return 0;
}
