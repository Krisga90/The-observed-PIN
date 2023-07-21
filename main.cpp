#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> get_pins(std::string observed);

void keyPermutation(const std::vector<std::vector<char>>& keys, int pos, std::string password, std::vector<std::string>& result);

std::vector<std::vector<char>> getAllPossibleKeys(std::string &observed);
void print()
{
  std::string a = "125";
  int i = 0;
  auto result = get_pins(a);
  for (auto password : result) {
      std::cout << password;
    std::cout << std::endl;
  }
}

int main() {

  print();
  return 0;
}

std::vector<std::string> get_pins(std::string observed) {

  std::vector<std::string> result;
  std::string temp = "";
  keyPermutation(getAllPossibleKeys(observed), 0, temp, result);
  return result;
}

std::vector<std::vector<char>> getAllPossibleKeys(std::string &observed) {
  
  std::unordered_map<char, std::vector<char>> possible_keys = {
      {'1', {'1', '2', '4'}},
      {'2', {'1', '2', '3', '5'}},
      {'3', {'2', '3', '6'}},
      {'4', {'1', '4', '5', '7'}},
      {'5', {'2', '4', '5', '6', '8'}},
      {'6', {'3', '5', '6', '9'}},
      {'7', {'4', '7', '8'}},
      {'8', {'5', '7', '8', '9', '0'}},
      {'9', {'6', '9', '8'}},
      {'0', {'8', '0'}}
  };

  std::vector<std::vector<char>> keys;

  for (char key : observed) {
    keys.push_back(possible_keys.at(key));
  }
  return keys;
}

void keyPermutation(const std::vector<std::vector<char>>& keys, int pos, std::string password, std::vector<std::string>& result)
{
  if(pos == keys.size())
  {
    result.push_back(password);
    return;
  }

  for(char key: keys[pos])
  {
    password.push_back(key);
    keyPermutation(keys, pos+1, password, result);
    password.pop_back();
  }
}