/*
Zimse Rectangular Rotation Algorithm
O(n^2)
ZRR
*/

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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

struct Rectangular{
    int N,M,B;
    int v[600][600],val[600*600],p[600*600][4],Id[600][600],_Id[600][600],tag[600][600];

    struct node{
        int x,y,id;
        node(int x=0,int y=0,int id=0):x(x),y(y),id(id){};
    }pos;
    const node stdnode=node(1,1,1);

    void upt(int id,int val0,int val1,int val2,int val3){
        p[id][0]=val0,p[id][1]=val1,p[id][2]=val2,p[id][3]=val3;
        return;
    }

    void p_rot(int id){
        int t=p[id][0];
        p[id][0]=p[id][1],p[id][1]=p[id][2],p[id][2]=p[id][3],p[id][3]=t;
        return;
    }

    int GetVal(node s){
        return val[s.id];
    }

    void InitRectangular(int n,int m){
/*
1 2 3  .. m+2
2n+2m+4   m+3
.         m+4
.         .
.         .
2m+n+4 .. n+m+3

B <- 2n+2m
B+1 .. B+m
B+m+1 .. B+m+n
.
.
B+(n-1)m+1 .. B+nm
*/
        N=n,M=m,B=2*n+2*m+4;
        int c=B;
        for(int i=1;i<=m+2;i++)Id[1][i]=i,Id[n+2][i]=2*m+n+4-i+1;
        for(int i=2;i<n+2;i++)Id[i][1]=2*n+2*m+4-(i-2),Id[i][m+2]=m+i+1;
        for(int i=2;i<n+2;i++){
            for(int j=2;j<m+2;j++){
                Id[i][j]=++c;
                val[Id[i][j]]=v[i-1][j-1];
            }
        }
        for(int i=1;i<=n+2;i++){
            for(int j=1;j<=m+2;j++){
                upt(Id[i][j],Id[i-1][j],Id[i][j+1],Id[i+1][j],Id[i][j-1]);
            }
        }
    }

    inline void GoDown(node& s){
        int to=p[s.id][2];
        while(p[to][0]!=s.id)p_rot(to);
        ++s.x,s.id=to;
        return;
    }

    inline void GoUp(node& s){
        int to=p[s.id][0];
        while(p[to][2]!=s.id)p_rot(to);
        --s.x,s.id=to;
        return;
    }

    inline void GoRight(node& s){
        int to=p[s.id][1];
        while(p[to][3]!=s.id)p_rot(to);
        ++s.y,s.id=to;
        return;
    }

    inline void GoLeft(node& s){
        int to=p[s.id][3];
        while(p[to][1]!=s.id)p_rot(to);
        --s.y,s.id=to;
        return;
    }

    inline void GoTo(node& s,int goal_x,int goal_y){
        while(s.x<goal_x)GoDown(s);
        while(s.x>goal_x)GoUp(s);
        while(s.y<goal_y)GoRight(s);
        while(s.y>goal_y)GoLeft(s);
        return;
    }

    inline void goTo(node& s,int goal_x,int goal_y){
        GoTo(s,goal_x+1,goal_y+1);
        return;
    }

    void RectangularRotation(int x,int y,int r){
        pos=stdnode,++x,++y;
        for(int i=1;i<=N+2;i++){
            for(int j=1;j<=M+2;j++){
               _Id[i][j]=Id[i][j]=0;
            }
        }
        for(int i=max(1,x-2);i<=min(N+2,x+1);i++){
            for(int j=max(1,y-2);j<=min(M+2,y+r+1);j++){
                GoTo(pos,i,j);
                _Id[i][j]=Id[i][j]=pos.id;
                if(x<=i&&i<x+r&&y<=j&&j<y+r)tag[i][j]=1;
                else tag[i][j]=0;
            }
        }
        for(int i=max(1,x+r-2);i<=min(N+2,x+r+1);i++){
            for(int j=max(1,y-2);j<=min(M+2,y+r+1);j++){
                GoTo(pos,i,j);
                _Id[i][j]=Id[i][j]=pos.id;
                if(x<=i&&i<x+r&&y<=j&&j<y+r)tag[i][j]=1;
                else tag[i][j]=0;
            }
        }
        for(int j=max(1,y-2);j<=min(M+2,y+1);j++){
            for(int i=max(1,x-2);i<=min(N+2,x+r+1);i++){
                GoTo(pos,i,j);
                _Id[i][j]=Id[i][j]=pos.id;
                if(x<=i&&i<x+r&&y<=j&&j<y+r)tag[i][j]=1;
                else tag[i][j]=0;
            }
        }
        for(int j=max(1,y+r-2);j<=min(M+2,y+r+1);j++){
            for(int i=max(1,x-2);i<=min(N+2,x+r+1);i++){
                GoTo(pos,i,j);
                _Id[i][j]=Id[i][j]=pos.id;
                if(x<=i&&i<x+r&&y<=j&&j<y+r)tag[i][j]=1;
                else tag[i][j]=0;
            }
    	}
    	for(int i=max(1,x-2);i<=min(N+2,x+1);i++){
            for(int j=max(1,y-2);j<=min(M+2,y+r+1);j++){
                if(tag[i][j]){
                	tag[i][j]=0;
                	_Id[i][j]=Id[x+r-1-j+y][y+i-x];
                }
            }
        }
        for(int i=max(1,x+r-2);i<=min(N+2,x+r+1);i++){
            for(int j=max(1,y-2);j<=min(M+2,y+r+1);j++){
                if(tag[i][j]){
                	tag[i][j]=0;
                	_Id[i][j]=Id[x+r-1-j+y][y+i-x];
				}
            }
        }
        for(int j=max(1,y-2);j<=min(M+2,y+1);j++){
            for(int i=max(1,x-2);i<=min(N+2,x+r+1);i++){
                if(tag[i][j]){
                	tag[i][j]=0;
                	_Id[i][j]=Id[x+r-1-j+y][y+i-x];
				}
            }
        }
        for(int j=max(1,y+r-2);j<=min(M+2,y+r+1);j++){
            for(int i=max(1,x-2);i<=min(N+2,x+r+1);i++){
                if(tag[i][j]){
                	tag[i][j]=0;
                	_Id[i][j]=Id[x+r-1-j+y][y+i-x];
				}
            }
    	}
    	for(int i,j=max(1,y-1);j<=min(y+r,M+2);j++){
    		if(x-1>=1){
    			i=x-1;
    			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			}
			i=x;
			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			i=x+r-1;
			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			if(x+r<=N+2){
				i=x+r;
				upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			}
		}
		for(int i=max(1,x-1),j;i<=min(x+r,N+2);i++){
    		if(y-1>=1){
    			j=y-1;
    			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			}
			j=y;
			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			j=y+r-1;
			upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			if(y+r<=M+2){
				j=y+r;
				upt(_Id[i][j],_Id[i-1][j],_Id[i][j+1],_Id[i+1][j],_Id[i][j-1]);
			}
		}
        return;
    }

    inline void Show(){
        pos=stdnode;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++)goTo(pos,i,j),printf("%d ",GetVal(pos));
            printf("\n");
        }
        return;
    }
}Rect;

signed main(){
    int n=read(),m=n,q=read();
    int v=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Rect.v[i][j]=++v;
    Rect.InitRectangular(n,m);
    while(q--){
    	int x=read(),y=read(),r=read(),z=read();
    	if(z==0)z=1;
    	else z=3;
    	x-=r,y-=r,r=r*2+1;
    	while(z--)Rect.RectangularRotation(x,y,r);
    }
    Rect.Show();
	return 0;
}
