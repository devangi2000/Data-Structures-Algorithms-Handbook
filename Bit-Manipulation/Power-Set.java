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