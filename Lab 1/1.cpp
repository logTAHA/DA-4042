#include <bits/stdc++.h>
using namespace std;

vector<long> solve(vector<vector<long>> arr);
vector<long> merge_arr(vector<long> a, vector<long> b);

int main() {
    int n, k;
    cin >> n >> k;
        
    vector<vector<long>> groups(k, vector<long>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> groups[i][j];
        }
    }

    vector<long> ans = solve(groups);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

vector<long> solve(vector<vector<long>> arr) {
    if (arr.size() == 0) {
        return {};
    }

    if (arr.size() == 1) {
        return arr[0];
    }

    int mid = arr.size() / 2;

    vector<long> left = solve(
        vector<vector<long>>(arr.begin(), arr.begin() + mid)
    );

    vector<long> right = solve(
        vector<vector<long>>(arr.begin() + mid, arr.end())
    );

    return merge_arr(left, right);
}

vector<long> merge_arr(vector<long> a, vector<long> b) {
    vector<long> res;
    res.reserve(a.size() + b.size());

    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }

    while (i < n) {
        res.push_back(a[i++]);
    }

    while (j < m) {
        res.push_back(b[j++]);
    }

    return res;
}
