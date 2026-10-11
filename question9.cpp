class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size(), m = p.size();
        if (m > n) return result;

        vector<int> need(26, 0), window(26, 0);
        for (char c : p) need[c - 'a']++;

        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;              // 加入右端

            if (i >= m) {                       // 窗口超过 m，移除左端
                window[s[i - m] - 'a']--;
            }

            if (window == need) {               // 窗口大小正好为 m 时比较
                result.push_back(i - m + 1);
            }
        }
        return result;
    }
};