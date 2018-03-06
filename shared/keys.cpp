#ifndef __KEYS
#define __KEYS

#include "vector"
#include "utility"

#include "./matrix.h"

struct keys_t {
  struct shiftCipher_t {
    int encryptionKey = 2;
    int decryptionKey = -2;
  } shiftCipher;
  struct multiplicativeCipher_t {
    int encryptionKey = 3;
    int decryptionKey = 9;
  } multiplicativeCipher;
  struct affineCipher_t {
    std::pair<int, int> encryptionKey = std::make_pair(3, 5);
    std::pair<int, int> decryptionKey = std::make_pair(9, -5);
  } affineCipher;
  struct hillCipher_t {
    Matrix encryptionKey = Matrix({10, 23, 1, 9, 21, 0, 3, 5, 5}); // {10, 9, 3, 23, 21, 5, 1, 0, 5}
    Matrix decryptionKey = Matrix({17, 2, 7, 15, 19, 23, 6, 11, 25}); // {17, 15, 6, 2, 19, 11, 7, 23, 25}
  } hillCipher;
} keys;

#endif