#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, w;
    if (!(std::cin >> n >> w)) {
        return 0;
    }

    constexpr int MAX_SCORE = 600;
    std::array<int, MAX_SCORE + 1> counts{};

    for (int i = 1; i <= n; ++i) {
        int score;
        std::cin >> score;
        ++counts[score];

        // 正整数除法向下取整；至少有 1 人获奖。
        const int target = std::max(1, i * w / 100);
        int accumulated = 0;

        for (int s = MAX_SCORE; s >= 0; --s) {
            accumulated += counts[s];
            if (accumulated >= target) {
                std::cout << s << (i == n ? '\n' : ' ');
                break;
            }
        }
    }

    return 0;
}
