// Developer: Wilbert (wilbert.phen@gmail.com)

#pragma once
#include <iostream>
#include "_matrix.hpp"

class Tiler {

public:

    Tiler(const Matrix &mat1, const Matrix &mat2, size_t tsize);

    ~Tiler() = default; // default destructor

    Matrix load1(Matrix const & mat1, size_t it1, size_t jt1, size_t NDIM_row, size_t NDIM_mid);
    Matrix load2(Matrix const & mat2, size_t it2, size_t jt2, size_t NDIM_col, size_t NDIM_mid);
    void multiply(Matrix &m_ret, size_t it, size_t jt, size_t kt);

    size_t nrow() const { return m_nrow; }
    size_t nmid() const { return m_nmid; }
    size_t ncol() const { return m_ncol; }

    Matrix& mat1(size_t it, size_t jt) { return m_mat1[it][jt]; }
    Matrix& mat2(size_t it, size_t jt) { return m_mat2[it][jt]; }

private:

    size_t m_nrow;
    size_t m_ncol;
    size_t m_nmid;

    std::vector<std::vector<Matrix>> m_mat1; // row-major
    std::vector<std::vector<Matrix>> m_mat2; // column-major
};

