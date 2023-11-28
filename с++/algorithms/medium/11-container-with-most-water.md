# 11. Container With Most Water
## Description
**ENG:** You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store. Notice that you may not slant the container.

**RU:** Вам дан целочисленный массив height длины n. Есть n вертикальные линии, нарисованные так, что двумя конечными точками линии являются (i, 0) и (i, height[i]). Найдите две линии, которые вместе с осью X образуют контейнер, в котором содержится больше всего воды. Возвращайте максимальное количество воды, которое может храниться в контейнере. Обратите внимание , что вы не можете наклонять контейнер.

### Example 1
![question_11](https://github.com/shkvik/leet-code/assets/75574213/949569cd-add5-4227-af08-eee4bf0a3be1)
<br>**Input:** height = [1,8,6,2,5,4,8,3,7]
<br>**Output:** 49
<br>**Explanation:** The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

### Example 2
**Input:** height = [1,1]
<br>**Output:** 1
### Constraints:
* n == height.length
* 2 <= n <= 105
* 0 <= height[i] <= 104

## Solution
Первым делом нужно понять, что искать.  Дан массив с последовательными высотами, между которыми может содержаться вода. Каким образом они образуются и есть ли какие-либо правила? Высоты образуют края, между которыми находится жидкость, значит, что максимальная высота объёма жидкости будет равна минимальному краю. Длина этого контейнера будет разницей между началом левого края и концом правого. Длины могут проходить через высоты на пути от левого края к правому. Теперь нужно понять, как найти максимальный объём контейнера, который может существовать в этом диапазоне.

### Step 1: Approach
Для эффективного поиска будем использовать технику 2 указателей, чтобы добиться сложности $`O(n)`$.
![two_pointers_1](https://github.com/shkvik/leet-code/assets/75574213/64dda395-624b-44e8-b428-77603dde303b)

### Step 2: Idea
Идея будет в том, чтобы искать возможные площади между всеми возможными вариантами, но так, чтобы мы эффективно продвигались. Для этого нам нужно начать считать площадь от первого края к последнему, затем, сравнивать с предыдущей площадью. Затем, мы будем продвигать указатель с меньшим значением до тех пор, пока левый указатель меньше правого. Это даст нам возможность пройтись по всем элементам массива за один заход, посчитав площадь каждой емкости.

### Step 3: Relise
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) 
                left++; 
            else 
                right--;
        }
        return maxArea;
    }
};
```
