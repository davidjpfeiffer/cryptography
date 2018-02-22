#include "iostream"
#include "string"

#include "../shared/helpers.cpp"
#include "../shared/keys.cpp"
#include "../shared/mathUtilities.cpp"

std::vector<int> encrypt(std::vector<int> ptn, int key);

int main(int argc, char **argv)
{
  int key = argc == 2 ? getNumberKey(argc, argv) : keys.shiftCipher.encryptionKey;
  std::string pt = getInput();
  std::vector<int> ptn = toNumberVector(pt);
  std::vector<int> ctn = encrypt(ptn, key);
  std::string ct = fromNumberVector(ctn, true);
  std::cout << ct;

  return 0;
}

std::vector<int> encrypt(std::vector<int> ptn, int key)
{
  std::vector<int> ctn = std::vector<int>(ptn.size());

  for (int i = 0; i < ctn.size(); i++)
  {
    ctn[i] = mod(ptn[i] + keys.shiftCipher.encryptionKey, 26);
  }

  return ctn;
}