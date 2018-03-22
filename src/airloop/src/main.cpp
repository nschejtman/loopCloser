#include <iostream>
#include <typeinfo>
#include "Feature2DFactory.hpp"

using namespace std;
int main(){
  cout << typeid(FeatureFactory::getClass("SURF")).name() << endl;
  return 0;
}
