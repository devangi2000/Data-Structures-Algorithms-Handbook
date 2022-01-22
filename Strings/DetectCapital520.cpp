class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i = 2; i < n; i++)
                if(islower(word[i]))return false;
        } else if(isupper(word[0]) && islower(word[1])) {
                for(int i = 2; i < n; i++)
                    if(isupper(word[i])) return false;
        }
            else if(islower(word[0]))
                for(int i = 0; i < n; i++)
                    if(isupper(word[i])) return false;
        return true;
    }
};
