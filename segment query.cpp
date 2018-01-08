#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];
int tree[mx*4];
int seg_build(int node,int b,int e)
{
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
int segment_query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p=segment_query(left,b,mid,i,j);
    int q=segment_query(right,mid+1,e,i,j);
    return (p+q);
}
int main()
{
    int n,m,m1;
    cin>>n>>m>>m1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
   seg_build(1,1,n);
   cout<< segment_query(1,1,n,m,m1)<<endl;
    return 0;
}
