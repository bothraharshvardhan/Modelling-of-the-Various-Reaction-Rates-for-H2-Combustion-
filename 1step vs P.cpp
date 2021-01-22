#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    int i,j;
    float A = 9.9*pow(10,14),R=8.314,T=1200,E=103874,a,b,c,PO=0,PH=0,k;
    k = A*pow(2.71,(-(E/(R*T))));
    for (i=0;i<=200;i++)
    {
        a = 2*(PH/2)*(PO/2)*k/(2.05*pow(10,11));
        b = -2*(PH/2)*(PO/2)*k/(2.05*pow(10,11));
        c = -1*(PH/2)*(PO/2)*k/(2.05*pow(10,11));
        cout<<a<<"  "<<b<<"  "<<c<<endl;
        PH = PH + 0.1;
        PO = PO + 0.1;
    }
    
}