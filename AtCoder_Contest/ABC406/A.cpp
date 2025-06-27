#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int a,b,c,d; 

signed main(){
    cin>>a>>b>>c>>d;
    if(c<a||(c==a&&d<=b))printf("Yes\n");
    else printf("No\n");
    return 0;
}


