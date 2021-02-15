/*********************************************************************************
** MIT License
**
** Copyright (c) 2021 VIKAS AWADHIYA
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

template <typename T>
class SparseTable
{
public:
    SparseTable(const std::vector<T>& elements);

    std::size_t indexOfMinimumValue(std::size_t inclusiveFirstIndex, std::size_t inclusiveLastIndex,
                    const std::vector<T>& elements) const;

private:
    std::vector<std::vector<T>> table;
};

template <typename T>
SparseTable<T>::SparseTable(const std::vector<T>& elements): table(std::log2(elements.size())){

    table.front().reserve((elements.size() - 2) + 1);

    for(std::size_t index = 0, lastIndex = elements.size() - 2; index <= lastIndex; ++index){

        table.front().push_back((elements[index] < elements[index + 1]) ? index : index + 1);
    }

    std::size_t tableIndex = 1;

    for(std::size_t rangeLen = 4; rangeLen < elements.size(); rangeLen *= 2, ++tableIndex){

        std::size_t preTableIndex = tableIndex - 1;
        std::size_t preRangeLen = rangeLen / 2;

        table[tableIndex].reserve((elements.size() - rangeLen) + 1);

        for(std::size_t index = 0, lastIndex = elements.size() - rangeLen; index <= lastIndex; ++index){

            table[tableIndex].push_back(
                        (elements[table[preTableIndex][index]] < elements[table[preTableIndex][index + preRangeLen]])?
                        table[preTableIndex][index] : table[preTableIndex][index + preRangeLen]);
        }
    }
}

template <typename T>
std::size_t SparseTable<T>::indexOfMinimumValue(std::size_t inclusiveFirstIndex, std::size_t inclusiveLastIndex,
                                                const std::vector<T> &elements) const{

    if(inclusiveLastIndex == inclusiveFirstIndex){

        return inclusiveFirstIndex;
    }

    std::size_t numOfElements = (inclusiveLastIndex - inclusiveFirstIndex) + 1;

    std::size_t tableIndex = std::log2(numOfElements) - 1;
    std::size_t rangeLen = 1 << (tableIndex + 1);


    if(numOfElements == rangeLen){

        return table[tableIndex][inclusiveFirstIndex];
    }
    else{
        std::size_t inclusiveNextIndex = inclusiveFirstIndex + (numOfElements - rangeLen);

        if(elements[table[tableIndex][inclusiveFirstIndex]] < elements[table[tableIndex][inclusiveNextIndex]]){

            return table[tableIndex][inclusiveFirstIndex];
        }
        else{
            return table[tableIndex][inclusiveNextIndex];
        }
    }
}


#endif // SPARSETABLE_HPP
