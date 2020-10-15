#include <iostream>
#include <string>
class ForceBeing {
  private:
    int power_level;
    std::string name;
    bool evil;

  public:
    ForceBeing(int level) {
      power_level = level;
    }

  void setPowerLevel(int level) {
    power_level = level;
  } 

  int getPowerLevel() {
    return power_level;
  }

  void setName(std::string characterName) {
    name = characterName;
  }

  std::string getName() {
    return name;
  }

  void setEvil() {
    evil = true;
  } 

  void setGood() {
    evil = false;
  }
};

class Jedi: public ForceBeing {
  public:
    Jedi(std::string JediName, int level) : ForceBeing(level) {
      setName(JediName);
      setGood();
    }

    int getPowerLevel() {
      return ForceBeing::getPowerLevel() - 1;
    }

    std::string getName() {
      return "Jedi Knight: " + ForceBeing::getName();
    }

};

class Sith: public ForceBeing {
  public:
    Sith(std::string SithName, int level) : ForceBeing(level) {
      setName(SithName);
      setGood();
    }

    int getPowerLevel() {
      return ForceBeing::getPowerLevel() - 1;
    }

    std::string getName() {
      return "Sith Lord: " + ForceBeing::getName();
    }

};

std::string getWinner(ForceBeing &player1, ForceBeing &player2) {
  return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
}

void printWinner(std::string winner) {
  std::cout << "The winner is: " << winner << std::endl;
}

int main() {
  Sith darthVader("Darth Vader", 100);
  Jedi lukeSkywalker("Luke Skywalker", 99);
  printWinner(getWinner(darthVader, lukeSkywalker));
  return 0;
}