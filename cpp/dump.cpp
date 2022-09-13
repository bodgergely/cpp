#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void permutate(int n, vector<vector<int>>& res)
{
    static unordered_set<int> included;
    static vector<int> vv;

    if (vv.size() == n) {
        res.push_back(vv);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (included.find(i) != included.end())
            continue;
        included.insert(i);
        vv.push_back(i);
        permutate(n, res);
        included.erase(i);
        vv.pop_back();
    }
}

vector<vector<int>> permutations(int n)
{
    vector<vector<int>> res;
    permutate(n, res);
    return res;
}

void subset(int n, int k, vector<vector<int>>& res)
{
    cout << "Calling with: " << k << endl;
    static vector<int> ss;
    if (n + 1 == k) {
        cout << "Reached subset with count: " << ss.size() << endl;
        res.push_back(ss);
        return;
    }
    // include k in the subset
    ss.push_back(k);
    subset(n, k + 1, res);
    // do not include k in the subset
    ss.pop_back();
    subset(n, k + 1, res);
}

vector<vector<int>> subsets(int n)
{
    vector<vector<int>> res;
    subset(n, 1, res);
    return res;
}

void floatingPoint()
{
    unsigned int res = 0;
    char* p = (char*)&res;
    p = p + 3;
    // *p |= 0x7F;
    *p |= 0x00;
    p--;
    *p |= 0x7F;
    p--;
    *p |= 0xFF;
    p--;
    *p |= 0xFF;

    float* fp = (float*)&res;
    cout << *fp << ":" << utils::bin(*fp, sizeof(*fp), true) << endl;
}