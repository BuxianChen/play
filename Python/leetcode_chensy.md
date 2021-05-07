## Leetcode 刷题记录

[TOC]

### no. Template
题目来源：[leetcode]()
题目简述：
> 题目内容

解题思路：
- 步骤一

<details>
<summary>
成功代码：
</summary>

```python
class Solution:
    def solve(self):
        return None
```
</details>

### 92. Reverse Linked List II
题目来源：[leetcode](https://leetcode.com/problems/reverse-linked-list-ii/)
题目简述：
> 给定起始位置和结束位置，将邻接链表中间的连续片段逆序。

解题思路：


<details>
<summary>
成功代码：
</summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def reverse_list(ls):
    # 将一个链表逆序
    for i in range(len(ls) - 1, 0, -1):
        ls[i].next = ls[i - 1]


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        count = 0
        ls = []
        current = head
        # 将 left 和 right 转化为从零开始的数字
        left -= 1
        right -= 1
        # 遍历列表，
        while current is not None:
            if count >= (left - 1):
                if count <= (right + 1):
                    ls.append(current)
                else:
                    break
            current = current.next
            count += 1
        delta = right - left + 1
        size = len(ls)
        if left > 0:
            if size == (delta + 2):
                reverse_list(ls[1:-1])
                ls[0].next = ls[-2]
                ls[1].next = ls[-1]
            else:
                reverse_list(ls[1:])
                ls[0].next = ls[-1]
                ls[1].next = None
            return head
        elif size == (delta + 1):
            reverse_list(ls[:-1])
            ls[0].next = ls[-1]
            return ls[-2]
        else:
            reverse_list(ls)
            ls[0].next = None
            return ls[-1]
```
</details>

### 223. Rectangle Area
题目来源：[leetcode](https://leetcode.com/problems/rectangle-area/)
> 题目简述：平面直角坐标系上的一个长方形由对角线上的两点坐标完全确定，给定两个长方形 `{(A, B), (C, D)}` 和 `{(E, F), (G, H)}`，求这两个长方形覆盖区域的总面积。

解题思路：
- 总面积等于两个长方形面积之和减去重叠部分的面积
- 长方形重叠转化为长和宽覆盖的区间是否都有重叠，即 `[A, C], [E, G]` 是否有交集，`[B, D], [F, H]` 是否有交集

<details>
<summary>
成功代码：
</summary>

```python
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        # 计算长和宽重叠区间的长度，长度小于等于零即为没有重叠
        width = max(min(C, G) - max(A, E), 0)
        height = max(min(D, H) - max(B, F), 0)
        return (D - B) * (C - A) + (H - F) * (G - E) - width * height
```
</details>