# 4. Median of Two Sorted Arrays

**ENG:** Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log(m + n)).
 
 **RU:** Учитывая два отсортированных массива nums1 и nums2 размером m и n соответственно, верните медиану двух отсортированных массивов.
Общая сложность времени выполнения должна быть $`O(log(m + n))`$.
 
### Example 1:
```
Input: nums1 = [1, 3], nums2 = [2]
Output : 2.00000
Explanation : merged array = [1, 2, 3] and median is 2.
``` 
### Example 2 :
```
Input : nums1 = [1, 2], nums2 = [3, 4]
Output : 2.50000
Explanation : merged array = [1, 2, 3, 4] and median is(2 + 3) / 2 = 2.5.
```
## Solution 1
Первым делом вспомним, что такое медиана массива. Медиана массива - это значение, которое разделяет упорядоченный массив на две равные половины. Другими словами, это элемент, который стоит посередине массива, когда все элементы упорядочены по возрастанию или убыванию. Если в массиве четное количество элементов, то медианой является среднее арифметическое двух средних элементов.

Для нахождения медианы массива сначала нужно упорядочить элементы. Затем, если количество элементов нечетное, медиана - это элемент, стоящий точно посередине. Если количество элементов четное, медиана - это среднее арифметическое двух средних элементов.

Например, в массиве [1, 3, 5, 7, 9] медианой будет 5, потому что он стоит посередине после упорядочивания. В массиве [1, 2, 3, 4] медианой будет (2 + 3) / 2 = 2.5, так как это среднее арифметическое двух средних элементов.

### Step 1: Approach
Самое простое решение - это объеденить массивы в новый заранее аллоцированный массив, отсортировать его и там уже искать. Потом определить четность, и возвращать значение с плавующей точкой, если медиана ищется в массиве с четным количеством элементов

### Step 2: Relise
```cpp
class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto merged = vector<int>(nums1.size() + nums2.size());
      
        std::copy(nums1.begin(), nums1.end(), merged.begin());
        std::copy(nums2.begin(), nums2.end(), merged.begin() + nums1.size());
        std::sort(merged.begin(), merged.end());
      
        auto size = merged.size();
        return size % 2 == 0 ?
            static_cast<float>(
                merged.at((size / 2) - 1) + merged.at(size / 2)
                    ) / 2.0f : merged.at(size / 2);
    }
};
```
