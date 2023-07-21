#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int a,b,c[3][3]; 

signed main(){
    cin>>a>>b;
    if(b<a)swap(a,b);
    if((b-a==1&&a%3!=0))printf("Yes\n");
    else printf("No\n");
    return 0;
}


