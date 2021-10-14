// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure
// and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with
// "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest
// lexical order when read as a single string.
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

// Example 1:
// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]
// Example 2:

// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 
// Constraints:

// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi
        // multiset is used since it keeps the items sorted and we need the lexicographically smallest item
        // map is used since it allows for random access; O(1) search time
        // also use stack for the special case encountered when there's a deadend for the lex. smaller item
        // TC : O(E) 
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        unordered_map<string, multiset<string>> adj;
        vector<string> ans;
        stack<string> st;
        for(auto ticket : tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        st.push("JFK");
        while(!st.empty()){
            string source = st.top();
            if(adj[source].size()==0){
                ans.push_back(source);
                st.pop();
            }
            else{
                auto dest = adj[source].begin();
                st.push(*dest);
                adj[source].erase(dest);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
