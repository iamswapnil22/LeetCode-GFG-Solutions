class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> vec(26,0);
        for(auto word:words)
        {
            for(auto ch:word)
            {
                vec[ch-'a']++;
            }
        }

        int n = words.size();
        for(int val:vec)
        {
            if(val%n != 0)
            {
                return false;
            }
        }
        return true;
    }
    
};