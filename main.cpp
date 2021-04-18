#include <chrono>

#include "includes/matplotlibcpp.h"
#include "includes/arguments_parser.h"
#include "linear_fitting/linear_fitting.h"
#include "random_noise_generator/random_noise_generator.h"

namespace plt = matplotlibcpp;
using ClockT = std::chrono::steady_clock;

int main(int argc, const char* argv[])
{
  // Argument parser
  struct Arguments
  {
    std::string noise{ "linear" };
    std::string solver{ "least_squares" };
  };

  const auto parser = CmdOpts<Arguments>::Create({
    {"--noise", &Arguments::noise },
    {"--solver", &Arguments::solver},
    // TODO: Add help. For now, check README.
  });

  const auto arguments = parser->parse(argc, argv);

  // Random number generator
  rng::RandomNoiseGenerator rng = rng::RandomNoiseGenerator(arguments.noise);
  plt::scatter(rng.GetX(), rng.GetY(), {{"label", arguments.noise}});

  // Measure performance
  ClockT::time_point begin = ClockT::now();
  // Line fitting
  lf::LinearFitting lf = lf::LinearFitting(arguments.solver);
  lf.Fit(rng.GetX(), rng.GetY());
  ClockT::time_point end = ClockT::now();
  std::cout << "Run time = "
            << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count()
            << " µs" << std::endl;
  plt::plot(lf.GetX(), lf.GetY(), {{"label", arguments.solver}});

  // Plot
  plt::title("Line fit 2D noisy data");
  plt::legend();
  plt::show();

  return 0;
}
