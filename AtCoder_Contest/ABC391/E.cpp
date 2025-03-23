#include <bits/stdc++.h>
using namespace std;

const int N=2.01e6;
int n,p3[N];
char s[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};

node query(int m,int l,int r){
    if(m==0){
        return node(s[l]-'0',1);
    }
    node A=query(m-1,l,l+p3[m-1]-1);
    node B=query(m-1,l+p3[m-1],r-p3[m-1]);
    node C=query(m-1,r-p3[m-1]+1,r);
    if(A.x==B.x&&B.x==C.x){
        return node(A.x,A.y+B.y+C.y-max(max(A.y,B.y),C.y));
    }
    if(A.x==B.x){
        return node(A.x,min(A.y,B.y));
    }
    if(A.x==C.x){
        return node(A.x,min(A.y,C.y));
    }
    if(B.x==C.x){
        return node(B.x,min(B.y,C.y));
    }
    return node(-1,-1);
}

signed main(){
    cin>>n;
    scanf("%s",s+1);
    p3[0]=1;
    for(int i=1;i<=n;i++)p3[i]=p3[i-1]*3;
    printf("%d\n",query(n,1,p3[n]).y);
    return 0;
}


