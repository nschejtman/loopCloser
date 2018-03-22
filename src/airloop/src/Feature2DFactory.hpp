#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

namespace FeatureFactory {
  Ptr<Feature2D> getClass(const string name);
}
