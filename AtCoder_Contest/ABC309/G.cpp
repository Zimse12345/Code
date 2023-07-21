#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,k;
int f[110][110][1100],popc[1100];

inline int lowbit(int x){
    return x&(-x);
}

inline void _mod(int &x,int y){
    (x+=y)%=Mod;
}

signed main(){
    cin>>n>>k;
    int K=k*2-1,V=(1<<K);
    for(int i=1;i<V;i++)popc[i]=popc[i^lowbit(i)]+1;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<=n;x++){
            for(int z=0;z<V;z++)if(f[i-1][x][z]){
                int _z=z/2,l=i-k-(i-1-x-popc[_z]);
                if(l>0)_mod(f[i][x][_z],f[i-1][x][z]*l);
                _mod(f[i][x+1][_z],f[i-1][x][z]);
                if(x){
                    _z+=(1<<(K-1));
                    if(l>0)_mod(f[i][x-1][_z],f[i-1][x][z]*l%Mod*x);
                    _mod(f[i][x][_z],f[i-1][x][z]*x);
                }
            }
        }
    }
    printf("%lld\n",f[n][0][(1<<k)-1]);
    return 0;
}


