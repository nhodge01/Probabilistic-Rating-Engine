#pragma once
#include <random>
#include "Player.hpp"

// Choas Factor (Server Lag, Outside Forces, Mom Asking for the Player, etc...)
const double GLOBAL_NOISE = 1.0;

class MatchSimulator {
  private:
    std::mt19937 rng;

  public:
    MatchSimulator() : rng(std::random_device{}()) {}

    bool playDual(const Player& pA, const Player& pB) {

      // Evaluates to one number
      std::normal_distribution<double> distA(pA.skill, pA.volatility + GLOBAL_NOISE);
      double perfA = distA(rng);

      std::normal_distribution<double> distB(pB.skill, pB.volatility + GLOBAL_NOISE);
      double perfB = distB(rng);

      return perfA > perfB;     
    }
};
