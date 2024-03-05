#include<bits/stdc++.h>
using namespace std;
class segment{
    static int size;
    vector<int> arr;
    vector<int> sum,mini,maxi,prod;
    public:
    segment(int n){
        size = n;
        arr.resize(n,0);
        sum.resize(n*4, 0);
        mini.resize(n*4, INT_MAX);
        maxi.resize(n*4, INT_MIN);
        prod.resize(n*4, 1);
    }

    void input(){
        cout << "Size of arr is " << arr.size() << endl;
        cout << "Enter elements of the array\n";
        for(int i = 0; i < size; i++){
            int num;
            cin >> num;
            arr[i] = num; 
        }
        cout << "Hi";
    }

    void create(){
        createUtils(0,0,size-1);
    }
    void createUtils(int ind,int low,int high){
        if(low == high){
            sum[ind] = mini[ind] = maxi[ind] = prod[ind] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        createUtils(2*ind+1,low,mid);
        createUtils(2*ind+2,mid+1,high);
        sum[ind] = sum[2*ind+1] + sum[2*ind+2];
        prod[ind] = prod[2*ind+1] * prod[2*ind+2];
        mini[ind] = min(mini[2*ind+1],mini[2*ind+2]);
        maxi[ind] = max(maxi[2*ind+1],maxi[2*ind+2]); 
    }
    int getMin(int ind,int left,int right,int low = 0,int high = size){
        if(high<left || right<low ){
            return INT_MAX;
        }else if(left<=low && right>= high){
            return mini[ind];
        }else{
            int mid = low+(high-low)/2;
            return min(getMin(2*ind+1,left,right,low,mid),getMin(2*ind+2,left,right,mid+1,high));
        }
    }
    int getMax(int ind,int left,int right,int low = 0,int high = size-1){
        if(high<left || right<low ){
            return INT_MIN;
        }else if(left<=low && right>= high){
            return maxi[ind];
        }else{
            int mid = low+(high-low)/2;
            return max(getMax(2*ind+1,left,right,low,mid),getMax(2*ind+2,left,right,mid+1,high));
        }
    }
    int getSum(int ind,int left,int right,int low = 0,int high = size-1){
        if(high<left || low>right){
            return 0;
        }else if(left<=low && right>=high){
            return sum[ind];
        }else{
            int mid = low+(high-low)/2;
            return getSum(2*ind+1,left,right,low,mid) + getSum(2*ind+2,left,right,mid+1,high);
        }
    }
    int getProduct(int ind,int left,int right,int low = 0,int high = size-1){
        if(high<left || right<low ){
            return 1;
        }else if(left<=low && right>= high){
            return prod[ind];
        }else{
            int mid = low+(high-low)/2;
            return getProduct(2*ind+1,left,right,low,mid)* getProduct(2*ind+2,left,right,mid+1,high);
        }
    }
    void update(int ind,int i,int val,int low = 0,int high = size-1){
        if(low == high){
            sum[ind] = mini[ind] = maxi[ind] = prod[ind] = val;
            return;
        }
        int mid = low + (high-low)/2;
        if(i<=mid){
            update(2*ind+1,i,val,low,mid);
        }else{
            update(2*ind+2,i,val,mid+1,high);
        }
        sum[ind] = sum[2*ind+1] + sum[2*ind+2];
        prod[ind] = prod[2*ind+1] * prod[2*ind+2];
        mini[ind] = min(mini[2*ind+1],mini[2*ind+2]);
        maxi[ind] = max(maxi[2*ind+1],maxi[2*ind+2]); 
    }

};
int segment::size  = 0;
int main(){
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    segment obj(n);
    obj.input();
    obj.create();
    do{
        cout<<"0.Get Min\n1.Get Max\n2.Get Sum\n3.Get Prod\n4.Update\n";
        cin>>n;
        int left,right;
        if(n == 0){
            cout<<"Enter left and right\n";
            cin>>left>>right;
            cout<<obj.getMin(0,left,right)<<endl;
        }else if(n == 1){
            cout<<"Enter left and right\n";
            cin>>left>>right;
            cout<<obj.getMax(0,left,right)<<endl;
        }else if(n == 2){
            cout<<"Enter left and right\n";
            cin>>left>>right;
            cout<<obj.getSum(0,left,right)<<endl;
        }else if(n == 3){
            cout<<"Enter left and right\n";
            cin>>left>>right;
            cout<<obj.getProduct(0,left,right)<<endl;
        }else{
            int ind,val;
            cout<<"Enter index and value to update\n";
            cin>>ind>>val;
            obj.update(0,ind,val);
        }
    }while(n<=4 && n>=0);
    return 0;
}