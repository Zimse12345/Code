#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,l,r,ans;;
signed main(){
    cin>>T;
    while(T--){
        cin>>l>>r;
        int d=0;
        for(int i=29;i>=0;i--){
            int x=(1<<i);
            if(l<x&&r>=x){
                int a=x,b=x-1,c=x-2;
                if(c<l)c=x+1;
                printf("%d %d %d\n",a+d,b+d,c+d);
                break;
            }
            if(l>=x)l-=x,r-=x,d+=x;
        }
    }
    return 0;
}


