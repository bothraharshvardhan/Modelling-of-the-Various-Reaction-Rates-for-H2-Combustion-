#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double f(double x) {
    long double E =16500;
	long double k = 3.52*pow(10,4)*pow(x,-0.7)*exp((-1*E/8.314)/x);
	return k;
}

double diff(double t) {
	long double k;
	long double d = pow(10,-3);
	 {
     // cout<<f(t+d)<<" "<<f(t-d);
		k= (f(t + d) - f(t - d))/ (2 * d);
	}


	return k;
}

int main() {

    long double d1=1;
    long double d2=2;
    long double T=2000;
	  long double T0;
    while(true)
    {
      T0=diff(T);

      if(abs(T0)<0.000001)
      {
        cout<<T<<endl;
        break;
      }
      else
      {
        T+=1;
      }
      if(T>10000)
      {
        break;
      }
    }
}