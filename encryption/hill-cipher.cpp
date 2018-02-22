#include "iostream"
#include "string"
#include "vector"

#include "../shared/matrix.h"
#include "../shared/helpers.cpp"
#include "../shared/keys.cpp"

int main(int argc, char **argv)
{
  Matrix key = argc == 10 ? getMatrixKey(argc, argv) : keys.hillCipher.encryptionKey;
  std::string pt = getInput();
  std::vector<int> ptv = toNumberVector(pt);
  Matrix ptm = Matrix(ptv);
  Matrix ctm = (key * ptm) % 26;
  std::vector<int> ctv = ctm.toVector();
  std::string ct = fromNumberVector(ctv, true);
  std::cout << ct;

  return 0;
}