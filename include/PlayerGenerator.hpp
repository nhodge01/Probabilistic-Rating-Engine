#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Player.hpp"

class PlayerGenerator {
  private:
    std::mt19937 rng;

    const double POPULATION_MEAN_SKILL = 25.0;
    const double POPULATION_SKILL_SPREAD = 8.5;

    const double POPULATION_MEAN_VOLATILITY = 3.0;
    const double POPULATION_VOL_SPREAD = 1.0;

  public:
    PlayerGenerator() : rng(std::random_device{}()) {}

    std::vector<Player> generate(int count) {

      // Reserve Space
      std::vector<Player> population;
      population.reserve(count);

      // Skill Dist
      std::normal_distribution<double> skillDist(POPULATION_MEAN_SKILL, POPULATION_SKILL_SPREAD);

      // Volatility Dist
      std::normal_distribution<double> volDist(POPULATION_MEAN_VOLATILITY, POPULATION_VOL_SPREAD);

      for (int i = 0; i < count; ++i) {
        double skill = skillDist(rng);
        double vol = volDist(rng);

        // Fix Negative Values, Zero Volatility
        double final_skill = std::max(1.0, skill);
        double final_vol = std::max(0.5, vol);

        population.emplace_back(i, final_skill, final_vol);
      }

      return population;
    }
};
