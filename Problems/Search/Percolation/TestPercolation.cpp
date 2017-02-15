/**
 * @details :   carries out all the test cases for percolation
 */

#include <algorithm>
#include <fstream>
#include <numeric>
#include <iterator>
#include <sstream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>

#include "percolation.h"

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
  boost::filesystem::path data_dir_path = project_root.append("Problems/Search/Percolation/test-data");
  return data_dir_path.string();
}

const std::string data_dir = get_data_dir() + "/";

}

auto open_percolation_from_input_file(const std::string& test_data_file) {
  std::ifstream input_file{test_data_file};

  if(input_file) {
    std::size_t grid_dimensions;
    input_file >> grid_dimensions;

    algo::problems::Percolation percolation{grid_dimensions};

    std::string line_contents;
    int row{1}, col{1};
    while (std::getline(input_file, line_contents)) {
      boost::trim(line_contents);
      if (!line_contents.empty()) {
        std::stringstream oss;
        oss << line_contents;
        oss >> row >> col;
        percolation.open(row - 1, col - 1);
      }
    }
    return percolation;
  }

  throw std::logic_error("Invalid Input File!");
}

TEST(TestPercolation, Input1Negative) {
  std::string test_data_file{data_dir + "input1-no.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);
  EXPECT_FALSE(percolation.percolates());
}

TEST(TestPercolation, Input1Positive) {
  std::string test_data_file{data_dir + "input1.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Input2Negative) {
  std::string test_data_file{data_dir + "input2-no.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_FALSE(percolation.percolates());
}

TEST(TestPercolation, Input2Positive) {
  std::string test_data_file{data_dir + "input2.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Input3Positive) {
  std::string test_data_file{data_dir + "input3.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Input4Positive) {
  std::string test_data_file{data_dir + "input4.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Input6Positive) {
  std::string test_data_file{data_dir + "input6.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Input8Negative) {
  std::string test_data_file{data_dir + "input8-no.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_FALSE(percolation.percolates());
}

TEST(TestPercolation, Input50Positive) {
  std::string test_data_file{data_dir + "input50.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Jerry47Positive) {
  std::string test_data_file{data_dir + "jerry47.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
}

TEST(TestPercolation, Wayne98Positive) {
  std::string test_data_file{data_dir + "wayne98.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_TRUE(percolation.percolates());
  EXPECT_EQ(percolation.number_of_open_sites(), 5079);
}

TEST(TestPercolation, Greeting57Negative) {
  std::string test_data_file{data_dir + "greeting57.txt"};
  algo::problems::Percolation percolation = open_percolation_from_input_file(test_data_file);

  EXPECT_FALSE(percolation.percolates());
  EXPECT_EQ(percolation.number_of_open_sites(), 2522);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
