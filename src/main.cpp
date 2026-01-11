#include <iostream>
#include <vector>
#include "Player.hpp"
#include "DualSimulator.hpp"

int main() {
  MatchSimulator simulator;

  Player p1(1, 30, 1);
  Player p2(2, 25, 8);

  int p1Wins = 0;
  int p2Wins = 0;
  int matches = 1000;

  std::cout << "--- Fight Club ---\n";
  std::cout << "P1 (Pro): Skill 30, Vol 1\n";
  std::cout << "P2 (Wild): Skill 25, Vol 8\n";

  for (int i = 0; i < matches; ++i) {
    if(simulator.playDual(p1, p2)) {
      p1Wins++;
    } else {
      p2Wins++;
    }
  }

  std::cout << "Results After " << matches << " matches\n";
  std::cout << "P1 Wins: " << p1Wins << " (" << (p1Wins * 100 / matches) << "%)\n";
  std::cout << "P2 Wins: " << p2Wins << " (" << (p2Wins * 100 / matches) << "%)\n";

  return 0;
}
