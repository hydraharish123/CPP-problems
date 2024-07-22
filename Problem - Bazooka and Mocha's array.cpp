//Problem -> Bazooka and Mocha's array
// https://codeforces.com/contest/1975/problem/A

//tc -> O( n * (n+n) ) 
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);

void rotate(vector<int>& arr , int n)
{
    int first = arr[0] ; 
    for(int i = 0 ; i<n-1 ; i++)
        arr[i] = arr[i+1];
    
    arr[n-1] = first ; 
}

bool sorted(vector<int>& arr, int n)
{
    for(int i = 0 ; i<n-1 ; i++)
    {
        if((arr[i] <= arr[i+1]) == false)
            return false ; 
    }

    return true ;
}
void solve(){
    int n ; 
    cin>>n ; 

    vector<int>arr ; 
    for(int i = 0 ; i<n ; i++){
        int x ; 
        cin>>x ; 
        arr.push_back(x);
    }
    
    int rotation = 0 ; 

    for(int i = 1 ; i<=n ; i++)
    {
        rotate(arr , n);
        if(sorted(arr,n))
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