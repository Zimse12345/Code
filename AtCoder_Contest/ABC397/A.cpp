#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
double x; 

signed main(){
    cin>>x;
    if(x>=38)printf("1\n");
    else if(x<37.5)printf("3\n");
    else printf("2\n");
    return 0;
}


