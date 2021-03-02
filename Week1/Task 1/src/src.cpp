#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix()
    {
        numrows = 0;
        numcols = 0;
    }
    Matrix(int num_rows, int num_cols)
    {
        Reset(num_rows, num_cols);
    }
    void Reset(int rows, int cols)
    {
        if (rows < 0 || cols < 0)
        {
            throw out_of_range("");
        }
        if (rows == 0 || cols == 0)
        {
            rows = cols = 0;
        }

        numrows = rows;
        numcols = cols;
        mat.assign(rows, vector<int>(cols));
    }
    int At(int row, int col) const
    {
        return mat.at(row).at(col);
    }
    int& At(int row, int col)
    {
        return mat.at(row).at(col);
    }
    int GetNumRows() const
    {
        return numrows;
    }
    int GetNumColumns() const
    {
        return numcols;
    }
private:
    vector<vector<int>> mat;
    int numrows;
    int numcols;
};

Matrix operator+(const Matrix& a, const Matrix& b)
{
    if (a.GetNumRows() != b.GetNumRows()
        || a.GetNumColumns() != b.GetNumColumns())
    {
        throw invalid_argument("");
    }

    Matrix c(a.GetNumRows(), a.GetNumColumns());
    for (int i = 0; i < c.GetNumRows(); i++)
    {
        for (int j = 0; j < c.GetNumColumns(); j++)
        {
            c.At(i, j) = a.At(i, j) + b.At(i, j);
        }
    }

    return c;
}

bool operator==(const Matrix& a, const Matrix& b)
{
    bool flag = false;
    if (a.GetNumRows() == b.GetNumRows()
        && a.GetNumColumns() == b.GetNumColumns())
    {
        flag = true;
        for (int i = 0; i < a.GetNumRows(); i++)
        {
            for (int j = 0; j < a.GetNumColumns(); j++)
            {
                if (a.At(i, j) != b.At(i, j))
                {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

istream& operator>>(istream& stream, Matrix& a)
{
    int rows, cols;
    stream >> rows >> cols;

    a.Reset(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            stream >> a.At(i, j);
        }
    }

    return stream;
}

ostream& operator<<(ostream& stream, const Matrix& a)
{
    stream << a.GetNumRows() << " " << a.GetNumColumns() << endl;
    for (int i = 0; i < a.GetNumRows(); i++)
    {
        for (int j = 0; j < a.GetNumColumns(); j++)
        {
            stream << a.At(i, j);
            if (j != a.GetNumColumns() - 1)
            {
                stream << " ";
            }
        }
        if (i != a.GetNumRows() - 1)
        {
            stream << endl;
        }
    }
return stream;
}

int main()
{
    try
    {
        Matrix one;
        Matrix two;

        cin >> one >> two;
        cout << one + two << endl;
        
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
    catch (invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}