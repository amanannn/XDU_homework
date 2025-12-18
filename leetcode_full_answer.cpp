#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        if (len == 1) return words[0].length() + 1;
        
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        
        int result = 0;
        unordered_set<string> encoded;
        
        for (int i = 0; i < len; i++) {
            bool isSubstring = false;
            
            for (const string& encodedWord : encoded) {
                if (isSuffix(encodedWord, sortedWords[i])) {
                    isSubstring = true;
                    break;
                }
            }
            
            if (!isSubstring) {
                result += sortedWords[i].length() + 1;
                encoded.insert(sortedWords[i]);
            }
        }
        
        return result;
    }
    
private:
    bool isSuffix(const string& word1, const string& word2) {
        if (word2.length() > word1.length()) {
            return false;
        }
        return word1.substr(word1.length() - word2.length()) == word2;
    }
};