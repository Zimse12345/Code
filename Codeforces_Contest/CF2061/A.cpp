#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int x=0,y=0;
        while(n--){
            cin>>a;
            if(a%2==0)++x;
            else ++y;
        }
        if(x)printf("%d\n",1+y);
        else printf("%d\n",y-1);
    }
    return 0;
}


