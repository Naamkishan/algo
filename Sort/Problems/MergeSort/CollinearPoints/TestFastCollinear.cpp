#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include <boost/filesystem.hpp>

#include <gtest/gtest.h>

#include "fast_collinear.h"

namespace {
/**
 * @brief   get the data dir location
 *
 * However, this function assumes that the target (percolation) is in the following hierarchy:
 *      ${PROJECT_ROOT}/
 *          build/
 *              config/
 *
 * @return  absolute path of the data dir
 */
std::string get_data_dir() {
  boost::filesystem::path project_root = boost::filesystem::current_path().parent_path().parent_path();
  boost::filesystem::path data_dir_path = project_root.append("Sort/Problems/MergeSort/CollinearPoints/data");
  return data_dir_path.string();
}

}

class TestFastCollinear : public testing::Test {
 public:
  std::string get_path(const std::string& filename) {
    std::ostringstream oss;
    oss << get_data_dir() <<
        boost::filesystem::path::preferred_separator <<
        filename;

    return oss.str();
  }

  algo::problems::FastCollinear setup_FastCollinear(const std::string& filename, const std::size_t min_collinear_points = 4) {
    std::ifstream file(filename);
    std::size_t num_points{0};
    file >> num_points;
    int x, y;

    std::vector<algo::problems::Point>  points;

    for(std::size_t i = {0}; i < num_points; ++i) {
      file >> x >> y;
      points.push_back(algo::problems::Point(x, y));
    }

    return algo::problems::FastCollinear(std::begin(points), std::end(points), min_collinear_points);
  }
};

TEST_F(TestFastCollinear, CheckCollinear4_Input3) {
  std::string filename = get_path("input3.txt");

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.number_of_segments(), 0);
}

TEST_F(TestFastCollinear, CheckCollinear3_Input3) {
  std::string filename = get_path("input3.txt");

  algo::problems::FastCollinear fast = setup_FastCollinear(filename, 3);
  EXPECT_EQ(fast.number_of_segments(), 1);
}

TEST_F(TestFastCollinear, CheckCollinear4_Input6) {
  std::string filename = get_path("input6.txt");

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.number_of_segments(), 1);
}

TEST_F(TestFastCollinear, CheckCollinear4_Input8) {
  std::string filename = get_path("input8.txt");

  std::vector<algo::problems::LineSegment>  segments;

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  std::size_t num_segments = fast.number_of_segments();
  EXPECT_EQ(num_segments, 2);

  segments.reserve(num_segments);
  fast.segments(segments.begin());

  for(const algo::problems::LineSegment& line : segments) {
    line.print(std::cout);
    std::cout << '\t';
  }
  std::cout << std::endl;
  std::cout << std::endl;

}

TEST_F(TestFastCollinear, CheckCollinear4_Input10) {
  std::string filename = get_path("input10.txt");

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  std::size_t num_segments = fast.number_of_segments();
  EXPECT_EQ(num_segments, 2);

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(num_segments);
  fast.segments(segments.begin());

  for(const algo::problems::LineSegment& line : segments) {
    line.print(std::cout);
    std::cout << '\t';
  }
  std::cout << std::endl;
}

TEST_F(TestFastCollinear, CheckCollinear4_Input20) {
  std::string filename = get_path("input20.txt");

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  std::size_t num_segments = fast.number_of_segments();
  EXPECT_EQ(num_segments, 5);

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(num_segments);
  fast.segments(segments.begin());

  for(const algo::problems::LineSegment& line : segments) {
    line.print(std::cout);
    std::cout << '\t';
  }
  std::cout << std::endl;
}