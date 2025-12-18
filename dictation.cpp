#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 使用vector作为顺序表的基本容器
vector<int> seqList;

// 初始化顺序表
void initialize() {
    seqList.clear();
    cout << "顺序表初始化完成" << endl;
}

// 在末尾插入元素
void append(int element) {
    seqList.push_back(element);
    cout << "元素 " << element << " 已添加到末尾" << endl;
}

// 在指定位置插入元素
bool insert(int position, int element) {
    if (position < 0 || position > seqList.size()) {
        cout << "插入位置无效！" << endl;
        return false;
    }
    seqList.insert(seqList.begin() + position, element);
    cout << "元素 " << element << " 已插入到位置 " << position << endl;
    return true;
}

// 在开头插入元素
void prepend(int element) {
    seqList.insert(seqList.begin(), element);
    cout << "元素 " << element << " 已插入到开头" << endl;
}

// 删除末尾元素
bool removeLast() {
    if (seqList.empty()) {
        cout << "顺序表为空，无法删除！" << endl;
        return false;
    }
    int removed = seqList.back();
    seqList.pop_back();
    cout << "末尾元素 " << removed << " 已被删除" << endl;
    return true;
}

// 删除指定位置元素
bool removeAt(int position) {
    if (position < 0 || position >= seqList.size()) {
        cout << "删除位置无效！" << endl;
        return false;
    }
    int removed = seqList[position];
    seqList.erase(seqList.begin() + position);
    cout << "位置 " << position << " 的元素 " << removed << " 已被删除" << endl;
    return true;
}

// 删除指定值的元素（首次出现）
bool removeValue(int value) {
    auto it = find(seqList.begin(), seqList.end(), value);
    if (it != seqList.end()) {
        seqList.erase(it);
        cout << "元素 " << value << " 已被删除" << endl;
        return true;
    }
    cout << "元素 " << value << " 未找到" << endl;
    return false;
}

// 清空顺序表
void clearList() {
    seqList.clear();
    cout << "顺序表已清空" << endl;
}

// 查找元素位置（首次出现）
int findElement(int element) {
    auto it = find(seqList.begin(), seqList.end(), element);
    if (it != seqList.end()) {
        int position = distance(seqList.begin(), it);
        cout << "元素 " << element << " 位于位置 " << position << endl;
        return position;
    }
    cout << "元素 " << element << " 未找到" << endl;
    return -1;
}

// 判断元素是否存在
bool contains(int element) {
    bool found = find(seqList.begin(), seqList.end(), element) != seqList.end();
    cout << "元素 " << element << (found ? " 存在" : " 不存在") << endl;
    return found;
}

// 按索引访问元素
int getElement(int index) {
    if (index < 0 || index >= seqList.size()) {
        throw out_of_range("索引越界！");
    }
    return seqList[index];
}

// 修改指定位置的元素
bool update(int position, int newValue) {
    if (position < 0 || position >= seqList.size()) {
        cout << "修改位置无效！" << endl;
        return false;
    }
    int oldValue = seqList[position];
    seqList[position] = newValue;
    cout << "位置 " << position << " 的元素从 " << oldValue 
        << " 修改为 " << newValue << endl;
    return true;
}

// 显示顺序表所有元素
void display() {
    if (seqList.empty()) {
        cout << "顺序表为空" << endl;
        return;
    }
    
    cout << "顺序表元素 (" << seqList.size() << "个): ";
    for (size_t i = 0; i < seqList.size(); ++i) {
        cout << seqList[i];
        if (i < seqList.size() - 1) cout << " → ";
    }
    cout << endl;
}

// 使用迭代器遍历
void displayWithIterator() {
    if (seqList.empty()) {
        cout << "顺序表为空" << endl;
        return;
    }
    
    cout << "使用迭代器遍历: ";
    for (auto it = seqList.begin(); it != seqList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 使用范围for循环遍历
void displayWithForEach() {
    if (seqList.empty()) {
        cout << "顺序表为空" << endl;
        return;
    }
    
    cout << "使用范围for循环遍历: ";
    for (int elem : seqList) {
        cout << elem << " ";
    }
    cout << endl;
}

// 获取顺序表大小
size_t getSize() {
    return seqList.size();
}

// 判断顺序表是否为空
bool isEmpty() {
    return seqList.empty();
}

// 获取顺序表容量信息
void getCapacityInfo() {
    cout << "当前元素个数: " << seqList.size() << endl;
    cout << "当前容量: " << seqList.capacity() << endl;
}

// 排序顺序表
void sortList(bool ascending = true) {
    if (seqList.empty()) {
        cout << "顺序表为空，无需排序" << endl;
        return;
    }
    
    if (ascending) {
        sort(seqList.begin(), seqList.end());
        cout << "已按升序排序" << endl;
    } else {
        sort(seqList.begin(), seqList.end(), greater<int>());
        cout << "已按降序排序" << endl;
    }
}

// 反转顺序表
void reverseList() {
    reverse(seqList.begin(), seqList.end());
    cout << "顺序表已反转" << endl;
}

// 查找最大最小值
void findMinMax() {
    if (seqList.empty()) {
        cout << "顺序表为空" << endl;
        return;
    }
    
    auto minIt = min_element(seqList.begin(), seqList.end());
    auto maxIt = max_element(seqList.begin(), seqList.end());
    
    cout << "最小值: " << *minIt << " (位置: " 
        << distance(seqList.begin(), minIt) << ")" << endl;
    cout << "最大值: " << *maxIt << " (位置: " 
        << distance(seqList.begin(), maxIt) << ")" << endl;
}

// 统计元素出现次数
int countElement(int element) {
    int count = 0;
    for (int elem : seqList) {
        if (elem == element) count++;
    }
    cout << "元素 " << element << " 出现了 " << count << " 次" << endl;
    return count;
}

// 去重操作
void removeDuplicates() {
    vector<int> temp;
    for (int elem : seqList) {
        if (find(temp.begin(), temp.end(), elem) == temp.end()) {
            temp.push_back(elem);
        }
    }
    seqList = temp;
    cout << "重复元素已去除" << endl;
}

int main() {
    // 初始化测试
    initialize();
    
    // 添加元素测试
    append(10);
    append(20);
    append(30);
    prepend(5);
    insert(2, 15);
    
    // 显示测试
    display();
    displayWithIterator();
    displayWithForEach();
    
    // 查找测试
    findElement(15);
    contains(25);
    
    // 修改测试
    update(1, 25);
    display();
    
    // 删除测试
    removeAt(2);
    removeValue(25);
    display();
    
    // 排序和统计测试
    append(5);
    append(15);
    display();
    sortList(true);
    display();
    findMinMax();
    countElement(5);
    
    // 容量信息
    getCapacityInfo();
    
    // 去重测试
    removeDuplicates();
    display();
    
    // 清空测试
    clearList();
    display();
    
    return 0;
}