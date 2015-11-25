#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

cv::RNG rng(12345);

int main(int argc, char** argv)
{
  std::string fname = std::string(argv[1]);
  cv::Mat gray, blur, edges, img = cv::imread(fname);

  if (img.empty())
  {
      std::cout << "Cannot open source image!" << std::endl;
      return -1;
  }

  // convert to greyscale and run canny edge detection
  cv::cvtColor(img, gray, CV_BGR2GRAY);
  cv::GaussianBlur(gray, blur, cv::Size2f(5, 5), 3);
  cv::Canny(blur, edges, 75, 200);

  // find contours
  cv::vector<cv::vector<cv::Point> > contours;
  cv::findContours(edges, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

  for( int i = 0; i< contours.size(); i++ ) {
    cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    cv::drawContours( img, contours, i, color, 2, 8, 0, 0 );
  }

  // display output
  cv::imshow("result", img);
  cv::waitKey(0);
}
