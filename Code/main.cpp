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

#include "sparsetable.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

    // A Sequence doesn't have to be constant, but 
    // a non-constant sequence must not be modified after the sparse table creation.

    const vector<int> sequence{1, 4, 2, 0, 9, 7, 8, 3, 5, 6}; 

    SparseTable<int> table(sequence);

    vector< pair<size_t, size_t> > queryRanges{ {0, 6}, {1, 5}, {0, 9}, {2, 5}, {2, 6}, {3, 4}, {4, 7}, {4, 9}, {8, 9} };
    
    for (auto& range : queryRanges) {

        size_t minElementIndex = table.minQuery(range.first, range.second);

        cout << "range[" << range.first << ", " << range.second << "] min value = " << sequence[minElementIndex] << '\n';
    }
}
