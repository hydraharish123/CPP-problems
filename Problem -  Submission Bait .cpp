//Problem ->  Submission Bait 
// https://codeforces.com/contest/1990/problem/A 

//hint : if all numbers appear twice then no matter what number alice choose 
//bob can do the same which then later on alice cannot perform further
//so alice will lose

//so alice should pick only the max among the odd occuring elements which will then force bob to first case

#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);

void solve(){
    int n ; 
    cin>>n ; 
    unordered_map<int,int>mpp ; 
    for(int i = 0 ; i<n ; i++)
    {
        int x ; 
        cin>>x ; 
        mpp[x]++;
    }
    for(auto it : mpp)
    {
        if(it.second % 2 == 1)
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    
}
int main(){
    fastIO ; 

    int t ; 
    cin>>t ; 

    while(t--){
        solve();
    }
}