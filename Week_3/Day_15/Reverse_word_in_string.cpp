class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0;i < s.length(); ){
            
            int j = i,c = 0;
            while(j < s.length() && s[j] == ' ')j++,c++; 
            while(j < s.length() && s[j] != ' ')j++;
            reverse(s.begin() + i,s.begin() + j);
            i = j - c + 1;
        }
        while(!s.empty() && s.back() == ' ')s.pop_back();
        reverse(s.begin(),s.end());
		
        return s;
        
    }
};