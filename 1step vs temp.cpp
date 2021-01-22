#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float k(float T)
{
    float i,k,A = 9.9*pow(10,14),R=8.314,E=103874,a,b,c;
    i = A*pow(2.71,(-(E/(R*T))));
    return i;
}
int main()
{
    int i,j;
    float A = 9.9*pow(10,14),R=8.314,T=1200,E=103874,a,b,c;
    for (i=0;i<=80;i++)
    {
        a = 2*(1*pow(10,-3))*(1*pow(10,-3))*k(T);
        b = -2*(1*pow(10,-3))*(1*pow(10,-3))*k(T);
        c = -1*(1*pow(10,-3))*(1*pow(10,-3))*k(T);
        cout<<a<<"  "<<b<<"  "<<c<<endl;
        T = T + 10;
    }
    
}