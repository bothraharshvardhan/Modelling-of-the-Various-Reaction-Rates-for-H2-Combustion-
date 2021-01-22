#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

float f(float x) {
    float E =16500;
	float k = 3.52*pow(10,16)*pow(x,-0.7)*exp((-1*E/8.314)/x);
	return k;
}

float diff(float t) {
	float k;
	float d = pow(10, -4);
	 {
		k= (f(t + d) - f(t - d)) / (2 * d);
	}
	
	
	return k;
}

int main() {

    float x=pow(10,1);
    float d1;
    float T=100;
	
	for(int i=1;i<1000;i++){
	    d1=f(T);

	    cout<<T<<"   "<<d1<<endl;
		T = T + x;
	}

}