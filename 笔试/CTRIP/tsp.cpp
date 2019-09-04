作者：Blue5437
链接：https://www.nowcoder.com/discuss/245173?type=all&order=time&pos=&page=1
来源：牛客网

// 旅行商问题
// 从原点出发遍历所有点回到原点，有权图
// NP难问题，所以递归回溯所有情况即可，注意n==1的情况

void helper(int idx, int nums, int &res, int cur, vector<vector<pair<int, int>>> &neigh, vector<bool> &flag) {
    if (idx == 0 && flag[idx] == true) {
        if (nums == flag.size())
            res = min(res, cur);
        return;
    }
    for (int i = 0; i < neigh[idx].size(); i++) {
        if (flag[neigh[idx][i].first] == false) {
            flag[neigh[idx][i].first] = true;
            helper(neigh[idx][i].first, nums + 1, res, cur + neigh[idx][i].second, neigh, flag);
            flag[neigh[idx][i].first] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<pair<int, int>>> neigh(n);
    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        neigh[a].push_back(make_pair(b, t));
        neigh[b].push_back(make_pair(a, t));
    }
    vector<bool> flag(n, false);
    int res = INT_MAX;
    helper(0, 0, res, 0, neigh, flag);
    if (res == INT_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
    system("pause");
    return 0;
}
