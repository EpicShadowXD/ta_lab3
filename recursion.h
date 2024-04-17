#pragma once

#include <stack>
#include <vector>

namespace Factorial {
    constexpr long long factorial(long long n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

    void test(int n = 5) {
        std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    }
}

namespace Fibonacci {
    long long fibonacci(long long n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    void test(int n = 10) {
        std::cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << std::endl;
    }
}

namespace Ackermann {
    namespace Simple {
        int ackermann(int m, int n) {
            if (m == 0) return n + 1;
            if (m > 0 && n == 0) return ackermann(m - 1, 1);
            return ackermann(m - 1, ackermann(m, n - 1));
        }

        void test(int n = 3, int m = 2) {
            printf("Ackermann(%d, %d) = %d", n, m, ackermann(n, m));
        }
    }

    namespace Iterative {
        int ackermann(int m, int n) {
            std::stack<std::pair<int, int>> stack;
            stack.push({m, n});
            int result = 0;

            while (!stack.empty()) {
                auto [m, n] = stack.top(); stack.pop();

                if (m == 0) {
                    result = n + 1;
                } else if (n == 0) {
                    if (m > 0) stack.push({m - 1, 1});
                } else {
                    stack.push({m - 1, result});
                    stack.push({m, n - 1});
                    continue;
                }

                if (stack.empty()) break;
                stack.top().second = result;
            }

            return result;
        }

        void test(int n = 3, int m = 2) {
            printf("Ackermann(%d, %d) = %d", n, m, ackermann(n, m));
        }
    }
}

namespace Maze {
    bool solveMazeUtil(std::vector<std::vector<int>>& maze, int x, int y, std::vector<std::vector<int>>& sol) {
        if (x == maze.size() - 1 && y == maze[0].size() - 1 && maze[x][y] == 1) {
            sol[x][y] = 1;
            return true;
        }

        if (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 1) {
            sol[x][y] = 1; // Assume step is part of solution path.
            if (solveMazeUtil(maze, x + 1, y, sol)) return true;
            if (solveMazeUtil(maze, x, y + 1, sol)) return true;
            sol[x][y] = 0; // Backtrack
        }
        return false;
    }

    bool solveMaze(std::vector<std::vector<int>>& maze) {
        std::vector<std::vector<int>> sol(maze.size(), std::vector<int>(maze[0].size(), 0));
        if (!solveMazeUtil(maze, 0, 0, sol)) return false;

        for (auto& row : sol) {
            for (int val : row) std::cout << val << " ";
            std::cout << "\n";
        }
        return true;
    }

    void test(std::vector<std::vector<int>> maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}
        }) {
        if (!solveMaze(maze)) std::cout << "No solution!\n";
    }
}

namespace Partitions {
    int countPartitions(int n, int k) {
        if (n == 0) return 1;
        if (k == 0 || n < 0) return 0;
        return countPartitions(n - k, k) + countPartitions(n, k - 1);
    }
    void test(int n = 4) {
        std::cout << "Number of ways to partition " << n << " is " << countPartitions(n, n) << std::endl;
    }
}

namespace Point {
    void moveRight(int x, int y);

    void moveUp(int x, int y) {
        if (y < 10) {
            std::cout << "Moving to (" << x << ", " << y + 1 << ")\n";
            moveRight(x, y + 1);
        }
    }

    void moveRight(int x, int y) {
        if (x < 10) {
            std::cout << "Moving to (" << x + 1 << ", " << y << ")\n";
            moveUp(x + 1, y);
        }
    }

    void test(int x = 0, int y = 0) {
        moveRight(x, y);
    }
}