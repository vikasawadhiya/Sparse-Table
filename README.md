# Sparse Table

<p align="justify">Sparse Table is an auxiliary data structure. It requires O(1) constant time to answer range 
query on a sequence and without this auxiliary data structure naïve approach requires O(n) 
linear time to answer the range queries. Sparse table can be used with the sequence if eighter 
the sequence is constant or doesn’t modify after the sparse table creation.

Sparse table contains information about the ranges of lengths 2<sup>p</sup>. These ranges can be 
used to answer the range query of any arbitrary length in O(1) time. It contains information 
about all possible ranges of a particular length (2<sup>p</sup>) in a particular row and due to this, different 
rows contain information about the ranges of different length.

The sparse table requires O(n log n) construction time and O(n log n) space.
</p>

## Tutorial Document

<p align="justify">Tutorial document 
<a href="https://github.com/vikasawadhiya/Sparse-Table/blob/main/SparseTable.pdf">SparseTable.pdf</a>  
explains the sparse table in detail. Document first introduce the sparse table then explains how the sparse can be constructed in O(n log n) 
time complexity for a sequence of n elements and finally it discusses how it answers the range queries of any arbitrary length in O(1) 
constant time using available information about the ranges of lengths 2<sup>p</sup>.

Document uses a lot of pictorial represents which helps to explain the concept and also makes it easy to understand.
</p>

## Usage

<p align="justify">This implementation allows sparce table to be used for range minimum query. The sparce 
table can be constructed for any type of sequence. The only constrains is that the objects of specific type must be comparable by &lt; operator.
</p>

**Sparse Table Creation**

```cpp
const std::vector<int> sequence{1, 4, 2, 0, 9, 7, 8, 3, 5, 6};

SparseTable<int> table(sequence);
```
**Range Minimum Query**

```cpp
std::size_t minElementIndex = table.minQuery(1, 5);
```
It returns index of minimum element of the query range.

## Example

If the `sequence = [1, 4, 2, 0, 9, 7, 8, 3, 5, 6]`, then following is the sparse table,

![Alt text](https://github.com/vikasawadhiya/Sparse-Table/blob/main/SparseTableImage.png)

## License

The code is licensed under the <a href="https://github.com/vikasawadhiya/Sparse-Table/blob/main/LICENSE">MIT License</a>.<br/>
The tutorial document <a href="https://github.com/vikasawadhiya/Sparse-Table/blob/main/SparseTable.pdf">SparseTable.pdf</a> and 
<a href="https://github.com/vikasawadhiya/Sparse-Table/blob/main/SparseTableImage.png">SparseTableImage.png</a> are licensed under the 
<a href="https://creativecommons.org/licenses/by/4.0/">CC BY 4.0</a>