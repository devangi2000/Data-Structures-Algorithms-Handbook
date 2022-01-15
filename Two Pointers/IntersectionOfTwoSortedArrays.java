public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> intersect(final List<Integer> A, final List<Integer> B) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int i = 0, j = 0;
    while(i < A.size() && j < B.size()){
        if(A.get(i) == B.get(j)){
            ans.add(A.get(i));
            i++; j++;
        }
        else if(A.get(i) < B.get(j)) i++;
        else j++;
    }
    return ans;
    }
}