#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include <Eigen/Dense>

namespace rng
{
class RandomNoiseGenerator
{
public:
  RandomNoiseGenerator(const std::string& type = "linear");
  Eigen::ArrayXf GetX() const { return noise_x_; };
  Eigen::ArrayXf GetY() const { return noise_y_; };
private:
  // Noise generators
  void Linear();
  void Quadratic();
  void SimplifiedCholesky();
  // Callback to register generators
  std::unordered_map<std::string, std::function<void()>> callbacks_ {
    std::make_pair("", [this](){ Linear(); }),  // Default
    std::make_pair("linear", [this](){ Linear(); }),
    std::make_pair("quadratic", [this](){ Quadratic(); }),
    std::make_pair("cholesky", [this](){ SimplifiedCholesky(); }),
    // Another example: https://en.wikipedia.org/wiki/Anscombe%27s_quartet
  };
  // Size of the population on each dimension
  const size_t size_{ 100 };
  // Noise is obtained from two arrays
  Eigen::ArrayXf noise_x_{ size_ };
  Eigen::ArrayXf noise_y_{ size_ };
};
} // namespace rng
