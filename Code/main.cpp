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

#include "sparsetable.hpp"

#include <iostream>
#include <vector>

using std::cout;

int main(){

    std::vector<std::size_t> elements{1, 4, 2, 0, 9, 7, 8, 3, 5, 6};

    SparseTable<std::size_t> table(elements);

    for(auto indexs : std::vector<std::pair<std::size_t, std::string::size_type>>{
    {0, 6}, {1, 5}, {0, 9}, {2, 5}, {2, 6}, {3, 4}, {4, 7}, {4, 9}, {8, 9}}){

        std::string::size_type minIndex = table.indexOfMinimumValue(indexs.first, indexs.second, elements);
        cout<< "min("<< indexs.first<< ", "<< indexs.second<< ") = "<< elements[minIndex]<< "("<< minIndex<< ")\n";
    }
}
