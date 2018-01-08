#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];
int c=0;
int tree[mx*4];/**tree array er size input array theke 4 multiple hoi**/
int seg_build(int node,int b,int e)
{
    c++;
    if(b==e)
    {
        tree[node]=arr[b];
        return tree[node];
    }
    int right=node*2+1;
    int left=node*2;
    int mid=(b+e)/2;
    seg_build(left,b,mid);
    seg_build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    seg_build(1,1,n);
    for(int i=1;i<=c;i++)
    {
        cout<<tree[i]<<endl;
    }
}

