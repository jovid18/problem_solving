#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int add_element(int mask, int element) {
    // Add element to mask
    return mask | (1 << element);
}

int remove_element(int mask, int element) {
    // Remove element from mask
    return mask & ~(1 << element);
}
int toggle_element(int mask, int element) {
    // Toggle element in mask
    return mask ^ (1 << element);
}

int count_elements(int mask) {
    // Count number of elements in mask
    return __builtin_popcount(mask);
}

void print_subset(int mask) {
    // Print subset of mask
    cout << bitset<64>(mask) << '\n';
}

vector<int> get_subset(int mask) {
    // Get subset of mask
    vector<int> subset;
    for (int subset_mask = mask; subset_mask; subset_mask = (subset_mask - 1) & mask) {
        print_subset(subset_mask);
        subset.push_back(subset_mask);
    }
    return subset;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}