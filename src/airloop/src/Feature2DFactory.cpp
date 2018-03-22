#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Feature2DFactory.hpp"
#include <map>

using namespace cv;
using namespace std;
using namespace FeatureFactory;


typedef Ptr<Feature2D> (*algo_creator_t)();

// proxy functions are needed since SIFT::create() etc. have optional parameters,
// so the function pointers can not be unified.
Ptr<Feature2D> create_SIFT() { return SIFT::create(); }
Ptr<Feature2D> create_ORB() { return ORB::create(); }
Ptr<Feature2D> create_SURF() { return SURF::create(); }
Ptr<Feature2D> create_FAST() { return FastFeatureDetector::create(50); }

// Map
map<string, algo_creator_t> createMap(){
  map<string, algo_creator_t> m;
  m["SIFT"] = create_SIFT;
  m["SURF"] = create_SURF;
  m["ORB"] = create_ORB;
  m["FAST"] = create_FAST;
  return m;
}
map<string, algo_creator_t> factory = createMap();


Ptr<Feature2D> getClass(const string name){
  return factory[name]();
}
