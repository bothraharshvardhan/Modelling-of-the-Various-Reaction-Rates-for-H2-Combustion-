#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float dH2(float y,float x,float z)
{
    float i,k1 =3030.79,k2 = 852.57;
    i = -1*k1*y*x - k2*z*y;
    return i;
}
float rkH2(float y,float x,float z,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dH2(y,x,z);
    k2=h*dH2(y + (k1/2),x + (k1/2),z + (k1/2));
    k3=h*dH2(y + (k2/2),x + (k2/2),z + (k2/2));
    k4=h*dH2(y + k3,x + k3,z + k3);
    r = y + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO2(float y,float x)
{
    float i,k1 =3030.79,k2 = 852.57;
    i = -1*k1*y*x;
    
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
float dOH(float y,float x,float z)
{
    float i,k1 =3030.79,k2 = 852.57;
    i = 2*k1*y*x - 2*k2*z*y;
    return i;
}
float rkOH(float y,float x,float z,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dOH(y,x,z);
    k2=h*dOH(y + (k1/2),x + (k1/2),z + (k1/2));
    k3=h*dOH(y + (k2/2),x + (k2/2),z + (k2/2));
    k4=h*dOH(y + k3,x + k3,z + k3);
    r = z + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
int main()
{
    int i,j;
    float k,R=8.314,T,E,H2,H20,O2,H2i=5,O2i=5,A,h,OH,k1,k2,t;
    k1 = 3030.79,k2 = 852.57;
    h=0.000001;
    OH=t=0;
    H2=H2i;
    O2=O2i;
    for (i=0;i<=5000;i++)
    {
        H2 = rkH2(H2,O2,OH,h);
        O2 = rkO2(H2,O2,h);
        OH = rkOH(H2,O2,OH,h);
        H20 = (O2i*2) + (-1*OH) + (-1*O2*2);
        t=t+h;
        cout<<H2<<"  "<<O2<<"   "<<OH<<"  "<<H20<<endl;
    }
    
}
