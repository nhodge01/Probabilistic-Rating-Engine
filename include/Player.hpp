#pragma once
#include <iostream>
#include <iomanip>

struct Player {
  int id;

  // Beliefs (Outputs)
  double mu;
  double sigma;

  // Reality (Inputs)
  double skill;
  double volatility;

  // Everyone starts with the same beliefs
  Player() = delete;
  Player(int id, double skill, double vol) :
    id(id),
    mu(25.0),
    sigma(8.333),
    skill(skill),
    volatility(vol) {}

  double mmr() const {
    return mu - 3 * sigma;
  }

  void print() const {
    std::cout << "ID: " << std::setw(4) << id
              << " | Skill: " << std::setw(5) << skill
              << " | Consistency: " << std::setw(4) << volatility
              << " | MMR: " << std::setw(6) << std::fixed << std::setprecision(2) << mmr()
              << "\n";
  }  
};
