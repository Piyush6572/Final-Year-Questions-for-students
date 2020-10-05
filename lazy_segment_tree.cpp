#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int tree[100005]={0};
int lazy[100005]={0};
void build(int arr[],int a,int b,int node){
  if(a==b){
    tree[node]=arr[a];
    return;
  }
  int mid=(a+b)>>1;
  build(arr,a,mid,node*2);
  build(arr,mid+1,b,node*2+1);
  tree[node]=tree[node*2]+tree[node*2+1]; // range sum
  // tree[node]=min(tree[node*2],tree[node*2+1]); //min value
  // tree[node]=max(tree[node*2],tree[node*2+1]); //max value
}

int query(int a,int b,int i,int j,int node){
  if(a>b || i>b || j<a)return 0;  // range sum
  // if(a>b || i>b || j<a)return INT_MAX; // min value
  // if(a>b || i>b || j<a)return 0; // max value
  if(lazy[node]!=0){
    tree[node]=lazy[node]*(b-a+1);
    if(a!=b){
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(i<=a && j>=b){
    return tree[node];
  }
  int mid=(a+b)>>1;
  return query(a,mid,i,j,node*2)+query(mid+1,b,i,j,node*2+1); // range sum
  // return min(query(a,mid,i,j,node*2),query(mid+1,b,i,j,node*2+1)); //min value
  // return max(query(a,mid,i,j,node*2),query(mid+1,b,i,j,node*2+1)); //max value
}

void update(int a,int b,int i,int j,int val,int node){
  if(lazy[node]!=0){
    tree[node]=lazy[node]*(b-a+1);
    if(a!=b){
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(a>b || i>b || j<a)return ;
  if(i<=a && j>=b){
    tree[node]=val*(b-a+1);
    lazy[node*2]=val;lazy[node*2+1]=val;
    return;
  }
  int mid=(a+b)>>1;
  update(a,mid,i,j,val,node*2);
  update(mid+1,b,i,j,val,node*2+1);
  tree[node]=tree[node*2]+tree[node*2+1]; // range sum
  // tree[node]=min(tree[node*2],tree[node*2+1]); //min value
  // tree[node]=max(tree[node*2],tree[node*2+1]); //max value
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  build(arr,0,n-1,1);
  for(int i=0;i<30;i++){
    cout<<tree[i]<<" ";
  }cout<<"\n";
  int q;
  cin>>q;
  int a,b,c;
  while(q--){
    cin>>c;
    if(c==1){
      cin>>a>>b;
      cout<<query(0,n-1,a,b,1)<<"\n";
    }else{
      int val;
      cin>>a>>b>>val;
      update(0,n-1,a,b,val,1);
    }
  }
}
