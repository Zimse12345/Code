#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,a,b,c,d;

signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        if(c<a)swap(a,c),swap(b,d);
        if(b<c)printf("1\n");
        else if(b<d){
            int x=b-c+1;
            if(a!=c)++x;
            printf("%d\n",x);
        }
        else{
            int x=d-c;
            if(a!=c)++x;
            if(b!=d)++x;
            printf("%d\n",x);
        }
    }
    return 0;
}


