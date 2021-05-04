//Class inheritance methods
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//Exception class
class matrix_error : public logic_error
{
public:
    matrix_error(const char* mess) :logic_error(mess) {}
};

//Matrix class
class matrix
{

protected:

    double** m; //matrix
    size_t sz; //matrix size
public:

    //returns the number of rows in the matrix
    size_t matrix_size() const
    {
        return sz;
    }

    //overload [] for const
    const double* operator[](size_t i) const
    {
        if (i >= sz)throw out_of_range("The index of the matrix row was outside the bounds of the array");
        return m[i];
    }

    //overload []
    double* operator[](size_t i)
    {
        if (i >= sz)throw out_of_range("The index of the matrix row was outside the bounds of the array");
        return m[i];
    }

    //overload + matrix addition
    matrix operator+(const matrix& mx) const
    {
        if (sz != mx.sz)
            throw matrix_error("You can't add up the matrices. The matrices have different sizes.");
        matrix res(sz);
        for (size_t i = 0; i < sz; i++)
            for (size_t j = 0; j < sz; j++)
                res[i][j] = m[i][j] + mx.m[i][j];
        return res;
    }

    //overload - matrix subtraction
    matrix operator-(const matrix& mx) const
    {
        return *this + mx * (-1);
    }

    //overload * matrix multiplication
    matrix operator*(const matrix& mx) const
    {
        if (sz != mx.sz)
            throw matrix_error("You can't multiply matrices. The matrices have different sizes");
        matrix res(sz);
        for (size_t i = 0; i < sz; i++)
            for (size_t j = 0; j < sz; j++)
                for (size_t k = 0; k < sz; k++)
                    res[i][j] += m[i][k] * mx.m[k][j];
        return res;
    }

    //multiplying a matrix by a number
    matrix operator*(double val) const
    {
        matrix res(sz);
        for (size_t i = 0; i < sz; i++)
            for (size_t j = 0; j < sz; j++)
                res[i][j] = m[i][j] * val;
        return res;
    }

    //dividing a matrix by a number
    matrix operator/(double val) const
    {
        return *this * (1 / val);
    }

    //assignment
    void operator=(const matrix& mx)
    {
        if (sz != mx.sz) throw matrix_error("You can't assign a matrix. The matrices have different sizes");
        for (size_t i = 0; i < sz; i++)
            for (size_t j = 0; j < sz; j++)
                m[i][j] = mx.m[i][j];
    }

    //constructors
    matrix(size_t size) :m(new double* [size])
    {
        for (int i = 0; i < size; i++)
            m[i] = new double[size] {0};
        sz = size;
    }

    matrix(const initializer_list<double>& list, size_t size) :matrix(size)
    {
        if (list.size() != pow(size, 2)) throw out_of_range("A non-square matrix is given");
        for (size_t i = 0; i < list.size(); i++)
            m[i / size][i % size] = *(list.begin() + i);
    }

    matrix(const matrix& mx) :matrix(mx.sz)
    {
        *this = mx;
    }

    //destructor
    virtual ~matrix()
    {
        for (int i = 0; i < sz; i++)
            delete[] m[i];
        delete[] m;
        m = nullptr;
    }
};


//Class trigonometric matrix
class trig_matrix :public matrix
{

private:

    //calculates the factorial
    unsigned long long factorial(unsigned char n) const
    {
        return (n != 0) ? n * factorial(n - 1) : 1;
    }

    //raises the matrix to a degree
    trig_matrix mult(unsigned char deg) const
    {
        trig_matrix res(sz);
        if (deg == 0)
        {
            for (int i = 0; i < sz; i++)
                res[i][i] = 1;
        }
        else
        {
            res = *this;
            for (int i = 1; i < deg; i++)res = res * *this;
        }
        return res;
    }

public:

    //calculates the matrix cosine
    trig_matrix cos(unsigned char n) const
    {
        trig_matrix res(sz);
        for (unsigned char i = 0; i <= n; i++)
            res = res + mult(2 * n) * pow(-1, n) / factorial(2 * n);
        return res;
    }

    //assignment operations
    void operator=(const matrix& m)
    {
        matrix::operator=(m);
    }

    void operator=(const trig_matrix& m)
    {
        matrix::operator=(m);
    }

    //constructors
    trig_matrix(size_t size) :matrix(size)
    {
    }

    trig_matrix(const initializer_list<double>& list, size_t size) : matrix(list, size)
    {
    }
};

//enters the matrix into the stream and returns the stream itself
ostream& operator<<(ostream& ost, const matrix& mx)
{
    for (size_t i = 0; i < mx.matrix_size(); i++)
    {
        for (size_t j = 0; j < mx.matrix_size(); j++)
            ost << mx[i][j] << " ";
        ost << endl;
    }
    return ost;
}

//enters the matrix from the stream and returns the stream itself
istream& operator>>(istream& ist, matrix& mx)
{
    for (size_t i = 0; i < mx.matrix_size(); i++)
        for (size_t j = 0; j < mx.matrix_size(); j++)
            cin >> mx[i][j];
    return ist;
}


int main()
{

    //testing
    trig_matrix m(5), m1(5);
    for (size_t i = 0; i < m.matrix_size(); i++)
        for (size_t j = 0; j < m.matrix_size(); j++)
            m[i][j] = m1[i][j] = i + j;


    cout << "m1, m2" << endl << m << endl;
    cout << "+" << endl << m + m << endl;
    cout << "-" << endl << m + m << endl;
    cout << "m * m" << endl << m * m << endl;
    cout << "m * 3" << endl << m * 3 << endl;
    cout << fixed << setprecision(2) << "m / 3" << endl << m / 3 << endl;
    cout << "cos n = 2" << endl << m.cos(2) << endl;


    return 0;
}
