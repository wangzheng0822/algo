#include <iostream>
#include <unordered_map>

class SolutionOFOneTwoStep {
  private:
    static std::unordered_map<size_t, size_t> result_;

  public:
    enum class POLICY {
        RECURSIVE,
        NONRECURSIVE
    };

  private:
    size_t recursive(size_t steps) {
        auto iter = result_.find(steps);
        if (result_.end() != iter) {  // found.
            return iter->second;
        } else {
            size_t res = operator()(steps - 1) + operator()(steps - 2);
            result_.insert({steps, res});
            return res;
        }
    }
    size_t nonrecursive(size_t steps) {
        auto iter = result_.find(steps);
        if (result_.end() != iter) {  // found.
            return iter->second;
        } else {
            size_t start;
            for (start = steps; start != 2 and result_.end() == result_.find(start); --start) {}
            for (size_t i = start; i != steps; ++i) {
                result_.insert({i + 1, result_[i - 1] + result_[i]});
            }
            return result_[steps];
        }
    }

  public:
    size_t operator()(size_t steps, const POLICY policy = POLICY::RECURSIVE) {
        if (policy == POLICY::RECURSIVE) {
            return recursive(steps);
        } else if (policy == POLICY::NONRECURSIVE) {
            return nonrecursive(steps);
        }
    }
    static void debug() {
        for (auto kv : result_) {
            std::cout << kv.first << ' ' << kv.second << std::endl;
        }
        std::cout << std::endl;
    }
};

std::unordered_map<size_t, size_t> SolutionOFOneTwoStep::result_ = {{1, 1}, {2, 2}};

int main() {
    SolutionOFOneTwoStep::debug();

    std::cout << SolutionOFOneTwoStep()(5, SolutionOFOneTwoStep::POLICY::RECURSIVE) << std::endl;
    SolutionOFOneTwoStep::debug();

    std::cout << SolutionOFOneTwoStep()(10, SolutionOFOneTwoStep::POLICY::NONRECURSIVE) << std::endl;
    SolutionOFOneTwoStep::debug();

    std::cout << SolutionOFOneTwoStep()(20, SolutionOFOneTwoStep::POLICY::RECURSIVE) << std::endl;
    SolutionOFOneTwoStep::debug();

    return 0;
}

