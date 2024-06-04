# 94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

### Example 1
![inorder_1](https://github.com/shkvik/leet-code/assets/75574213/83f6e7c9-87f4-49f6-bdf3-257559b9f3cb)
```
Input: root = [1,null,2,3]
Output: [1,3,2]
```
### Example 2
```
Input: root = []
Output: []
```
### Example 3
```
Input: root = [1]
Output: [1]
```

### Constraints
```
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
```

### Step 1: Approach
**Прямой обход**\
При прямом обходе будут посещаться все узлы в порядке возрастания, начиная с указанного узла (хотя это и необязательно), и выполнять заданную функцию обратного вызова callback (также необязательно). Опять же, мы будем использовать рекурсию:
![qn6dtt7tccizpg76swp8](https://github.com/shkvik/leet-code/assets/75574213/0b28f7c8-4970-4cdb-8850-e6078bb31ef7)
### Step 2: Solution
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

function inorderTraversal(root: TreeNode | null): number[] {
  if(!root) return [];
  return [
    ...inorderTraversal(root.left),
    root.val,
    ...inorderTraversal(root.right),
  ];
};
```
### Complexity
**Временная сложность**
Поскольку каждый узел посещается ровно один раз и выполняется фиксированное количество операций (рекурсивный вызов для левого поддерева, выполнение коллбэка, рекурсивный вызов для правого поддерева), временная сложность будет линейной относительно количества узлов в дереве.
В худшем случае: O(n), где n — количество узлов в дереве.
**Пространственная сложность**
Пространственная сложность алгоритма зависит от глубины рекурсии, которая определяется высотой дерева.
1. В лучшем случае (сбалансированное дерево): Высота дерева h≈log(n), где n — количество узлов в дереве. Пространственная сложность: O(log(n)) из-за глубины рекурсии.
2. В худшем случае (несбалансированное дерево, например, одностороннее дерево): Высота дерева h≈n. Пространственная сложность: O(n) из-за глубины рекурсии.

Таким образом, алгоритм inOrderTraverse является эффективным для симметричного обхода бинарного дерева, обеспечивая линейную временную сложность и логарифмическую пространственную сложность для сбалансированных деревьев.
![image](https://github.com/shkvik/leet-code/assets/75574213/0da409a5-123b-4c8d-830e-bf03aef39e44)
