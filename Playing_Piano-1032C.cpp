#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<cmath>
#include<string.h>
#include<queue>
//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
#define pb push_back
typedef long long ll;
#define inf 1000000000
//typedef vector <int> vi;
//typedef pair<int,int> pii;
#define For(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
using namespace std;
#define BIG 100003
 
 
 
 
void pri(int x)
{        cout<<(x)<<" ";
 
}
 
int n,a[BIG],dp[BIG][6];
vector<int>ans;
 
int solve(int ind, int prev){
 
    if(ind==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        exit(0);
    }
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    dp[ind][prev]=0;
    if(a[ind]>a[ind-1]){
        for(int i=prev+1;i<=5;i++){
            ans.pb(i);
            solve(ind+1,i);
            ans.pop_back();
        }
    }
    else if(a[ind]<a[ind-1]){
        for(int i=(prev-1);i>=1;--i){
            ans.pb(i);
            solve(ind+1,i);
            ans.pop_back();
        }
    }
    else if(a[ind]==a[ind-1]){
        for(int i=1;i<=5;i++){
            if(i!= prev){
                ans.pb(i);
                solve(ind+1,i);
                ans.pop_back();
            }
        }
    }
 
    return 0;
}
 
 
int main(){
    int i;
    cin>>n;
    memset(dp,-1,sizeof dp);
    For(i,0,n){
        cin>>a[i];
    }
    For(i,1,6){
        ans.pb(i);
        if(solve(1,i))
            return 0;
        ans.pop_back();
    }
    cout<<"-1";
    return 0;
}
