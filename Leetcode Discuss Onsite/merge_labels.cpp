#include <tuple>
#include <vector>
#include <set>
#include <iostream>

std::string to_string(int start, int end, const std::set<char> &comments) {
    std::string str = "(" + std::to_string(start) + ", " + std::to_string(end) + "): [";

    std::for_each(comments.begin(), comments.end(), [&](const char &comment) {
        str += comment;
        str += ", ";
    });

    str.pop_back();
    str.pop_back();

    str += "]";

    return str;
}

std::vector<std::string> solve(const std::vector<std::tuple<int, int, char>> &input) {
    std::vector<std::tuple<int, int, char, int>> intervals;

    for (const auto &in: input) {
        const auto&[start, end, text] = in;

        intervals.emplace_back(start, end, text, 0);
        intervals.emplace_back(end, start, text, 1);
    }

    sort(intervals.begin(), intervals.end(), [](const auto &tup1, const auto &tup2) {
        const auto&[s1, e1, _t1, o1] = tup1;
        const auto&[s2, e2, _t2, o2] = tup2;

        return std::tie(s1, o1, e1) < std::tie(s2, o2, e2);
    });

    std::vector<std::string> merged;
    std::set<char> comments;
    int current = -1;

    for (const auto &interval: intervals) {
        const auto&[start, _end, text, is_end] = interval;

        if (is_end) {
            if (current != -1 && start >= current && !comments.empty()) {
                merged.push_back(to_string(current, start, comments));
            }

            comments.erase(text);
            current = start + 1;
        } else {
            if (current != -1 && start != current && start >= current + 1 && !comments.empty()) {
                merged.push_back(to_string(current, start - 1, comments));
            }

            comments.insert(text);
            current = start;
        }
    }

    return merged;
}

void test(const std::vector<std::tuple<int, int, char>> &input) {
    std::cout << "\nInput:\n";
    for (const auto &in: input) {
        const auto&[start, end, text] = in;
        std::cout << '(' << start << ", " << end << "): " << text << "\n";
    }
    std::cout << "\nOutput:\n";
    for (const auto &out: solve(input)) {
        std::cout << out << "\n";
    }
}

int main() {
    test({
             {0, 3, 'A'},
             {2, 4, 'B'},
             {5, 6, 'C'}
         });

    test({
             {0, 3, 'A'},
             {0, 3, 'B'},
             {2, 4, 'C'},
             {5, 6, 'D'}
         });

    test({
             {1, 2, 'A'},
             {2, 3, 'B'},
             {3, 4, 'C'},
             {4, 5, 'D'}
         });

    test({
             {1, 2, 'A'},
             {1, 3, 'B'},
             {1, 4, 'C'},
             {1, 5, 'D'}
         });

    test({
             {5, 5, 'A'},
             {4, 5, 'B'},
             {3, 5, 'C'},
             {2, 5, 'D'}
         });

    test({
             {3, 3, 'A'},
             {4, 4, 'B'},
             {4, 7, 'C'},
             {6, 7, 'D'}
         });
}