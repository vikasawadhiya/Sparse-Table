/*********************************************************************************
** MIT License
**
** Copyright (c) 2025 Vikas Awadhiya
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:

** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.

** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*********************************************************************************/

#ifndef SPARSETABLE_HPP
#define SPARSETABLE_HPP

#include <cmath>
#include <vector>
#include <stdexcept>

template <typename T>
class SparseTable
{
    const std::vector<T>& sequence;
    std::vector< std::vector<size_t> > table;

public:
    explicit SparseTable(const std::vector<T>& elements);

    std::size_t minQuery(std::size_t rangeInclusiveLowerBound, std::size_t rangeInclusiveUpperBound) const;
};

template <typename T>
SparseTable<T>::SparseTable(const std::vector<T>& sequence):
    sequence(sequence),
    table(sequence.empty() ? 0 : static_cast<size_t>( std::log2(sequence.size() ) ) ){ //log2(0) is undfined.

    if (sequence.size() < 2) {

        return;
    }

    table.front().reserve(sequence.size() - 1);

    for(std::size_t index = 0, lastIndex = sequence.size() - 1; index < lastIndex; ++index){

        table.front().push_back( (sequence[index] < sequence[index + 1]) ? index : index + 1 );
    }

    std::size_t row = 1;

    for (std::size_t rangeLen = 4; rangeLen <= sequence.size(); rangeLen *= 2, ++row) {

        std::size_t preRow = row - 1;
        std::size_t preRangeLen = rangeLen / 2;

        table[row].reserve( (sequence.size() - rangeLen) + 1 );

        for (std::size_t index = 0, lastIndex = sequence.size() - rangeLen; index <= lastIndex; ++index) {

            if (sequence[ table[preRow][index] ] < sequence[ table[preRow][index + preRangeLen] ]) {

                table[row].push_back(table[preRow][index]);
            }
            else {
                table[row].push_back(table[preRow][index + preRangeLen]);
            }
        }
    }
}

template<typename T>
std::size_t SparseTable<T>::minQuery(std::size_t rangeInclusiveLowerBound, std::size_t rangeInclusiveUpperBound) const{
    
    if ( rangeInclusiveLowerBound > rangeInclusiveUpperBound || rangeInclusiveUpperBound >= sequence.size() ) {


        throw std::invalid_argument("Invalid range!");
    }

    if (rangeInclusiveUpperBound == rangeInclusiveLowerBound) {

        return rangeInclusiveLowerBound;
    }

    std::size_t numOfElements = (rangeInclusiveUpperBound - rangeInclusiveLowerBound) + 1;

    std::size_t row = static_cast<size_t>( std::log2(numOfElements) ) - 1;  //Explicit use of std::floor() function is
                                                                            //not required.
    std::size_t rangeLen = 1;
    rangeLen = rangeLen << (row + 1);

    if (numOfElements == rangeLen) {

        return table[row][rangeInclusiveLowerBound];
    }
    
    std::size_t otherSubRangeInclusiveLowerBound = rangeInclusiveLowerBound + (numOfElements - rangeLen);

    if (sequence[ table[row][rangeInclusiveLowerBound] ] < sequence[ table[row][otherSubRangeInclusiveLowerBound] ]) {

        return table[row][rangeInclusiveLowerBound];
    }
    
    return table[row][otherSubRangeInclusiveLowerBound];
}


#endif // SPARSETABLE_HPP
