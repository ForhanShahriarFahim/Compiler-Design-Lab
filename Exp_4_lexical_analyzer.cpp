#include <bits/stdc++.h>
using namespace std;

void find(string s)
{
    int n = s.size();
    if((s[0]>='i'&& s[0]<='n') || (s[0]>='I' && s[0]<='N'))
    {
        for(int i = 1;i<n;i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            {

            }
            else 
            {
                cout<<"Otherwise"<<endl;
                return;
            }
        }
        cout<<"Integer Variable"<<endl;
    }
    else if(s[0]>='1' && s[0]<='9')
    {
        for (int i = 1; i < n; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                continue;
            }
            else 
            {
                cout<<"Otherwise"<<endl;
                return;
            }
        }
        if(n>4)
        {
            cout<<"LongInt Number"<<endl;            
        }
        else cout<<"ShortInt Number"<<endl;
    }
    else cout<<"Otherwise"<<endl;

}


int main()
{
    string s;
    cin >> s;
    find(s);
}