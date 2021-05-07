## Leetcode 刷题记录

[TOC]

### no. Template
题目来源：[leetcode]()

> 题目简述：题目内容

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

> 题目简述：给定起始位置 left 和结束位置 right，将邻接链表中间的连续片段逆序。

解题思路：除了待逆序的中间片段外，片段左右两边的邻接节点也可能受影响，按片段头尾节点是否为原链表头尾节点，一共分 4 种情况讨论

- 若 left 非起始节点，right 非终止节点，则将 [left, right] 逆序，将 left-1 指向 right，将 left 指向 right+1
- 若 left 非起始节点，right 为终止节点，则将 [left, right] 逆序，将 left-1 指向 right，将 left 指向 None，成为新的终止节点
- 若 left 为起始节点，right 非终止节点，则将 [left, right] 逆序，将 left 指向 right+1
- 若 left 为起始节点，right 为终止节点，则将 [left, right] 逆序，将 left 指向 None，成为新的终止节点

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
        # 遍历列表，保存位置在 [left-1, right+1] 之间的节点
        while current is not None:
            if count >= (left - 1):
                if count <= (right + 1):
                    ls.append(current)
                else:
                    break
            current = current.next
            count += 1
        # 待逆序的链表片段长度
        delta = right - left + 1
        # 实际保存的片段长度
        size = len(ls)
        if left > 0:
            # 若 left 非起始节点，right 非终止节点，则将 [left, right] 逆序，将 left-1 指向 right，将 left 指向 right+1
            if size == (delta + 2):
                reverse_list(ls[1:-1])
                ls[0].next = ls[-2]
                ls[1].next = ls[-1]
            # 若 left 非起始节点，right 为终止节点，则将 [left, right] 逆序，将 left-1 指向 right，将 left 指向 None，成为新的终止节点
            else:
                reverse_list(ls[1:])
                ls[0].next = ls[-1]
                ls[1].next = None
            return head
        # 若 left 为起始节点，right 非终止节点，则将 [left, right] 逆序，将 left 指向 right+1
        elif size == (delta + 1):
            reverse_list(ls[:-1])
            ls[0].next = ls[-1]
            return ls[-2]
        # 若 left 为起始节点，right 为终止节点，则将 [left, right] 逆序，将 left 指向 None，成为新的终止节点
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

### 328. Odd Even Linked List
题目来源：[leetcode](https://leetcode.com/problems/odd-even-linked-list/)

> 题目简述：将链表的偶数节点、奇数节点各自连成子链表，最后将奇数节点构成的链表拼接上偶数节点构成的链表（假设下标从 1 开始）。

解题思路：

- 注意空链表
- 分别记录奇数、偶数节点构成的子链表，最后奇数链表的尾节点指向偶数链表的头节点

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
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        # 判断链表是否非空
        if head is not None:
            # 假设下标从零开始，先偶数后奇数
            even_current = head
            odd_current = even_current.next
            odd_init = odd_current
            current = odd_current
            # flag=0 表示当前为偶数下标，flag=1 表示奇数下标
            flag = 1
            while current is not None:
                current = current.next
                flag = 1 - flag
                if flag == 0:
                    even_current.next = current
                    # 最后一个偶数节点的下一个节点非空
                    if current is not None:
                        even_current = current
                else:
                    odd_current.next = current
                    odd_current = current
            # 最后一个偶数节点的下一个节点为第一个奇数节点
            even_current.next = odd_init
        return head
```
</details>