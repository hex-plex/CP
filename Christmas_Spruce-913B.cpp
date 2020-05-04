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
{        cout<<(x)<<" ";
 
}
queue<int> mai;
queue<int> q[1005];
int parent[1005];
int bfs(int root){
    if(q[root].size()==0)
    {
        return 1;
    }
    int cnt=0;
    while(!q[root].empty()){
        int buff = q[root].front();
        q[root].pop();
        mai.push(buff);
        if(q[buff].size()==0){
            cnt++;
        }
    }
    if(cnt>=3){
        return 1;
    }
    else{
        return -1;
    }
}
int main()
{
    int n,i,tem;
    cin>>n;
    For(i,2,n+1){
        cin>>tem;
        q[tem].push(i);
    }
    int flag=0;
    mai.push(1);
    while(!mai.empty()){
        int a = mai.front();
        mai.pop();
        if(bfs(a)==-1){
            flag=1;
            break;
        }
 
    }
    if(!flag){
        cout<<"Yes";
    }
    else
        cout<<"No";
    return 0;
 
}
