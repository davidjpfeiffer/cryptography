#ifndef __HELPERS
#define __HELPERS

#include "iostream"
#include "string"
#include "locale"
#include "cctype"
#include "vector"
#include "cmath"

#include "./matrix.h"

std::vector<int> toNumberVector(std::string s);
std::string fromNumberVector(std::vector<int> v, bool uppercase);
int toNumber(char c);
char toCharacter(int n, bool uppercase = true);
bool isalphaonly(std::string s);
std::string getInput();
int getNumberKey(int argc, char **argv);
Matrix getMatrixKey(int argc, char **argv);
Matrix multiply(Matrix a, Matrix b);

std::vector<int> toNumberVector(std::string s)
{
  std::vector<int> v = std::vector<int>(s.length());

  for (int i = 0; i < s.length(); i++)
  {
    v[i] = toNumber(s[i]);
  }

  return v;
}

std::string fromNumberVector(std::vector<int> v, bool uppercase)
{
  std::string s(v.size(), '\0');

  for (int i = 0; i < v.size(); i++)
  {
    s[i] = toCharacter(v[i], uppercase);
  }

  return s;
}

int toNumber(char c)
{
  int cv = (int)c;
  if (cv > 47 && cv < 58)
  {
    return cv - 48;
  }
  else if (cv > 64 && cv < 91)
  {
    return cv - 65;
  }
  else if (cv > 96 && cv < 123)
  {
    return cv - 97;
  }
  else
  {
    std::cout << "Character not recognized\n";
    throw "Character not recognized\n";
  }
}

char toCharacter(int n, bool uppercase)
{
  return uppercase ? (char)(n + 65) : (char)(n + 97);
}

bool isalphaonly(std::string s)
{
  for (char c : s)
  {
    if (std::isalpha(c) == false)
    {
      return false;
    }
  }

  return true;
}

std::string getInput()
{
  std::string input;
  std::cin >> input;
  if (isalphaonly(input) == false)
  {
    std::cout << "Input must contain only alphabetic characters\n";
    throw "Input must contain only alphabetic characters\n";
  }
  return input;
}

int getNumberKey(int argc, char **argv)
{
  int key;
  if (argc == 2)
  {
    int customKey = toNumber(*argv[1]);
    if (std::isdigit(*argv[1]))
    {
      key = customKey;
    }
    else
    {
      std::cout << "Key must be a number\n";
      throw "Key must be a number\n";
    }
  }
  return key;
}

Matrix getMatrixKey(int argc, char **argv)
{
  std::vector<int> key;

  for (int i = 1; i < argc; i++)
  {
    key.push_back(toNumber(*argv[i]));
  }

  return Matrix(key);
}

#endif