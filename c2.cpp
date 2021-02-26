// Description : (Misread the question, condition was <2, i thought it's <=2. Here's the solution for <=2)
// 3 arrays of activities are given
// Condition is, one can't select more than 2 activities from the
// same stream consecutively
// Objective is to find the max points gained

// Approach :
// maintain 2 layers
// layer 1 : you are at an array x, you select only some other array y
// which is not x, and layer2[i+1][y!=x] = max(layer2[i+1][y], layer1[i][x] + y[i+1])
// and layer1[i+1][x] = max(layer1[i+1][x], layer2[i][x] + x[i+1])

#include <bits/stdc++.h>
using namespace std;
#define prv(x) for(auto a:x){cout<<a<<" ";}cout<<endl;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<"opt\n";
    vector<int> temp1(3), temp2(3), layer1(3), layer2(3);
    layer2[0] = v[0][0];
    layer2[1] = v[0][1];
    layer2[2] = v[0][2];
    layer1[0] = layer1[1] = layer1[2] = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            temp1[j] = temp2[j] = 0;
        }
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==j)temp1[k] = max(temp1[k], layer2[k] + v[i][k]);
                else
                {
                    temp2[k] = max(temp2[k], max(layer1[j],layer2[j]) + v[i][k]);
                }
            }
        }
        layer1 = temp1;
        layer2 = temp2;
    }
    cout<<max(*max_element(layer1.begin(),layer1.end()),*max_element(layer2.begin(),layer2.end()))<<endl;
}