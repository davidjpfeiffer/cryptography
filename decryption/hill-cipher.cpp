#include "iostream"
#include "string"
#include "vector"

#include "../shared/matrix.h"
#include "../shared/helpers.cpp"
#include "../shared/keys.cpp"

int main(int argc, char **argv)
{
  Matrix key = argc == 10 ? getMatrixKey(argc, argv) : keys.hillCipher.decryptionKey;
  std::string ct = getInput();
  std::vector<int> ctv = toNumberVector(ct);
  Matrix ctm = Matrix(ctv);
  Matrix ptm = (key * ctm) % 26;
  std::vector<int> ptv = ptm.toVector();
  std::string pt = fromNumberVector(ptv, false);
  std::cout << pt;

  return 0;
}