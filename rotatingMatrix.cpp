//I taught of slicing it open as a onion and moving a pointer on the ring of the array of a equispaced ring elements
//question = https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
//Algo applied circular ring list
//things learned "new" feature to allocate new memory and vectors are not dynamic allocation of memory like calloc or malloc

#include<iostream>
//#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
//#include<string>

//#include<stdio.h>
//#define a.pb(c) push_back(c)
//#define pri(n) cout<<n<<"\n"
#define all(c) c.begin(),c.end()
//#define allarr(c) c,c+sizeof(c)
//#define revall(c) c.rbegin(),c.rend()
//#define pb push_back
typedef long long ll;
//#define inf 1000000000
//typedef vector <int> vi;
//typedef pair<int,int> pii;

using namespace std;


struct rl{
ll val;
rl * poi;
};


void pri(rl x)
{
    cout<<x.val<<" ";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,i,j,k,r;
    cin>>m>>n>>r;
    ll a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }


    rl* toprl;
    for(i=0;i<m/2;i++)
    {
        rl* temp;
        rl* prev=temp;
        int top=1;
        for(k=i;k<(m-i-1);k++)
        {
            temp = new rl;
            (*temp).poi=prev;
            (*temp).val=a[k][i];
            if(top==1)
            {
                top=0;
                toprl = temp;
            }
            prev = temp;
            //cout<<(*temp).val<<" ";
        }

        for(j=i;j<n-i;j++)
        {
            temp = new rl;
            (*temp).poi=prev;
            (*temp).val=a[m-i-1][j];
            //cout<<(*temp).val<<" ";
            prev = temp;
        }
        j--;
        for(k--;k>i;k--)
        {
            temp = new rl;
            (*temp).poi=prev;
            (*temp).val=a[k][j];
            prev = temp;
            //cout<<(*temp).val<<" ";
        }

        for(;j>i;j--)
        {
            temp = new rl;
            (*temp).poi=prev;
            (*temp).val=a[i][j];
            prev = temp;
            //cout<<(*temp).val<<" ";
            }

        (*toprl).poi=prev;
        //cout<<(*toprl).val;
        int perimeter = max(2*(n+m-4*i)-4,2);
        int rr = r%perimeter;
        while(rr--)
        {
            toprl = (*toprl).poi;
        }
        rl* it = toprl;
        for(j=i;j<n-i;j++)
        {
            a[i][j]=(*it).val;
            it=(*it).poi;
        }
        j--;
        for(k=i+1;k<m-i;k++)
        {
            a[k][j]=(*it).val;
            it=(*it).poi;
        }
        for(j--;j>i;j--)
        {
            a[m-1-i][j]=(*it).val;
            it=(*it).poi;
        }
        for(k--;k>i;k--)
        {
            a[k][j]=(*it).val;
            it=(*it).poi;
        }

        //cout<<"\n";
    }
    //for_each(all(tempo),pri);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;

}
