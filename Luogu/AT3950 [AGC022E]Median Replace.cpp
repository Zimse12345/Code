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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=1e9+7,INF=1e9+7;
int n,f[N][3][3],ans;
char s[N];
inline void add(int& x,int y){(x+=y)%=Mod;return;}

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++)if(f[i-1][x][y]){
                if(s[i]!='0'){//+1
                    int _x=x,_y=y;
                    if(_y)--_y;
                    else if(_x<2)++_x;
                    add(f[i][_x][_y],f[i-1][x][y]);
                }
                if(s[i]!='1'){//+0
                    int _x=x,_y=y;
                    ++_y;
                    if(_y==3)_y=1;
                    add(f[i][_x][_y],f[i-1][x][y]);
                }
            }
        }
    }
    for(int x=0;x<3;x++){
        for(int y=0;y<=x;y++){
            add(ans,f[n][x][y]);
        }
    }
    printf("%lld\n",ans);
	return 0;
}
