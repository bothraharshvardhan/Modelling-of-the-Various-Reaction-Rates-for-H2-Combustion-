#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float dH2(float H2,float O2,float OH,float H,float O)
{
    float i,k1 = 109.85,k2 = 409.75,k3 = 506.99;
    i = -1*k2*H2*O - k3*H2*OH;
    return i;
}
float rkH2(float H2,float O2,float OH,float H,float O,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dH2(H2,O2,OH,H,O);
    k2=h*dH2(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2));
    k3=h*dH2(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2));
    k4=h*dH2(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3);
    r = H2 + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO2(float H2,float O2,float OH,float H,float O)
{
    float i,k1 = 109.85,k2 = 409.75,k3 = 506.99;
    i = -1*k1*O2*H;
    return i;
}
float rkO2(float H2,float O2,float OH,float H,float O,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dO2(H2,O2,OH,H,O);
    k2=h*dO2(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2));
    k3=h*dO2(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2));
    k4=h*dO2(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3);
    r = O2 + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dH(float H2,float O2,float OH,float H,float O)
{
    float i,k1 = 109.85,k2 = 409.75,k3 = 506.99;
    i = -1*k1*H*O2 + k2*H2*O + k3*H2*OH;
    return i;
}
float rkH(float H2,float O2,float OH,float H,float O,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dH(H2,O2,OH,H,O);
    k2=h*dH(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2));
    k3=h*dH(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2));
    k4=h*dH(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3);
    r = H + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO(float H2,float O2,float OH,float H,float O)
{
    float i,k1 = 109.85,k2 = 409.75,k3 = 506.99;
    i = k1*H*O2 - k2*H2*O;
    return i;
}
float rkO(float H2,float O2,float OH,float H,float O,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dO(H2,O2,OH,H,O);
    k2=h*dO(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2));
    k3=h*dO(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2));
    k4=h*dO(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3);
    r = O + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dOH(float H2,float O2,float OH,float H,float O)
{
    float i,k1 = 109.85,k2 = 409.75,k3 = 506.99;
    i = k1*H*O2 + k2*H2*O - k3*H2*OH;
    return i;
}
float rkOH(float H2,float O2,float OH,float H,float O,float h)
{
    float r,k1,k2,k3,k4;
    k1=h*dOH(H2,O2,OH,H,O);
    k2=h*dOH(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2));
    k3=h*dOH(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2));
    k4=h*dOH(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3);
    r = OH + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
int main()
{
    int i,j;
    float k,R=8.314,T,E,H2,H20=0,O2,H2i=5,O2i=5,A,h,OH,H=5,O=5,Oi=5,k1,k2,k3;
    k = A*pow(2.71,(-(E/(R*T))));
    k1 = 109.85,k2 = 409.75,k3 = 506.99;
    h = 0.00001;
    OH=0;
    H2=H2i;
    O2=O2i;
    cout<<H2<<"  "<<O2<<"   "<<O<<"   "<<H<<"   "<<OH<<"   "<<H20<<endl;
    for (i=0;i<=5000;i++)
    {
        O = rkO(H2,O2,OH,H,O,h);
        H = rkH(H2,O2,OH,H,O,h);
        H2 = rkH2(H2,O2,OH,H,O,h);
        O2 = rkO2(H2,O2,OH,H,O,h);
        OH = rkOH(H2,O2,OH,H,O,h);
        H20 = (O2i*2) + Oi + (-1*OH) + (-1*O2*2) - O;
        cout<<H2<<"  "<<O2<<"   "<<O<<"   "<<H<<"   "<<OH<<"   "<<H20<<endl;
    }
    
}
