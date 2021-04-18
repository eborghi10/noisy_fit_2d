#include <iostream>
#include <memory>
#include <string>

// Base class
#include "noises/random_noise_base.h"

// Noise classes
#include "noises/linear.h"
#include "noises/quadratic.h"
#include "noises/simplified_cholesky.h"

namespace rng
{
using RandomNoiseBasePtr = std::unique_ptr<RandomNoiseBase>;

class RandomNoiseFactory
{
public:
  /**
   * \brief Generator of RandomNoiseBase.
   * \param type Type of noise generator. Available options are: linear, quadratic and cholesky.
   * \return Pointer to RandomNoiseBase.
   */
  static RandomNoiseBasePtr Make(const std::string& type = "linear")
  {
    std::cout << "Noise = " << type << std::endl;
    if(type == "linear") {
      return std::make_unique<LinearNoise>();
    }
    else if(type == "quadratic") {
      return std::make_unique<QuadraticNoise>();
    }
    else if(type == "cholesky") {
      return std::make_unique<SimplifiedCholesky>();
    }
    else {
      // Default uses linear
      return std::make_unique<LinearNoise>();
    }
    // Another example: https://en.wikipedia.org/wiki/Anscombe%27s_quartet
}
};
} // namespace rng
