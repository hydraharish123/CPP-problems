//Problem -> Football
// https://codeforces.com/problemset/problem/96/A

//tc -> o(100)
//sc -> o(1)
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
void solve()
{
    string s ; 
    cin>>s ; 

    int n = s.size() ; 

    for(int i = 0 ; i<n ; i++)
    {
        int cnt0 = 0 ; 
        int cnt1 = 0 ; 
        for(int j = i ; j<n ; j++)
        {
            if(s[j] == '1')
                cnt1++;
            else
                cnt0++;
            int len = j-i + 1;
            if((cnt0 == 7 && len == 7) || (cnt1==7 && len==7))
            {
                cout<<"YES"<<endl;
                return ; 
            }
        }
    }

    cout<<"NO"<<endl;
}
int main(){
    fastIO ; 

    solve();

    return 0 ; 
}