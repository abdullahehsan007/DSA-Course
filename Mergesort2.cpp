#include<iostream>
using namespace std;
void mergesort(int arr[],int left[],int n,int right[],int m){
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(left[i]<right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n){
		arr[k]=left[i];
		i++;
		k++;
		
	}
	while(j<m){
		arr[k]=right[j];
		j++;
		k++;
		
	}
	
}
void merge(int arr[],int n){
	if(n<=0){
		return;
	}
	int mid=n/2;
	int left[mid];
	int right[n-mid];
	for(int i=0;i<mid;i++){
		left[i]=arr[i];
	}
	for(int i=mid;i<n;i++){
		right[i-mid]=arr[i];
	}
merge(left,mid);
merge(right,n-mid);
mergesort(arr,left,mid,right,n-mid);	
	
}
int main(){
	int n;
	cout<<"Enter Number of Elements in an array :";
	cin>>n;
	int arr[n];
	cout<<"Enter Elements in a array :"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge(arr,n);
	cout<<"After Sorting :"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"|";
	}
}
