#ifndef IntervalH
#define IntervalH


class Interval {
public:
    Interval();
    Interval(double lo, double hi);
    double lo() const;
    double hi() const;
private:
    double the_lo;
    double the_hi;
};


#endif
