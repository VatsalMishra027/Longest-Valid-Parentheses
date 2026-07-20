#include <bits/stdc++.h>
using namespace std;

int main() {
        string s;
        cin>>s;
        int n = s.size();
        int maxLen = 0;

        // Left to right pass: treat '(' as +1, ')' as -1
        int left = 0, right = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(') left++;
            else right++;

            if (right > left){
                // invalid, reset
                left = 0;
                right = 0;
            } else if (left == right){
                maxLen = max(maxLen, 2 * right);
            }
        }

        // Right to left pass: treat ')' as +1, '(' as -1
        left = 0; right = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == ')') right++;
            else left++;

            if (left > right){
                // invalid, reset
                left = 0;
                right = 0;
            } else if (left == right){
                maxLen = max(maxLen, 2 * left);
            }
        }
        cout << maxLen << endl;
    return 0;
}   