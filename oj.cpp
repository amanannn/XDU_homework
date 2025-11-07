#include <stdio.h>
#include <stdbool.h>

// 方向枚举：右上或左下
typedef enum {
    DIR_UP_RIGHT,    // 右上方向 ↗
    DIR_DOWN_LEFT    // 左下方向 ↙
} Direction;

// 位置结构体
typedef struct {
    int row;
    int col;
} Position;

// 获取 Z 字形扫描的下一个位置
// 返回 false 表示扫描结束（到达右下角）
bool zigzagNextStep(int n, Position *current, Direction *dir) {
    // 检查是否到达矩阵右下角（扫描结束）
    if (current->row == n - 1 && current->col == n - 1) {
        return false;
    }
    
    if (*dir == DIR_UP_RIGHT) {
        // 右上方向移动 ↗
        if (current->col == n - 1) {
            // 碰到右边界，向下移动，改为左下方向
            current->row++;
            *dir = DIR_DOWN_LEFT;
        } else if (current->row == 0) {
            // 碰到上边界，向右移动，改为左下方向
            current->col++;
            *dir = DIR_DOWN_LEFT;
        } else {
            // 正常右上移动
            current->row--;
            current->col++;
        }
    } else {
        // 左下方向移动 ↙
        if (current->row == n - 1) {
            // 碰到下边界，向右移动，改为右上方向
            current->col++;
            *dir = DIR_UP_RIGHT;
        } else if (current->col == 0) {
            // 碰到左边界，向下移动，改为右上方向
            current->row++;
            *dir = DIR_UP_RIGHT;
        } else {
            // 正常左下移动
            current->row++;
            current->col--;
        }
    }
    
    return true;
}

// 修正：使用指针传递二维数组
void zigzagScan(int n, int *matrix) {
    Position pos = {0, 0};  // 起始位置 (0,0)
    Direction dir = DIR_UP_RIGHT;  // 初始方向
    
    // 输出第一个元素（通过指针访问）
    printf("%d", *((matrix + pos.row * n) + pos.col));
    
    // 循环获取下一个位置直到结束
    while (zigzagNextStep(n, &pos, &dir)) {
        printf(" %d", *((matrix + pos.row * n) + pos.col));
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // 修正：传递矩阵的首地址
    zigzagScan(n, (int *)matrix);
    
    return 0;
}