#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,qx[N*N],qy[N*N],l=1,r;
char s[N][N];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)if(s[i][j]=='E'){
            ++r;
            qx[r]=i,qy[r]=j;
        }
    }
    while(l<=r){
        int x=qx[l],y=qy[l];
        ++l;
        for(int w=0;w<4;w++){
            int _x=x+dx[w],_y=y+dy[w];
            if(s[_x][_y]=='.'){
                if(w==0)s[_x][_y]='v';
                if(w==1)s[_x][_y]='^';
                if(w==2)s[_x][_y]='>';
                if(w==3)s[_x][_y]='<';
                ++r;
                qx[r]=_x,qy[r]=_y;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}


