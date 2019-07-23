### 描述
在一个字符串重寻找没有重复字母的最长子串。

### 示例
````
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
````
### 思路
设置起始（start,end）位置，end右移
判断是否重复，不重复继续右移
重复则重置当前最长字母数，并将start设置为重复位置
