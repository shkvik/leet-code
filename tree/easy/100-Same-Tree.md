# 11. Container With Most Water

**ENG:** Given the roots of two binary trees p and q, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**RU:** Учитывая корни двух двоичных деревьев p и q, напишите функцию, проверяющую, совпадают они или нет. Два двоичных дерева считаются одинаковыми, если они структурно идентичны и узлы имеют одинаковое значение.

### Example 1
![ex1](https://github.com/shkvik/leet-code/assets/75574213/ef9c89c7-c4e1-4670-83e0-cb5423f9c9ed)
```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```
### Example 2
![ex2](https://github.com/shkvik/leet-code/assets/75574213/fc853a56-dc91-4ff6-b69a-d1e82400e2b7)
```
Input: p = [1,2], q = [1,null,2]
Output: false
```
### Example 3
![ex2](https://github.com/shkvik/leet-code/assets/75574213/fc853a56-dc91-4ff6-b69a-d1e82400e2b7)
```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

### Constraints
```
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
```
## Solution 1
Примитивный подход 
### Step 1: Approach
**Симметричный обход**\
При симметричном обходе посещаются каждый узел до его потомков.\
![rrqqihedxk7svv3pntcj](https://github.com/shkvik/leet-code/assets/75574213/8a936b97-8bd7-4b58-93e5-75a536216bff)

Мы сделаем обход двух деревьев, затем превратим их значения в 2 строки и сравним.
```js
preOrderTraverse(node, callback) {
    if (node != null) {
        callback(node.data);
        this.preOrderTraverse(node.left, callback);
        this.preOrderTraverse(node.right, callback);
    }
}
```

### Step 2: Code
```ts
class TreeNode {
  public val: number
  public left: TreeNode | null
  public right: TreeNode | null

  constructor(val?: number, left?: TreeNode, right?: TreeNode) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}

function inorderTraversal(root: TreeNode | null): Array<number | null> {
  if(root === null){
    return [null];
  }
  return [
    root.val,
    ...inorderTraversal(root!.left),
    ...inorderTraversal(root!.right)
  ];
}

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
  const a = inorderTraversal(p)
    .map(n => n !== null ? n : 'n')
    .join('')
  const b = inorderTraversal(q)
    .map(n => n !== null ? n : 'n')
    .join('')
  return a === b;
};
```
### Complexity
1. Временная сложность: В худшем случае $O(n^2)$ в лучшем $O(n*log n)$
2. Пространственная сложность: $𝑂(𝑛^2)$

### Summary
Решение работает, но оно говно


## Solution 2
Рекурсивный пожход
### Step 1: Approach
Решаем применить рекурсию, думаем логически:
1. Начнем с проверки, являются ли оба дерева нулевыми. Если да, то они одинаковы, поэтому мы возвращаем true.
2. Если одно из деревьев имеет значение NULL, а другое — нет, они не могут быть одинаковыми, поэтому мы возвращаем false.
3. Если оба дерева не равны нулю, мы проверяем, равны ли их значения.
4. Затем мы рекурсивно вызываем функцию в их левом и правом поддеревьях и проверяем, совпадают ли они.
5. Мы объединяем результаты проверок значения текущего узла и его поддеревьев и возвращаем окончательный результат.

### Step 2: Code
```ts
class TreeNode {
  public val: number
  public left: TreeNode | null
  public right: TreeNode | null

  constructor(val?: number, left?: TreeNode, right?: TreeNode) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    if (p === null && q === null) return true;
    if (p === null || q === null) return false;
    if (p.val !== q.val) return false;
    return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
}
```

### Complexity
1. Временная сложность: $O(n)$ где n — количество узлов в меньшем дереве. Нам нужно пройти каждый узел один раз.
2. Пространственная сложность: $O(h)$ где h — высота дерева. Это пространство, необходимое для стека рекурсивных вызовов. В худшем случае высота дерева может составлять O(n) для перекошенного дерева, но в среднем она равна O(log n) для сбалансированного двоичного дерева.

![image](https://github.com/shkvik/leet-code/assets/75574213/0da409a5-123b-4c8d-830e-bf03aef39e44)
