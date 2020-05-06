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
box zero;
box vis[100005];
int parent[100005];
queue<int> q[100005];
box dfs(int root , int gro){
    if(vis[root]!=zero){
        return vis[root];
    }
    box cnt;
    while(!q[root].empty()){
        ll nex = q[root].front();
        q[root].pop();
        if (parent[root]!=nex){
        parent[nex]=root;
        cnt=cnt+dfs(nex,!gro);}

    }
    box tem;
    if (gro==1){
        tem.grp1+=1;
    }
    else
        tem.grp0+=1;
    vis[root]=cnt+tem;
    return vis[root];
}

int main(){

    ll n,i,l,r;
    cin>>n;
    memset(parent,0,100005*(int(sizeof(parent[0]))));
    For(i,1,n){
        cin>>l>>r;
        q[l].push(r);
        q[r].push(l);
    }
    box ans;
    For(i,1,n+1){
        if(!(vis[i]!=zero)){
            ans=ans+dfs(i,0);
        }
    }
    ll turn = (ans.grp0*ans.grp1-n+1);
    ll zer =0 ;
    cout<<max(zer,turn)<<"\n";
    return 0;

}
