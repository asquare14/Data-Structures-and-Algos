#include<bits/stdc++.h>
using namespace std;
int temp[8] 
void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++];
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }
    
int main()
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(10);
    int N = arr.size();

    vector<pair<int, int> > v(N);
    for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

    vector<int> count(N, 0);
    // sorting in descending order
    mergeSort(count, v, 0, N-1);

    cout<<"Sorted Array"<<endl;
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
}