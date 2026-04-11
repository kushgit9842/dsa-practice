// ─────────────────────────────────────────
// Problem : Rotting Oranges
// Difficulty: Medium
// Topic    : Array
// Tags     : Array, Breadth-First Search, Matrix
// Date     : 2026-04-11
// ─────────────────────────────────────────
                \n                for(auto &dir : directions) {\n                    int new_i = i + dir[0];\n                    int new_j = j + dir[1];\n                    \n                    if(isSafe(new_i, new_j)) {\n                        grid[new_i][new_j] = 2;\n                        que.push({new_i, new_j});\n                        freshCount--;\n                    }\n                }\n            }\n            time++;\n        }\n        \n        return (freshCount==0) ? time-1 : -1;\n    }\n};\n[[2,1,1],[1,1,0],[0,1,1]]\n[[2,1,1],[0,1,1],[1,0,1]]\n[[0,2]]\n4\n-1\n0\n4\n-1\n0\n