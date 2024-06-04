# 3Sum Closest
Учитывая целочисленный массив numsдлины nи целое число target, найдите три целых числа nums, сумма которых наиболее близка к target.
Возвращает сумму трех целых чисел .
Вы можете предположить, что каждый вход будет иметь ровно одно решение.

### Example 1
```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
```
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
### Example 2
```
Input: nums = [0,0,0], target = 1
Output: 0
```
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
### Example 3
```
Input: nums = [4,0,5,-5,3,3,0,-4,-5], target = -2
Output: -2
```
### Example 4
```
Input: nums = [1,1,1,0], target = -100
Output: 2
```
## Solution
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int limit = nums.size() - 1;
        int ans = 1e6;
        for (int i = 0; i < nums.size() - 2; i++) {
            int right = limit;
            int left = i+1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum;
                else if (sum > target) right--;
                else left++;  
                if (abs(sum - target) < abs(ans - target)) ans = sum;
            }
        }
        return ans;
    }
};
```
### Complexity
1. Сортировка массива: sort(nums.begin(), nums.end()); - Обычно сортировка массива методом быстрой сортировки (std::sort) имеет временную сложность O(n log n), где n - размер массива nums.
2. Цикл по массиву: for (int i = 0; i < nums.size() - 2; i++) - Этот цикл выполняется от 0 до nums.size() - 3. Он приводит к временной сложности O(n), где n - размер массива nums.
3. Двоичный поиск внутри вложенного цикла: while (left < right) - Вложенный цикл, в худшем случае, выполняется для каждой итерации основного цикла. В худшем случае (когда требуется полный проход по массиву), временная сложность этого участка кода может быть O(n). В среднем, она будет O(n log n), так как это двоичный поиск.

### Anaylis
Таким образом, общая временная сложность кода составляет O(n log n) за счет сортировки, и O(n^2) из-за вложенных циклов. В пространственном отношении код требует O(1) дополнительной памяти, так как используются только константные переменные, не зависящие от размера входных данных.

