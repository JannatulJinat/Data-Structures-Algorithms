/*
Next Largest Element
NGR = next greater to right
stack -> right array
Element        Output:NGE
1                   3
3                   4
2                   4
4                  -1
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void using_stack(vector<int>element, int n)
{
    vector<int> NGE ;
    stack <int> stk;
    for(int i=n-1; i>=0 ; i--)
    {
        if(stk.empty())
        {
            NGE.push_back(-1);
        }
        else if(!stk.empty() && stk.top()> element[i])
        {
            NGE.push_back(stk.top());
        }
        else if(!stk.empty() && stk.top() <= element[i])
        {
            while(!stk.empty() && stk.top() <= element[i])
            {
                stk.pop();
            }
            if(stk.empty())
                NGE.push_back(-1);
            else
                NGE.push_back(stk.top());
        }
        stk.push(element[i]);
    }
    cout<<"Element: ";
    for(int value : element)
        cout<<value<<" ";
    cout<<"\nNGE:\t ";
    reverse(NGE.begin(),NGE.end());
    for(int value : NGE)
        cout<<value<<" ";
}
void brute_force(vector<int>element, int n)
{
    int ans;
    for(int i=0; i<n; i++)
    {
        ans = -1;
        for(int j = i+1; j<n; j++)
        {
            if(element[i]<element[j])
            {
                ans = element[j];
                break;
            }
        }
        cout<< element[i] << "  " << ans <<endl;
    }
}
int main()
{
    vector<int>element{1,3,2,4};
    int n = element.size();

    brute_force(element,n); //O(n^2)

    cout<<endl;

    using_stack(element,n); //O(n)

    return  0;
}
