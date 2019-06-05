//
// Created by utec on 05/06/19.
//

#ifndef CLASE0506_ARITHPROGRESSION_H
#define CLASE0506_ARITHPROGRESSION_H

#include "GeoProgression.h"


class ArithProgression_iterator{
    long curr;
    long step;
    friend class ArithProgression;
    ArithProgression_iterator(long curr,long step):curr{curr},step{step}{}
public:
    bool operator==(const ArithProgression_iterator& other) const;
    bool operator!=(const ArithProgression_iterator& other) const;
    long& operator*();
    ArithProgression_iterator& operator++();
    ArithProgression_iterator& operator++(int);
};

class ArithProgression {
    long inicio;
    long final;
    long prog;

public:
    ArithProgression(int start, int stop, int step):inicio{start},final{stop}, prog{step} {}
    using iterator = ArithProgression_iterator;
    iterator begin() const
    {
        return ArithProgression::iterator(inicio,prog);
    }
    iterator end() const
    {
        return ArithProgression::iterator(final,prog);
    }
};

bool ArithProgression_iterator::operator==(const ArithProgression_iterator &other) const {
    return curr == other.curr;
}

bool ArithProgression_iterator::operator!=(const ArithProgression_iterator &other) const {
    return curr < other.curr;
}

long &ArithProgression_iterator::operator*() {
    return curr;
}

ArithProgression_iterator &ArithProgression_iterator::operator++() {
    curr = curr + step;
    return *this;
}

ArithProgression_iterator &ArithProgression_iterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}


#endif //CLASE0506_ARITHPROGRESSION_H
