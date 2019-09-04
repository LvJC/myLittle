作者：Blue5437
链接：https://www.nowcoder.com/discuss/245173?type=all&order=time&pos=&page=1
来源：牛客网

//示例输入："aabbcddc"
//示例输出：2, 2, 4

// 两次遍历，第一次统计字母个数，第二次维护cur 和 tar，cur表示当前字母个数，tar表示目标个数（例如已包含a，则全部a都要包含），
// cur==tar时划分并清0

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> m;
    unordered_map<char, bool> flag;
    int sum = 0, cur = 0;
    vector<int> res;
    for (int i = 0; i < s.size(); i++)
        m[s[i]]++;
    for (int i = 0; i < s.size(); i++) {
        if (flag.find(s[i]) == flag.end()) {
            sum += m[s[i]];
            flag[s[i]] = true;
        }
        cur++;
        if (cur == sum) {
            res.push_back(cur);
            cur = 0;
            sum = 0;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1)
            cout << res[i] << ',';
        else
            cout << res[i] << endl;
    }
    system("pause");
    return 0;
}
