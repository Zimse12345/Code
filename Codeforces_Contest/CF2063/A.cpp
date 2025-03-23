#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,l,r; 

signed main(){
    cin>>T;
    while(T--){
        cin>>l>>r;
        if(l==1&&r==1)printf("1\n");
        else printf("%d\n",r-l);
    }
    return 0;
}


