#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 计算单词数组的最小编码长度
     * 
     * 编码规则：使用'#'字符将单词连接成一个字符串，使得每个单词都可以通过
     * 从特定索引开始到下一个'#'字符结束的方式被提取出来
     * 
     * 优化策略：如果一个单词是另一个单词的后缀，则不需要单独编码
     * 例如：如果同时有"me"和"time"，由于"me"是"time"的后缀，
     * 那么编码"time#"就足够了，因为"me"可以通过从索引2开始提取得到
     * 
     * @param words 输入的单词数组
     * @return 最小助记字符串的长度
     */
    int minimumLengthEncoding(vector<string>& words) {
        // 使用集合存储所有单词，便于后续删除操作
        // 集合会自动去重，处理重复单词的情况
        unordered_set<string> wordSet(words.begin(), words.end());
        
        // 遍历每个单词，检查其后缀是否存在于集合中
        for (const string& word : words) {
            // 检查当前单词的所有后缀（从位置1开始，避免重复处理单词本身）
            // 例如对于单词"time"，检查后缀"ime", "me", "e"
            for (int i = 1; i < word.length(); i++) {
                string suffix = word.substr(i);  // 获取从位置i开始的后缀
                wordSet.erase(suffix);  // 如果后缀存在于集合中，则删除
                // 删除后缀的原因：如果suffix是word的后缀，
                // 那么在编码word时，suffix已经包含在其中了
                // 所以suffix不需要单独编码
            }
        }
        
        // 计算结果：每个剩余单词长度+1（用于'#'字符）
        // 剩余的单词都是不能被其他单词包含的，需要单独编码
        int result = 0;
        for (const string& word : wordSet) {
            result += word.length() + 1;  // 单词长度 + 1个'#'字符
        }
        
        return result;
    }
};