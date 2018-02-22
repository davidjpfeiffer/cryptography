#ifndef __MATRIX
#define __MATRIX

#include "vector"

#include "./mathUtilities.cpp"

class Matrix
{
public:
  int rows = 0, columns = 0;

  Matrix(int rows, int columns)
  {
    this->rows = rows;
    this->columns = columns;
    this->size = rows * columns;
    this->allocateMatrix();
  }

  Matrix(std::vector<int> v, int rows = 3)
  {
    this->set(v, rows);
  }

  int get(int row, int column) const
  {
    return this->m[row][column];
  }

  int set(int row, int column, int value)
  {
    this->m[row][column] = value;
  }

  void set(std::vector<int> v, int rows = 3)
  {
    this->size = v.size();
    this->rows = rows;
    this->columns = size % rows == 0 ? size / rows : (size / rows) + 1;
    this->allocateMatrix();

    for (int column = 0; column < this->columns; column++)
    {
      for (int row = 0; row < rows; row++)
      {
        int n = (column * this->rows) + row;
        if (n < size)
        {
          this->m[row][column] = v[n];
        }
      }
    }
  }

  std::vector<int> toVector() const
  {
    std::vector<int> v;

    for (int column = 0; column < this->columns; column++)
    {
      for (int row = 0; row < this->rows; row++)
      {
        int n = (column * this->rows) + row;
        if (n < this->size)
        {
          v.push_back(this->m[row][column]);
        }
      }
    }

    return v;
  }

  void print() const
  {
    for (int row = 0; row < this->rows; row++)
    {
      for (int column = 0; column < this->columns; column++)
      {
        std::cout << this->m[row][column] << ' ';
      }
      std::cout << '\n';
    }
  }

private:
  int **m;
  int size = 0;

  void allocateMatrix()
  {
    this->m = new int *[this->rows];
    for (int i = 0; i < this->rows; ++i)
    {
      m[i] = new int[this->columns];
    }
  }

  void deallocateMatrix()
  {
    for (int i = 0; i < this->columns; ++i)
    {
      delete[] m[i];
    }
    delete[] m;
  }
};

// Helper For Multiply Method
int getMatrixProductEntry(Matrix a, Matrix b, int row, int column)
{
  int acc = 0;

  for (int c = 0; c < a.columns; c++)
  {
    acc += a.get(row, c) * b.get(c, column);
  }

  return acc;
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
  if (a.columns != b.rows)
  {
    std::cout << "Matrix multiplication is not defined for these matrices";
    throw "Matrix multiplication is not defined for these matrices";
  }

  Matrix c(a.rows, b.columns);

  for (int row = 0; row < c.rows; row++)
  {
    for (int column = 0; column < c.columns; column++)
    {
      c.set(row, column, getMatrixProductEntry(a, b, row, column));
    }
  }

  return c;
}

Matrix operator%(const Matrix &a, const int n)
  {
    Matrix newmatrix(a.rows, a.columns);

    for (int row = 0; row < a.rows; row++)
    {
      for (int column = 0; column < a.columns; column++)
      {
        newmatrix.set(row, column, mod(a.get(row, column), n));
      }
    }

    return newmatrix;
  }

#endif