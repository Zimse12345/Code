#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e6 + 10, M = 256;

int n,m,X,Y,v[N],f[2][N],T;
char s[M][M],str[M][M];

void decode(int x){
    v[1]=x%3;
    for(int i=2;i<=m;i++){
        v[i]=v[i-1]+1;
        if((x/3)&(1<<(i-2)))++v[i];
        v[i]%=3;
    }
    return;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++){
            if(n>=m)s[i][j]=str[i][j];
            else s[j][i]=str[j][i];
        }
    }
    if(n<m)swap(n,m);
    X=(1<<(m-1)),Y=X*3;
    for(int i=0;i<Y;i++){
        decode(i);
        int tag=1;
        for(int j=1;j<=m;j++){
            if(j<m&&v[j]==v[j+1])tag=0;
            if(s[i][j]!='?'&&s[i][j]-'0'!=v[j])tag=0;
        }
        if(tag)++f[T][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int z=0;z<Y;z++)f[T^1][z]=0;
            for(int z=0;z<Y;z++)if(f[T][z]){
                decode(z);
                for(int c=0;c<3;c++)if(s[i][j]=='?'||s[i][j]-'0'==c){
                    if(j>1&&c==v[j-1])continue;
                    if(j<m&&c==v[j])continue;
                    int _z=z;
                    if(j==1)_z=_z-_z%3+c;
                    else{
                        int zz=(1<<(j-2));
                        if((v[j-1]+1)%3==c&&(_z&zz))_z-=zz;
                        if((v[j-1]+2)%3==c)_z|=zz;
                    }
                    (f[T^1][_z]+=f[T][z])%=mod;
                }
            }
            T^=1;
        }
    }
    int ans=0;
    for(int z=0;z<Y;z++)(ans+=f[T][z])%=mod;
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
