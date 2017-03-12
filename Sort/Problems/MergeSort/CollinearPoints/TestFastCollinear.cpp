#include <cstdlib>
#include <fstream>
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

  algo::problems::FastCollinear setup_FastCollinear(const std::string& filename) {
    std::ifstream file(filename);
    std::size_t num_points{0};
    file >> num_points;
    int x, y;

    std::vector<algo::problems::Point>  points;

    for(std::size_t i = {0}; i < num_points; ++i) {
      file >> x >> y;
      points.push_back(algo::problems::Point(x, y));
    }

    return algo::problems::FastCollinear(std::begin(points), std::end(points));
  }
};

TEST_F(TestFastCollinear, CheckCollinear4_Input3) {
  std::string filename = get_path("input3.txt");

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(3);

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.get_line_segments(std::begin(segments)), 0);
}

TEST_F(TestFastCollinear, CheckCollinear3_Input3) {
  std::string filename = get_path("input3.txt");

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(3);

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.get_line_segments(std::begin(segments), 3), 1);
}

TEST_F(TestFastCollinear, CheckCollinear4_Input6) {
  std::string filename = get_path("input6.txt");

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(3);

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.get_line_segments(std::begin(segments)), 1);
}

TEST_F(TestFastCollinear, CheckCollinear4_Input8) {
  std::string filename = get_path("input8.txt");

  std::vector<algo::problems::LineSegment>  segments;
  segments.reserve(3);

  algo::problems::FastCollinear fast = setup_FastCollinear(filename);
  EXPECT_EQ(fast.get_line_segments(std::begin(segments)), 2);
}