vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i = 0, j = 0;
    vector<int> ans;
    while(i < A.size() and j < B.size()){
        if(A[i] == B[j]){
            ans.push_back(A[i]);
            i++; j++;
        }
        else if(A[i] < B[j]) i++;
        else j++;
    }
    return ans;
}