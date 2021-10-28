// Method 1

class Solution
{
    public List<String> AllPossibleStrings(String s)
    {
        List<String> result = new ArrayList<>();
        int n = s.length();
        for(int i = 1; i < (1 << n); i++){
            String res = "";
            int temp = i, j = 0;
            while(temp > 0){
                if((temp & 1) != 0)
                    res += s.charAt(j);
                j++;
                temp >>= 1;
            }
            if(res.length() > 0)
                result.add(res);
        }
        Collections.sort(result);
        return result;
    }
}

// Method 2

class Solution
{
    public void solve(String s, List<String> result, int idx, String curr){
        if(idx == s.length()){
            if(curr != "")
                result.add(curr);
            return;
        }
        solve(s, result, idx + 1, curr + s.charAt(idx));
        solve(s, result, idx + 1, curr);
    }
    public List<String> AllPossibleStrings(String s)
    {
        List<String> result = new ArrayList<>();
        solve(s, result, 0, "");
        Collections.sort(result);
        return result;
    }
}