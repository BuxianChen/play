## Leetcode 刷题记录

[TOC]
- [Leetcode 刷题记录](#leetcode-刷题记录)
  - [no. Template](#no-template)
  - [2. Add Two Numbers](#2-add-two-numbers)
  - [92. Reverse Linked List II](#92-reverse-linked-list-ii)
  - [143. Reorder List](#143-reorder-list)
  - [223. Rectangle Area](#223-rectangle-area)
  - [274. H-Index](#274-h-index)
  - [328. Odd Even Linked List](#328-odd-even-linked-list)
  - [no. 725 Split Linked List in Parts](#no-725-split-linked-list-in-parts)

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

### 2. Add Two Numbers
题目来源：[leetcode](https://leetcode.com/problems/add-two-numbers/)

> 题目简述：用链表表示一个正整数，头节点为最低位，尾节点为最高位，计算两个正整数的和并以链表表示

解题思路：
- 将链表转为整数并求和
- 将整数转为链表

> 备注：本题应该可以直接计算，不用转成整数，本解法并不高效

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
def traverse_list(ls):
    # 把链表转为正整数
    ret = ls.val
    current = ls.next
    i = 1
    while current is not None:
        ret += current.val * 10 ** i
        current = current.next
        i += 1
    return ret


def construct_list(ls):
    # 给定正整数的各位数字列表，构造链表
    ret = ListNode(ls[0], None)
    for i in range(1, len(ls)):
        ret = ListNode(ls[i], ret)
    return ret


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 把链表转为正整数
        a = traverse_list(l1)
        b = traverse_list(l2)
        # 求和并将和转为字符串
        c = str(a + b)
        # 把字符串转为数字列表
        l3 = list(map(int, c))
        # 根据数字列表构造链表
        l3 = construct_list(l3)
        return l3
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

### 143. Reorder List
题目来源：[leetcode](https://leetcode.com/problems/reorder-list/)

> 题目简述：把链表 L_0 -> L_1 -> ... -> L_{n-1} -> L_n 重排为 L_0 -> L_n -> L1 -> L_{n-1} -> ...

解题思路：用列表（数组）存储链表节点，按下标重排

> 本解法需要额外空间存储链表以方便下标索引，不知道是否有更节省空间但不增加时间开销的做法。

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
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is not None:
            ls = []
            current = head
            # 把链表的节点存入一个列表
            while current is not None:
                ls.append(current)
                current = current.next
            size = len(ls)
            quotient, remainder = size // 2, size % 2
            # 当 i < (n+1)//2 - 1，L_i -> L_{n-i}, L_{n-i} -> L_{i+1}
            for i in range(quotient - 1):
                ls[i].next = ls[-1 - i]
                ls[-1 - i].next = ls[i + 1]
            # 若中间剩下 3 个节点 L_{i-1}, L_{i}, L_{i+1}，则 L_{i-1} -> L_{i+1} -> L_i -> None
            if remainder == 1 and (quotient > 0):
                ls[quotient - 1].next = ls[quotient + 1]
                ls[quotient + 1].next = ls[quotient]
            ls[quotient].next = None
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

### 274. H-Index
题目来源：[leetcode](https://leetcode.com/problems/h-index/)

> 题目简述：给定一名作者全部论文的引用数量列表，计算其 h-index，即有 n 篇文章的引用数量不少于 n，n 取最大。

解题思路：
- 统计所有可能的引用次数（升序排列） [h_1, ..., h_k] 及引用数不低于该次数的文章数量（降序排列） [c_1, ..., c_k]
- 若存在某个 i 使得 h_i <= c_i，且 h_{i+1} > c_{i+1}，则 c_i 为 h-index 的一个上界，最接近该上界的为 h_i 和 c_{i+1}，h-index 为其中的较大者，即 h-index = max(h_i, c_{i+1})。

> 备注：本题方法需要统计不同引用数出现的次数，比较耗时，尤其是当论文列表比较长时。

<details>
<summary>
成功代码：
</summary>

```python
import numpy as np


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # 统计所有可能的引用数及其出现的次数
        values, counts = np.unique(citations, return_counts=True)
        all_counts = sum(counts)
        min_val = min(values)
        # 边界条件：若文章少，但引用量多，出现最低引用量超过论文总量的情况，则 h-index 等于论文总数
        if min_val >= all_counts:
            return all_counts
        else:
            # 计算引用数不少于某个次数的论文总数
            cumsums = np.cumsum(counts[::-1])[::-1]
            h = 0
            for v, c in zip(values, cumsums):
                if c >= v:
                    h = v
                else:
                    h = max(c, h)
                    break
            return h
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

### no. 725 Split Linked List in Parts
题目来源：[leetcode](https://leetcode.com/problems/split-linked-list-in-parts/)

> 题目简述：将一个链表按顺序分成 k 个子链表，链表长度相差不超过 1，后一个链表的长度不大于前一个链表的长度，不足则用空链表补齐。

解题思路：
- 只需确定每个子链表的长度，最小长度为 len(ListNoe) // k，有 len(ListNode) % k 个链表的长度需要 +1

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


def length(head):
    # 计算链表长度
    size = 0
    while head is not None:
        head = head.next
        size += 1
    return size


def slice(head, k):
    # 给定链表，将其切分成两部分，第一部分长度为 k
    # 只包含两种情况，一种是链表为空，另一种链表长度不小于 k
    if head is None:
        return None, head
    else:
        ret = head
        for i in range(k):
            if i == (k - 1):
                tail = head.next
                head.next = None
                head = tail
            else:
                head = head.next
        return ret, head


class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        size = length(head)
        # 子链表的最小长度
        quotient = size // k
        # 长度需要 +1 的链表个数
        remainder = size % k
        ret = []
        for i in range(k):
            if remainder > 0:
                remainder -= 1
                piece, head = slice(head, quotient + 1)
                ret.append(piece)
            else:
                piece, head = slice(head, quotient)
                ret.append(piece)
        return ret
        
```
</details>