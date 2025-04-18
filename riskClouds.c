#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map <string, vector<string>> edge;
unordered_map <string, int> spb;
unordered_map <string, int> npb;
unordered_map <string, int> counts;
vector <string> clouds;
int n_npb, n_spb = 0;


void dfs(string node, int& n_npb, int& n_spb) {
    // 每次加上子节点的问题数目
    auto it = npb.find(node);
    auto de = spb.find(node);
    // 如果npb有值就加上
    if (it != npb.end()) {
        n_npb += npb[node];
    }
    // 如果spb有这个值的话就加上
    if (de != spb.end()) {
        n_spb += spb[node];
    }
    // 递归遍历子节点
    for (string child : edge[node]) {
        dfs(child, n_npb, n_spb);
    }
}

bool isRepeat(string node, vector <string> nodes) {
    for (string m : nodes) {
        if (node == m) {
            return true;
        }
    }
    return false;
}

int main()
{
    // 阈值m，n组节点信息
    int m, n;
    cin >> m >> n;
    
    while (n--) {
        string node;
        string parent;
        cin >> node >> parent;
        // 如果node已经在云服务里面就不加了，如果不在且父节点为‘*’，则加上
        if (!isRepeat(node, clouds) && parent == "*") {
            clouds.push_back(node);
        }
        else if (parent != "*") {
            auto it = edge.find(parent);
            // 如果parent未定义
            if (it == edge.end()) {
                edge[parent].push_back(node);
            }
            // 如果parent已经被定义但node不在里面
            else if (it != edge.end() && !isRepeat(node, edge[parent])) {
                edge[parent].push_back(node);
            }
        }
        int sig;
        cin >> sig;
        int num;
        cin >> num;
        // 若为0则算严重问题
        if (!sig) {
            spb[node] = num;
        }
        else if (sig == 1) {
            npb[node] = num;
        }
    }
    // int res, ans = 0;
    int res, ans = 0;
    // 每次递归计算问题总数
    for (string root : clouds) {
        n_npb = n_spb = 0;
        dfs(root, n_npb, n_spb);
        res = 5 * n_spb + 2 * n_npb;
        // 如果结果大于阈值，则属于风险云服务，计数加1
        if (res > m) {
            ans++;
        }
    }
    cout << ans;
    return ans;
}
