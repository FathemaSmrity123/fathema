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
int update(int node,int b,int e,int i,int newvalue)/** if it find -1 in any node,then -1 value wont be counted**/
{
    if(i>e || i<b)
        return -1;
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
   seg_build(1,1,n);
   update(1,1,n,2,0);
   cout<< segment_query(1,1,n,1,3)<<endl;
   update(1,1,n,2,2);
   cout<<segment_query(1,1,n,2,2)<<endl;
   return 0;
}

