#include <Eigen/Dense>
#include <gtest/gtest.h>

#include "linear_fitting.cpp"

namespace lf
{
namespace
{
class LinearFittingFixture
  : public LinearFitting, public testing::Test
{
protected:
  LinearFittingFixture(): LinearFitting() {};
};

TEST_F(LinearFittingFixture, LinearFitting) {
  // Initialization
  Eigen::ArrayXf noise_x{ 2 };
  noise_x << 0, 1;
  Eigen::ArrayXf noise_y{ 2 };
  noise_y << 0, 1;

  Line line = Fit(noise_x, noise_y);
  ASSERT_FLOAT_EQ(line.m, 1.0f);
  ASSERT_FLOAT_EQ(line.b, 0.0f);
}
} // namespace
} // namespace lf
