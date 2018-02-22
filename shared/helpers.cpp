#ifndef __HELPERS
#define __HELPERS

#include "iostream"
#include "string"
#include "locale"
#include "cctype"
#include "vector"
#include "cmath"

#include "./matrix.h"
#include "./mathUtilities.cpp"

std::vector<int> toNumberVector(std::string s);
std::string fromNumberVector(std::vector<int> v, bool uppercase);
int toNumber(char c);
int toNumber(std::string s);
char toCharacter(int n, bool uppercase = true);
bool isalphaonly(std::string s);
std::string getInput();
int getNumberKey(int argc, char **argv);
std::vector<int> getVectorKey(int argc, char **argv);
Matrix getMatrixKey(int argc, char **argv);

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
    throw;
  }
}

int toNumber(std::string s)
{
  int n = 0;
  int length = s.length();

  for (int i = 0; i < length; i++)
  {
    if (std::isdigit(s[i]))
    {
      n += toNumber(s[length - i - 1]) * pow(10, i);
    }
    else
    {
      std::cout << "Number key must contain only numbers\n";
      throw;
    }
  }

  return n;
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
    throw;
  }
  return input;
}

int getNumberKey(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Number key must be a number\n";
    throw;
  }

  return toNumber(argv[1]);
}

std::vector<int> getVectorKey(int argc, char **argv)
{
  std::vector<int> v;

  for (int i = 1; i < argc; i++)
  {
    v.push_back(toNumber(argv[i]));
  }

  return v;
}

Matrix getMatrixKey(int argc, char **argv)
{
  return Matrix(getVectorKey(argc, argv));
}

#endif