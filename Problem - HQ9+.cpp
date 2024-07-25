//Problem -> HQ9+
//https://codeforces.com/contest/133/problem/A

//tc -> o(n)
//sc -> o(1)
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
 
void solve(){
    string p ; 
    cin>>p ; 
 
    int n = p.size();
    for(int i = 0 ; i<n ; i++)
    {
        if(p[i] == 'H' || p[i] == 'Q' || p[i] == '9')//only they will produce output '+' will just accumulate 
        {
            cout<<"YES"<<endl;
            return ; 
        }
    }
    cout<<"NO"<<endl;
}
int main(){
 
    fastIO ; 
 
    solve();
 
    return 0 ; 
}