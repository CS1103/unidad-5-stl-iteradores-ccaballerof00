#include <iostream>
#include "GeoProgression.h"
#include "ArithProgression.h"

using namespace std;

int main() {
cout<<"Progresión geomética"<<endl;
for(auto i: GeoProgression{1,1000,5})
    cout<<i<<" ";
cout<<endl;
cout<<"Progresión aritmética"<<endl;
for(auto i: ArithProgression(0,20,2))
    cout<<i<<" ";

}