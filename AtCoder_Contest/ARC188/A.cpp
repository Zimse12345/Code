#include <bits/stdc++.h>
using namespace std;

const int N=51,Mod=998244353;
int n,k,T,ans;
char s[N];
vector<int> f[2][N][N][N];

signed main(){
    cin>>n>>k;
    scanf("%s",s+1);
    f[T][0][0][0].resize(1);
    f[T][0][0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<i;x++){
            for(int y=0;x+y<i;y++){
                for(int z=0;x+y+z<i;z++){
                    for(int j=0;j<f[T][x][y][z].size();j++){
                        if(!f[T][x][y][z][j])continue;
                        int val=0;
                        swap(val,f[T][x][y][z][j]);
                        for(int c=0;c<3;c++){
                            if(s[i]!='?'&&s[i]!='A'+c)continue;
                            int _x=x,_y=y,_z=z,_j=j;
                            if(c==0){
                                _j+=_x,_x=i-_x-_y-_z;
                                swap(_y,_z);
                            }
                            if(c==1){
                                _j+=_y,_y=i-_x-_y-_z;
                                swap(_x,_z);
                            }
                            if(c==2){
                                _j+=_z,_z=i-_x-_y-_z;
                                swap(_x,_y);
                            }
                            if(f[T^1][_x][_y][_z].size()<=_j)f[T^1][_x][_y][_z].resize(_j+1);
                            (f[T^1][_x][_y][_z][_j]+=val)%=Mod;
                        }
                    }
                }
            }
        }
        T^=1;
    }
    for(int x=0;x<=n;x++){
        for(int y=0;x+y<=n;y++){
            for(int z=0;x+y+z<=n;z++){
                for(int j=k;j<f[T][x][y][z].size();j++){
                    (ans+=f[T][x][y][z][j])%=Mod;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


