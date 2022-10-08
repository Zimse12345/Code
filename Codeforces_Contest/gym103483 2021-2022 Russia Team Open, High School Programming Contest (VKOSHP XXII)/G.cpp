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
#define double long double

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int a[5],p[5];
double b[N],ans;
double s[5];

signed main(){
    int tag=1,cnt=0;
    for(int i=1;i<=4;i++){
        a[i]=read();
        if(a[i]!=1)tag=0;
    }
    if(tag){
        printf("1 2 3 4\n1.0 1.0 1.0 1.0\n");
        return 0;
    }
    for(int i1=1;i1<=4;i1++){
        for(int i2=1;i2<=4;i2++)if(i2!=i1){
            for(int i3=1;i3<=4;i3++)if(i3!=i1&&i3!=i2){
                for(int i4=1;i4<=4;i4++)if(i4!=i1&&i4!=i2&&i4!=i3){
                    if(a[i1]==1)continue;
                    b[1]=a[i1],b[2]=a[i2],b[3]=a[i3],b[4]=a[i4];
                    double x=(b[1]+b[2]*b[3]-b[2]-b[3])/(b[1]-1);
                    if(x<=b[4]){
                        double val=b[1]*x+b[2]+b[3];
                        if(val>ans)ans=val,p[1]=i1,p[2]=i2,p[3]=i3,p[4]=i4,s[1]=b[1],s[2]=b[2],s[3]=b[3],s[4]=x;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n%.14Lf %.14Lf %.14Lf %.14Lf\n",p[1],p[2],p[3],p[4],s[1],s[2],s[3],s[4]);
    return 0;
}
