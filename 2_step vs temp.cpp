#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float k(float T)//Fix ea in both
{
    float i,k,A = 2.3*pow(10,16),R=8.314,E=295888.86,a,b,c;
    i = A*pow(2.71,(-(E/(R*T))));
    return i;
}
float km(float T)
{
    float i,k,A = 1.83*pow(10,18),R=8.314,E=352206.9,a,b,c;
    i = A*pow(2.71,(-(E/(R*T))));
    return i;
}
int main()
{
    int i,j;//initial conc of H2,O2,OH = 10^-3
    float R=8.314,T=900,a,b,c,d;
    for (i=0;i<=80;i++)
    {
        a = -1*k(T)*(1*pow(10,-3))*(1*pow(10,-3)) - km(T)*(1*pow(10,-3))*(1*pow(10,-3));//H2
        b = -1*(1*pow(10,-3))*(1*pow(10,-3))*k(T);//O2
        c = -2*k(T)*(1*pow(10,-3))*(1*pow(10,-3)) - 2*km(T)*(1*pow(10,-3))*(1*pow(10,-3));//OH
        d = 2*km(T)*(1*pow(10,-3))*(1*pow(10,-3));//H2O
        cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
        T = T + 10;
    }
    
}