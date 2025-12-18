#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int x, y;
    cin >> x >> y;
    
    // 8个方向的移动
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    set<pair<int, int>> visited;
    queue<vector<int>> q; // {x, y, steps}
    
    q.push({x, y, 0});
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int curr_x = curr[0], curr_y = curr[1], steps = curr[2];
        
        // 如果已访问过，跳过
        if (visited.count({curr_x, curr_y})) {
            continue;
        }
        
        // 标记为已访问
        visited.insert({curr_x, curr_y});
        
        // 如果还没达到步数限制，继续扩展
        if (steps < k) {
            for (int i = 0; i < 8; i++) {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];
                
                // 检查边界和是否已访问
                if (new_x >= 1 && new_x <= n && 
                    new_y >= 1 && new_y <= n && 
                    !visited.count({new_x, new_y})) {
                    q.push({new_x, new_y, steps + 1});
                }
            }
        }
    }
    
    cout << visited.size() << endl;
    
    return 0;
}



