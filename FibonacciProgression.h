//
// Created by utec on 05/06/19.
//

#ifndef CLASE0506_FIBONACCIPROGRESSION_H
#define CLASE0506_FIBONACCIPROGRESSION_H

class FibonacciProgression_iterator{
    long curr;
    long anterior1;
    long anterior2;
    friend class FibonacciProgression;
    FibonacciProgression_iterator(long curr):curr{curr},anterior1{anterior1},anterior2{anterior2}{}
public:
    bool operator==(const FibonacciProgression_iterator& other) const;
    bool operator!=(const FibonacciProgression_iterator& other) const;
    long& operator*();
    FibonacciProgression_iterator& operator++();
    FibonacciProgression_iterator& operator++(int);
};

class FibonacciProgression{
    long inicio;
    long final;
    long fibo;
public:
    FibonacciProgression(long fibo):fibo{fibo}{}
    FibonacciProgression(long inicio,long final):inicio{inicio},final{final}{}
    using iterator = FibonacciProgression_iterator;
    iterator begin() const
    {
        return FibonacciProgression::iterator(inicio);
    }
    iterator end() const
    {
        return FibonacciProgression(final);
    }
};

bool FibonacciProgression_iterator::operator==(const FibonacciProgression_iterator &other) const {
    return curr == other.curr;
}

bool FibonacciProgression_iterator::operator!=(const FibonacciProgression_iterator &other) const {
    return curr < other.curr;
}

long &FibonacciProgression_iterator::operator*() {
    return curr;
}

FibonacciProgression_iterator &FibonacciProgression_iterator::operator++() {
    curr = curr*step;
    return *this;
}

FibonacciProgression_iterator &FibonacciProgression_iterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;}


#endif //CLASE0506_FIBONACCIPROGRESSION_H
