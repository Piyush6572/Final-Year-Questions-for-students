#include<bits/stdc++.h>
using namespace std;
void lps_calc(string pat,int lps[]){
    int i=1,len=0,m=pat.length();
    lps[0]=0;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;lps[i]=len;i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;i++;
            }
        }
    }
}
void kmp(string mess,string pat){
    int n=mess.length(),m=pat.length();
    if(n<m)return;
    int lps[m],i=0,j=0;
    lps_calc(pat,lps);
    while(i<n){
        if(mess[i]==pat[j]){
            i++;j++;
            if(j==m){
                cout<<"Pattern found at :"<<i-j<<"\n";
                j=lps[j-1];
            }
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
}
int main(){
    string mess,pat;
    cin>>mess>>pat;
    kmp(mess,pat);
}
