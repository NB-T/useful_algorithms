#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// find length of longest palindrome centered on index (left + right) / 2
int expand(string s, int left, int right)
{
     size_t l = left;
     size_t r = right;
     while (l >= 0 && r < s.size() && s[l] == s[r])
     {
          --l;
          ++r;
     }
     return r - l - 1;
}

// find longest palindromic substring of s
string longestPalindrome(string s)
{

     // if empty string
     if (s.size() == 0)
          return "";

     // start and end indices of longest sub-palindrome
     int start = 0;
     int end = 0;

     // for each potential center idx i of a palindrome
     for (size_t i = 0; i < s.size(); ++i)
     {
          // find longest palindrome centered on i
          int len1 = expand(s, i, i);
          int len2 = expand(s, i, i + 1);
          int len = max(len1, len2);

          // if this was larger than longest previously found palindrome, update
          if (len > end - start)
          {
               start = i - (len - 1) / 2;
               end = i + (len - 1) / 2;
          }
     }
     return s.substr(start, end + 1);
}

// count number of palindromic substrings
int countPalindromicSubstrings(string s)
{
     int n = s.size();
     int ans = 0;
     for (int i = 0; i < n; ++i)
     {
          int left = i - 1;
          int right = i;

          // make center as large as possible
          while (right < n - 1 && s[right] == s[right + 1]) ++right;

          // center contains (right - left)th triangular number of palindromes
          ans += (right - left) * (right - left + 1) / 2;

          // i jumps to start of segment after current center
          i = right++;
          while (left >= 0 && right < n && s[right] == s[left])
          {
               ++ans;
               ++right;
               --left;
          }
     }
     return ans;
}