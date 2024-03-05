
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    int index;
    vector<int> list;
    public:
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
             index = -1;
        }
};
class Solution {
    void insert(TrieNode* root,string word,int ind){
        for(int i= word.length()-1;i>=0;i--){
            int curr = word[i] - 'a';
            if(root->children[curr] == NULL){
                root->children[curr] = new TrieNode();
            }
            if(isPalindrome(word,0,i)){
                root->list.push_back(ind);
            }
            root = root->children[curr];
        }
        root->list.push_back(ind);
        root->index = ind;
    }
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    void search(vector<string>& words,int i,TrieNode* root,vector<vector<int>>& ans){
        for(int j = 0;j<words[i].length();j++){
            if(root->index >= 0 && root->index!=i && isPalindrome(words[i],j,words[i].length()-1)){
                ans.push_back({i,root->index});
            }
            root = root->children[words[i][j] - 'a'];
            if(root == NULL){
                return;
            }
        }
        for(int j:root->list){
            if(i == j){
                continue;
            }
            ans.push_back({i,j});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            insert(root,words[i],i);
        }
        for(int i=0;i<n;i++){
            search(words,i,root,ans);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter strings:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    ans = obj.palindromePairs(arr);

    cout << "Palindrome Pairs:\n";
    for(const auto &pair : ans) {
        cout << "(" << arr[pair[0]] << ", " << arr[pair[1]] << ")\n";
    }

    return 0;
}
