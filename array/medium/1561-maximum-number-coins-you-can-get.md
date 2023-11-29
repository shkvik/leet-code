# 1561. Maximum Number of Coins You Can Get

**ENG:** There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:
In each step, you will choose any 3 piles of coins(not necessarily consecutive). Of your choice, Alice will pick the pile with the maximum number of coins. You will pick the next pile with the maximum number of coins. Your friend Bob will pick the last pile. Repeat until there are no more piles of coins. Given an array of integers piles where piles[i] is the number of coins in the ith pile. Return the maximum number of coins that you can have.

**RU:** Есть 3n стопок монет разного размера, вы и ваши друзья будете собирать стопки монет следующим образом:
На каждом шаге вы будете выбирать любые 3 стопки монет (не обязательно последовательные). По вашему выбору Алиса выберет стопку с максимальным количеством монет. Вы выберете следующую стопку с максимальным количеством монет. Ваш друг Боб выберет последнюю стопку. Повторяйте, пока стопок монет больше не останется. Задан массив целых чисел, где стопки[i] - количество монет в i-й стопке. Верните максимальное количество монет, которое у вас может быть.

### Example 1
```
Input: piles = [2, 4, 1, 2, 7, 8]
Output : 9
```
**Explanation:** Choose the triplet(2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one. Choose the triplet(1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one. The maximum number of coins which you can have are : 7 + 2 = 9. On the other hand if we choose this arrangement(1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.

### Example 2 
``` 
Input : piles = [2, 4, 5]
Output : 4
```

### Example 3 
``` 
Input : piles = [9, 8, 7, 6, 5, 1, 2, 3, 4]
Output : 18
```

```cpp
class Solution {
public:
    static int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0, n = piles.size();
        for (int i = n / 3; i < n; i += 2) {
            ans += piles.at(i);
        }
        return ans;
    }
};
```
