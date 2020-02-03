#ifndef STUDENTC_H
#define STUDENTC_H

#include <string.h>
#include <valarray>
#invlude <iostream>


class Student : private std::string,private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::ostream & arr_out(std::ostream & os) const;
    public:
        Student(): std::string("Null Student"), AarrayDb() {}
        virtual ~Student() {}

};

#endif // STUDENTC_H
