public class Solution {	
	public static long maxSubarraySum(int[] arr, int n) {
		long sumtillhere = 0, maxtillhere = 0;
    	for(int i = 0; i < n; i++){
        	sumtillhere = Math.max((long)sumtillhere + (long)arr[i], (long)arr[i]);
        	maxtillhere = Math.max((long)maxtillhere, (long)sumtillhere);
    	}
    	return maxtillhere;
	}
}
