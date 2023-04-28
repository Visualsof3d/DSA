#include <bits/stdc++.h>
using namespace std;

// Link -> https://leetcode.com/problems/merge-intervals/
// Intervals = {{1,3}, {2,6}, {5,10}, {15,18}};
// Output -> Intervals = {{1,10}, {15,18}};

// Function Prototype
vector<vector<int>> mergeInterval( vector<vector<int>>& interval );

int main(){
    vector<vector<int>> Interval = {{1,3}, {2,6}, {5,10}, {15,18}};
    
    // Calling Function
    vector<vector<int>> mergedIntervals = mergeInterval(Interval);

    // Printing
    for(auto vec: mergedIntervals){
        cout<<"{ ";
        for(auto it: vec){
            cout<< it <<" ";
        }
        cout<< "}" <<endl;
    }
}


// Merge all overlapping intervals, and return the non-overlapping intervals
vector<vector<int>> mergeInterval( vector<vector<int>>& interval ){
    vector<vector<int>> ans;
    // If vector is empty
    if(interval.size() == 0) 
        return ans;
    
    // Sorting for easily access
    sort(interval.begin(), interval.end());

    // This store the first vector element present in array of vector
    vector<int> temp = interval[0];
    for(auto it: interval){
        if(it[0] <= temp[1])
            // eg: temp = {5, 8}, it = {6, 7} || temp = {5, 8}, it = {6, 11}
            temp[1] = max(it[1], temp[1]);
        else{
            ans.push_back(temp);
            temp = it;
        }      
    }
    ans.push_back(temp);
    return ans;
}

