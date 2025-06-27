#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int r,x; 

signed main(){
    cin>>x>>r;
    if(r==2){
        if(1200<=x&&x<=2399)printf("Yes\n");
        else printf("No\n");
    }
    else{
        if(1600<=x&&x<=2999)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


