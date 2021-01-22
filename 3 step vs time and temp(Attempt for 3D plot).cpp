#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
float dH2(float H2,float O2,float OH,float H,float O,float k1,float k2,float k3)
{
    float i;
    i = -1*k2*H2*O - k3*H2*OH;
    return i;
}
float rkH2(float H2,float O2,float OH,float H,float O,float h,float m1,float m2,float m3)
{
    float r,k1,k2,k3,k4;
    k1=h*dH2(H2,O2,OH,H,O,m1,m2,m3);
    k2=h*dH2(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2),m1,m2,m3);
    k3=h*dH2(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2),m1,m2,m3);
    k4=h*dH2(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3,m1,m2,m3);
    r = H2 + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO2(float H2,float O2,float OH,float H,float O,float k1,float k2,float k3)
{
    float i;
    i = -1*k1*O2*H;
    return i;
}
float rkO2(float H2,float O2,float OH,float H,float O,float h,float m1,float m2,float m3)
{
    float r,k1,k2,k3,k4;
    k1=h*dO2(H2,O2,OH,H,O,m1,m2,m3);
    k2=h*dO2(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2),m1,m2,m3);
    k3=h*dO2(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2),m1,m2,m3);
    k4=h*dO2(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3,m1,m2,m3);
    r = O2 + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dH(float H2,float O2,float OH,float H,float O,float k1,float k2,float k3)
{
    float i;
    i = -1*k1*H*O2 + k2*H2*O + k3*H2*OH;
    return i;
}
float rkH(float H2,float O2,float OH,float H,float O,float h,float m1,float m2,float m3)
{
    float r,k1,k2,k3,k4;
    k1=h*dH(H2,O2,OH,H,O,m1,m2,m3);
    k2=h*dH(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2),m1,m2,m3);
    k3=h*dH(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2),m1,m2,m3);
    k4=h*dH(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3,m1,m2,m3);
    r = H + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dO(float H2,float O2,float OH,float H,float O,float k1,float k2,float k3)
{
    float i;
    i = k1*H*O2 - k2*H2*O;
    return i;
}
float rkO(float H2,float O2,float OH,float H,float O,float h,float m1,float m2,float m3)
{
    float r,k1,k2,k3,k4;
    k1=h*dO(H2,O2,OH,H,O,m1,m2,m3);
    k2=h*dO(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2),m1,m2,m3);
    k3=h*dO(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2),m1,m2,m3);
    k4=h*dO(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3,m1,m2,m3);
    r = O + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float dOH(float H2,float O2,float OH,float H,float O,float k1,float k2,float k3)
{
    float i;
    i = k1*H*O2 + k2*H2*O - k3*H2*OH;
    return i;
}
float rkOH(float H2,float O2,float OH,float H,float O,float h,float m1,float m2,float m3)
{
    float r,k1,k2,k3,k4;
    k1=h*dOH(H2,O2,OH,H,O,m1,m2,m3);
    k2=h*dOH(H2 + (k1/2),O2 + (k1/2),OH + (k1/2),H + (k1/2),O + (k1/2),m1,m2,m3);
    k3=h*dOH(H2 + (k2/2),O2 + (k2/2),OH + (k2/2),H + (k2/2),O + (k2/2),m1,m2,m3);
    k4=h*dOH(H2 + k3,O2 + k3,OH + k3,H + k3,O + k3,m1,m2,m3);
    r = OH + (k1 + 2*k2 + 2*k3 + k4)/6;
    return r;
}
float m1(float T)
{
    float A = 3.52*pow(10,16),E = 283716,R = 8.314,i;
    i = A*pow(T,-0.7)*pow(2.71,(-(E/(R*T))));
    return i;
}
float m3(float T)
{
    float A = 5.06*pow(10,4),E =239037 ,R = 8.314,i;
    i = A*pow(T,2.7)*pow(2.71,(-(E/(R*T))));
    return i;
}
float m2(float T)
{
    float A = 1.17*pow(10,9),E = 238135,R = 8.314,i;
    i = A*pow(T,1.3)*pow(2.71,(-(E/(R*T))));
    return i;
}

int main()
{
    int i,j;
    float k,R=8.314,T,E,H2,H20=0,O2,H2i=5,O2i=5,A,h,OH,H=5,O=5,Oi=5,k1,k2,k3,h1;
    T = 1000,h1 = 5;
    OH=0;
    H2=H2i;
    O2=O2i;
    cout<<H2<<"  "<<O2<<"   "<<O<<"   "<<H<<"   "<<OH<<"   "<<H20<<endl;
    for (i=0;i<=1000;i++)
    {
        k1=m1(T);
        k2=m2(T);
        k3=m3(T);
        cout<<T<<" "<<k1<<" "<<k2<<" "<<k3<<endl;
        h = 0.1/k2;
        for (j=0;j<=0.5/h;j++)
        {
            O = rkO(H2,O2,OH,H,O,h,k1,k2,k3);
            H = rkH(H2,O2,OH,H,O,h,k1,k2,k3);
            H2 = rkH2(H2,O2,OH,H,O,h,k1,k2,k3);
            O2 = rkO2(H2,O2,OH,H,O,h,k1,k2,k3);
            OH = rkOH(H2,O2,OH,H,O,h,k1,k2,k3);
            H20 = (O2i*2) + Oi + (-1*OH) + (-1*O2*2) - O;
            cout<<H2<<"  "<<O2<<"   "<<O<<"   "<<H<<"   "<<OH<<"   "<<H20<<endl;
        }
        cout<<endl;
        T = T + h1;
        H=5,O=5,H2=H2i,O2=O2i,H20=0,OH=0;
    }

}