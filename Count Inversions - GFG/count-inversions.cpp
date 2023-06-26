//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long int
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[], ll l, ll mid, ll r) {
        ll n1 = mid - l + 1, n2 = r - mid;
        ll a[n1], b[n2];
        
        for(ll i=0; i<n1; i++) a[i] = arr[l+i];
        for(ll j=0; j<n2; j++) b[j] = arr[mid+j+1];
        
        ll i=0, j=0, k=l, inv = 0LL;
        
        while(i<n1 and j<n2) {
            if(a[i] <= b[j]) {
                arr[k++] = a[i++];
            } 
            else {
                inv += (n1 - i);
                arr[k++] = b[j++];
            }
        }
        
        while(i<n1) arr[k++] = a[i++];
        while(j<n2) arr[k++] = b[j++];
        return inv;
    }
    
    ll mergeSort(ll arr[], ll l, ll r) {
        ll inv = 0;
        if(l < r) {
            ll mid = (l + r) / 2;
            inv += mergeSort(arr, l, mid);
            inv += mergeSort(arr, mid+1, r);
            inv += merge(arr, l, mid, r);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N-1);
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends