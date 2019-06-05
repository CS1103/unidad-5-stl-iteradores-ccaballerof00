//
// Created by utec on 05/06/19.
//

#ifndef CLASE0506_GEOPROGRESSION_H
#define CLASE0506_GEOPROGRESSION_H

class GeoProgression_iterator{
    long curr;
    long step;
    friend class GeoProgression;
    GeoProgression_iterator(long curr,long step):curr{curr},step{step}{}
public:
    bool operator==(const GeoProgression_iterator& other) const;
    bool operator!=(const GeoProgression_iterator& other) const;
    long& operator*();
    GeoProgression_iterator& operator++();
    GeoProgression_iterator& operator++(int);
};

class GeoProgression{
    long inicio;
    long final;
    long razon;
public:
    GeoProgression(long inicio,long final,long razon):inicio{inicio},final{final},razon{razon}{}
    using iterator = GeoProgression_iterator;
    iterator begin() const
    {
        return GeoProgression::iterator(inicio,razon);
    }
    iterator end() const
    {
        return GeoProgression::iterator(final,razon);
    }
};

bool GeoProgression_iterator::operator==(const GeoProgression_iterator &other) const {
    return curr == other.curr;
}

bool GeoProgression_iterator::operator!=(const GeoProgression_iterator &other) const {
    return curr < other.curr;
}

long &GeoProgression_iterator::operator*() {
    return curr;
}

GeoProgression_iterator &GeoProgression_iterator::operator++() {
    curr = curr*step;
    return *this;
}

GeoProgression_iterator &GeoProgression_iterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;}

#endif //CLASE0506_GEOPROGRESSION_H
