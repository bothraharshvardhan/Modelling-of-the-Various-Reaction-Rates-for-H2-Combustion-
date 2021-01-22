#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float dH2(float y,float x)
{
    float i,k = 1500;
    i = -2*k*y*x;
    return i;
}
float rkH2(float y,float x,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dH2(y,x);
    k2=h*dH2(y + (k1/2),x + (k1/2));
    k3=h*dH2(y + (k2/2),x + (k2/2));
    k4=h*dH2(y + k3,x + k3);
    r = y + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO2(float y,float x)
{
    float i,k = 1500;
    i = -1*k*y*x;
    return i;
}
float rkO2(float y,float x,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dO2(y,x);
    k2=h*dO2(y + (k1/2),x + (k1/2));
    k3=h*dO2(y + (k2/2),x + (k2/2));
    k4=h*dO2(y + k3,x + k3);
    r = x + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
int main()
{
    int i,j;
    float k,R=8.314,T,E,H2,H20,O2,H2i=6.5,O2i=3.25,A=9.9*pow(10,14),h;
    k = A*pow(2.71,(-(E/(R*T))));
    k = 1500;
    h=0.0000001;
    H2=H2i;
    O2=O2i;
    for (i=0;i<=5000;i++)
    {
        H2 = rkH2(H2,O2,h);
        O2 = rkO2(H2,O2,h);
        H20 = H2i - H2;
        cout<<H2<<"  "<<O2<<"   "<<H20<<endl;
    }
    
}

