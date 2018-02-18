#include "iostream"
#include "string"

#include "../shared/helpers.cpp"

std::vector<int> decrypt(std::vector<int> ctn, int key);
int getKey(int argc, char **argv);

int main(int argc, char **argv)
{
  int key = getKey(argc, argv);
  std::string ct = getMessage();
  std::vector<int> ctn = toNumberVector(ct);
  std::vector<int> ptn = decrypt(ctn, key);
  std::string pt = fromNumberVector(ptn, false);
  std::cout << pt;

  return 0;
}

std::vector<int> decrypt(std::vector<int> ctn, int key)
{
  std::vector<int> ptn = std::vector<int>(ctn.size());

  for (int i = 0; i < ptn.size(); i++)
  {
    ptn[i] = mod(ctn[i] - key, 26);
  }

  return ptn;
}