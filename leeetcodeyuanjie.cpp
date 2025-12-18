#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 计算单词数组的最小编码长度
     * 编码规则：使用'#'分隔符将所有单词连接，但要避免重复编码
     * 如果一个单词是另一个单词的后缀，则不需要单独编码
     */
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        // 如果只有一个单词，直接返回其长度+1（用于'#'分隔符）
        if (len == 1) return words[0].length() + 1;
        
        // 创建单词副本并按长度降序排序
        // 这样可以确保长单词优先处理，短单词（可能是后缀）后处理
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(), [](const string& a, const string& b) {
            return a.length() > b.length();  // 按长度降序排序
        });
        
        int result = 0;  // 存储最终编码长度
        unordered_set<string> encoded;  // 存储已编码的单词
        
        // 遍历排序后的单词
        for (int i = 0; i < len; i++) {
            bool isSubstring = false;  // 标记当前单词是否是其他单词的后缀
            
            // 检查当前单词是否是已编码单词的后缀
            for (const string& encodedWord : encoded) {
                if (isSuffix(encodedWord, sortedWords[i])) {
                    isSubstring = true;
                    break;  // 如果是后缀，无需再检查其他单词
                }
            }
            
            // 如果当前单词不是任何已编码单词的后缀，则需要单独编码
            if (!isSubstring) {
                result += sortedWords[i].length() + 1;  // 加1是为'#'分隔符
                encoded.insert(sortedWords[i]);  // 将当前单词加入已编码集合
            }
        }
        
        return result;
    }
    
private:
    /**
     * 检查word2是否是word1的后缀
     * @param word1 长单词
     * @param word2 短单词（可能的后缀）
     * @return 如果word2是word1的后缀返回true，否则返回false
     */
    bool isSuffix(const string& word1, const string& word2) {
        // 如果word2比word1长，则不可能是其后缀
        if (word2.length() > word1.length()) {
            return false;
        }
        // 取word1的后word2.length()个字符，与word2比较
        return word1.substr(word1.length() - word2.length()) == word2;
    }
};
