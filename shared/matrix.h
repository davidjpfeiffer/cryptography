#ifndef __MATRIX
#define __MATRIX

#include "vector"
#include "algorithm"

#include "./mathUtilities.cpp"

class Matrix
{
public:
  int rows = 0, columns = 0;

  Matrix(int rows_p, int columns_p)
  {
    rows = std::max(rows_p, 0);
    columns = std::max(columns_p, 0);
    size = rows * columns;
    allocateMatrix();
  }

  ~Matrix()
  {
    deallocateMatrix();
  }

  Matrix(std::vector<int> v, int rows_p = 3)
  {
    create(v, rows_p);
  }

  Matrix(const Matrix &other)
  {
    create(other.toVector(), other.rows);
  }

  int get(int row, int column) const
  {
    validateRowAndColumn(row, column);
    return m[row][column];
  }

  int set(int row, int column, int value)
  {
    validateRowAndColumn(row, column);
    m[row][column] = value;
  }

  std::vector<int> toVector() const
  {
    std::vector<int> v;

    for (int column = 0; column < columns; column++)
    {
      for (int row = 0; row < rows; row++)
      {
        int n = (column * rows) + row;
        if (n < size)
        {
          v.push_back(m[row][column]);
        }
      }
    }

    return v;
  }

  void print() const
  {
    for (int row = 0; row < rows; row++)
    {
      for (int column = 0; column < columns; column++)
      {
        std::cout << m[row][column] << ' ';
      }
      std::cout << '\n';
    }
  }

  Matrix &operator=(const Matrix &rhs)
  {
    create(rhs.toVector(), rhs.rows);
    return *this;
  }

  Matrix operator%(const int n)
  {
    Matrix result = Matrix(rows, columns);

    for (int row = 0; row < rows; row++)
    {
      for (int column = 0; column < columns; column++)
      {
        result.set(row, column, mod(get(row, column), n));
      }
    }

    return result;
  }

  Matrix operator*(const Matrix &rhs)
  {
    if (columns != rhs.rows)
    {
      std::cout << "Matrix multiplication is not defined for these matrices\n";
      throw;
    }

    Matrix c = Matrix(rows, rhs.columns);

    for (int row = 0; row < c.rows; row++)
    {
      for (int column = 0; column < c.columns; column++)
      {
        c.set(row, column, getMatrixProductEntry(*this, rhs, row, column));
      }
    }

    return c;
  }

private:
  int **m;
  int size = 0;

  void allocateMatrix()
  {
    m = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
      m[i] = new int[columns];
    }
  }

  void deallocateMatrix()
  {
    for (int i = 0; i < rows; ++i)
    {
      delete[] m[i];
    }
    delete[] m;
  }

  void create(std::vector<int> v, int rows_p = 3)
  {
    size = v.size();
    rows = std::max(rows_p, 1);
    columns = size % rows == 0 ? size / rows : (size / rows) + 1;
    allocateMatrix();

    for (int column = 0; column < columns; column++)
    {
      for (int row = 0; row < rows; row++)
      {
        int n = (column * rows) + row;
        if (n < size)
        {
          m[row][column] = v[n];
        }
      }
    }
  }

  void validateRowAndColumn(int row, int column) const
  {
    if (validRow(row) == false)
    {
      std::cout << "Invalid row\n";
      throw;
    }

    if (validColumn(column) == false)
    {
      std::cout << "Invalid column\n";
    }
  }

  bool validRow(int row) const
  {
    return row >= 0 && row < rows;
  }

  bool validColumn(int column) const
  {
    return column >= 0 && column < columns;
  }

  int getMatrixProductEntry(const Matrix &a, const Matrix &b, int row, int column)
  {
    int acc = 0;

    for (int c = 0; c < a.columns; c++)
    {
      acc += a.get(row, c) * b.get(c, column);
    }

    return acc;
  }
};

#endif