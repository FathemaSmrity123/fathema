#include<bits/stdc++.h>
using namespace std;
string rev(string s)
{
    reverse(s.begin(),s.end());
    return s;
}
string add(string s1,string s2)
{
    int carry=0,x,y,sum=0,k=0;
    string s="",d,a,b;
    a=rev(s1);
    b=rev(s2);
    for(int i=0; i<a.length(); i++)
    {
        if(i<b.length())
        {
            x=a[i]-48;
            y=b[i]-48;
            sum=carry+x+y;
            k=sum%10;
            s+=k+48;
            carry=0;
            if(sum>9)
                carry=1;
            if(carry==1 && i==a.length()-1)
            {
                s+=49;
            }
        }
        else
        {
            x=a[i]-48;
            sum=carry+x;
            k=sum%10;
            s+=k+48;
            carry=0;
            if(sum>9)
                carry=1;
            if(carry==1 && i==a.length()-1)
            {
                s+=49;
            }
        }
    }
    return s;
}
int main()
{
    string c,a,b;
    cin>>a;
    cin>>b;
        c=rev(add(a,b));
        cout<<c<<endl;
    return 0;
}

