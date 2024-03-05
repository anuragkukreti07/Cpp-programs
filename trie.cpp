#include<bits/stdc++.h>
using namespace std;
struct trienode{
    bool endofWord;
    trienode* children[26];
};
class trie{
    trienode* root;
    public:
        trie(){
        }
        void Insert(string s){
            if(root == NULL){
                cout<<"HI";
                root = new trienode();
                root->endofWord = false;
            }
            trienode* temp = root;
            for(char ch:s){
                int idx = ch-'a';
                if(temp->children[idx] == NULL){
                    temp->children[idx] = new trienode();
                }
                temp = temp->children[idx];
            }
            temp->endofWord = true;
        }
        void Delete(string s){
            trienode* temp = root;
            stack<trienode*> st;
            for(char ch:s){
                int idx = ch - 'a';
                if(temp->children[idx] == NULL){
                    return;
                }
                st.push(temp);
                temp = temp->children[idx];
            }
            if(temp->endofWord == false){
                return;
            }
            temp->endofWord = false;
            string s1 = s;
            while(!st.empty() && temp->endofWord == false && noChild(temp)){    
                int idx = s1.back() - 'a';
                delete temp;
                temp = st.top()->children[idx];
                st.pop();
                s1.pop_back();
            }
        }
        bool noChild(trienode* root){
            for(int i=0;i<26;i++){
                if(root->children[i]){
                    return false;
                }
            }
            return true;
        }
        bool Search(string s){
            trienode* temp = root;
            for(char ch:s){
                int idx = ch-'a';
                if(temp->children[idx] == NULL){
                    return false;
                }
                temp = temp->children[idx];
            }
            return temp->endofWord;
        }
};
int main(){
    int ch ;
    string s;
    trie obj;
    do{
        cout<<"1.Insert\n2.Search\n3.Delete\n";
        cin>>ch;
        if(ch == 1){
            cout<<"Enter string to be inserted\n";
            cin>>s;
            obj.Insert(s);
        }else if(ch == 2){
            cout<<"Enter string to be Searched\n";
            cin>>s;
            if(obj.Search(s) == true){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else if(ch == 3){
            cout<<"Enter string to be Deleted\n";
            cin>>s;
            obj.Delete(s);
        }
    }while(ch<4 && ch>0);
}