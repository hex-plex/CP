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
 
 
struct box{
ll grp1=0;
ll grp0=0;
};
box operator+(const box& a,const box& b )
{
    box temp;
    temp.grp0=a.grp0+b.grp0;
    temp.grp1=a.grp1+b.grp1;
    return temp;
 
}
bool operator!=(const box& a,const box& b )
{
    return ((a.grp0!=b.grp0) || (a.grp1!=b.grp1));
 
}
 
void pri(int x)
{        cout<<(x)<<" ";
 
}
int vis[100005];
queue<int>q[100005];
 
int dfs(int root){
    if(vis[root]!=0)
        return vis[root];
    int sz=0;
    vis[root]=1;
    while(!q[root].empty()){
        int nex=q[root].front();
        q[root].pop();
        if (vis[nex]==0){
            sz+=dfs(nex);
        }
    }
    vis[root]=sz+1;
    return vis[root];
 
}
 
ll Perm(ll n, ll k ){
    if (k==0)return 1;
    if (k&1)return (((n%mod) * (Perm(n,k-1)%mod))%mod);
 
    ll temp = Perm(n,k/2);
    return (((temp%mod)*(temp%mod))%mod);
}
 
int main(){
 
    ll n,k,i,a,b;
    int grp;
    cin>>n>>k;
    For(i,1,n){
        cin>>a>>b>>grp;
        if(grp==0){
            q[a].push(b);
            q[b].push(a);
        }
 
    }
    memset(vis,0,100007*int(sizeof(vis[0])));
    ll ans =Perm(n,k);
    For(i,1,n+1){
        if(vis[i]==0){
            ans = ((ans%mod) - (Perm(dfs(i),k)%mod) + mod)%mod;
        }
    }
    cout<<ans<<"\n";
 
    return 0;
 
}
