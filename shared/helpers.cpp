#include "iostream"
#include "string"
#include "locale"
#include "cctype"
#include "vector"

const int defaultKey = 2;

int mod(int n, int m);
std::vector<int> toNumberVector(std::string s);
std::string fromNumberVector(std::vector<int> v, bool uppercase);
int toNumber(char c);
char toCharacter(int n, bool uppercase = true);
bool isalphaonly(std::string s);
std::string getMessage();
int getKey(int argc, char **argv);

int mod(int n, int m)
{
  while(n < 0)
  {
    n += m;
  }

  return n % m;
}

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
    throw "Character not recognized in toNumber method\n";
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

std::string getMessage()
{
  std::string message;
  std::cin >> message;
  if (isalphaonly(message) == false)
  {
    throw "Message must contain only alphabetic characters\n";
  }
  return message;
}

int getKey(int argc, char **argv)
{
  int key = defaultKey;
  if (argc == 2)
  {
    int customKey = toNumber(*argv[1]);
    if (std::isdigit(*argv[1]))
    {
      key = customKey;
    }
    else
    {
      throw "Key must be a number\n";
    }
  }
  return key;
}