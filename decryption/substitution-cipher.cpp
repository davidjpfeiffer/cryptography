#include "iostream"
#include "string"

#include "../shared/helpers.cpp"
#include "../shared/keys.cpp"
#include "../shared/mathUtilities.cpp"

std::vector<int> decrypt(std::vector<int> ctn, std::vector<int> key);

int main(int argc, char **argv)
{
  std::vector<int> key = argc == 2 ? getVectorKey(argc, argv) : keys.substitutionCipher.decryptionKey;
  std::string ct = getInput();
  std::vector<int> ctn = toNumberVector(ct);
  std::vector<int> ptn = decrypt(ctn, key);
  std::string pt = fromNumberVector(ptn, false);
  std::cout << pt;

  return 0;
}

std::vector<int> decrypt(std::vector<int> ctn, std::vector<int> key)
{
  std::vector<int> ptn = std::vector<int>(ctn.size());

  for (int i = 0; i < ptn.size(); i++)
  {
    ptn[i] = key[ctn[i]];
  }

  return ptn;
}