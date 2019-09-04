作者：Blue5437
链接：https://www.nowcoder.com/discuss/245173?type=all&order=time&pos=&page=1
来源：牛客网

int main() {
    int n;
    cin >> n;
    vector<double> pos;
    vector<double> neg;
    while (n--) {
        int label;
        double p;
        cin >> label >> p;
        if (label == 1)
            pos.push_back(p);
        else
            neg.push_back(p);
    }
    double sum = 0;
    for (int i = 0; i < pos.size(); i++) {
        for (int j = 0; j < neg.size(); j++) {
            if (pos[i] > neg[j])
                sum += 1;
            else if (pos[i] == neg[j])
                sum += 0.5;
        }
    }
    cout << fixed << setprecision(2) << sum / (pos.size() * neg.size()) << endl;

    system("pause");
    return 0;
}
