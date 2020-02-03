#ifndef STUDENTC_H
#define STUDENTC_H

#include <string.h>
#include <valarray>
#invlude <iostream>


class Student : private std::string,private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        std:
        Student() {}
        virtual ~Student() {}

};

#endif // STUDENTC_H
