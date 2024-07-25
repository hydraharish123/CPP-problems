//Problem -> Even and Odd
//https://codeforces.com/contest/318/problem/A

//tc -> o(1)
//sc -> o(1)
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
 
void solve(){
    long long n , k ; 
    cin>>n>>k ; 
 
    long long evencnt = n/2 ; 
    long long oddcnt = n % 2 == 0 ? n/2 : (n/2)+1 ; 
 
    if(k > oddcnt)
    {
        cout<<2*(k - oddcnt)<<endl ; 
    }
    else {
        cout<<2*k - 1<<endl;
    }
}
int main(){
    fastIO ; 
 
    solve();
 
    return 0 ; 
}