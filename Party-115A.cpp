#include<iostream>
#include<map>
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
int c;
int p;
int ind;
};
bool operator<(const box& a,const box& b )
{
    return a.p > b.p;

}

void pri(int x)
{        cout<<x<<" ";

}

int dfs(int x , vector<int> *vis, vector< queue<int> > *q)
{
    if((*vis)[x]>0)
    {
        return ((*vis)[x]+1);
    }
    int ma=1;
    while(!((*q)[x].empty()))
    {
        int a = ((*q)[x]).front();
        (*q)[x].pop();
        ma=max(ma,dfs(a,vis,q));

    }
    (*vis)[x]=ma;
    return ((*vis)[x]+1);
}

int main()
{
    int n,i,tem;
    cin>>n;
    queue<int> sample;
    vector<queue<int> > q(n+1, sample );
    vector<int> vis(n+1,0);
    For(i,0,n){
        cin>>tem;
        if(tem!=-1)
            q[tem].push(i+1);
    }
    int maxx=1;
    For(i,0,n){
        dfs(i+1,&vis,&q);
        maxx=max(maxx,vis[i+1]);
    }
    cout<<(maxx)<<"\n";
    return 0;

}
