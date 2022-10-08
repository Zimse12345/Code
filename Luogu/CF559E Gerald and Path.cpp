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
int n,f[N][N][2],ans;
inline void mx(int& x,int y){if(y>x)x=y;return;}
struct line{
    int pos,len;
    line(int pos=0,int len=0):pos(pos),len(len){}
    bool operator < (const line& A)const{return pos<A.pos;}
}a[N];

signed main(){
    n=read();
    for(int i=1,x,y;i<=n;i++)x=read(),y=read(),a[i]=line(x,y);
    sort(a+1,a+n+1);
    a[0].pos=-INF;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int p=0;p<2;p++){
                mx(ans,f[i][j][p]);
                int R=a[j].pos+a[j].len*p,Max=-INF,x,y;
                for(int k=i+1;k<=n;k++){
                    for(int q=0;q<2;q++){
                        int RR=a[k].pos+a[k].len*q;
                        if(RR>Max)Max=RR,x=k,y=q;
                        mx(f[k][x][y],f[i][j][p]+min(a[k].len,RR-R)+Max-RR);
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
