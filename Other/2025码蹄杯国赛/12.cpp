#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,m,q,a[N][N],w;
char s[4][N][N];

signed main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)scanf("%s",s[0][i]);
    for(int r=1;r<4;r++){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)s[r][j][m-i-1]=s[r-1][i][j];
        }
    }
    while(q--){
        int ty=0,x=0,y=0;
        scanf("%d",&ty);
        if(ty==1)w=(w+1)%4;
        else{
            scanf("%d%d",&x,&y);
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++)if(s[w][i][j]=='#')a[x+i][y+j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


