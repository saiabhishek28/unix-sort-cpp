#include <iostream>
#include <vector>

using namespace std;

void merge(std::vector<int> &v, int left_index, int mid_index, int right_index) 
{
    int i, j, k, left_size, right_size; //to merge the sub arrays

    left_size = mid_index - left_index + 1; //defining left and right array size
    right_size = right_index - mid_index;

    std::vector<int> L, R; //init 2 vectors

    L.resize(left_size); //resizing vectors as per left and right size
    R.resize(right_size);

    for (i = 0; i < left_size; i++) {
        L[i] = v[left_index + i]; //writing left side vector
    }

    for (j = 0; j < right_size; j++) {
        R[j] = v[mid_index + 1 + j]; //creating right side vector
    }

    i = 0;
    j = 0;
    k = left_index;


    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            v[k] = L[i]; 
            i++;

        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
//the above part is written to merge the left and right array to the real array

    while (i < left_size) { //to counter edge case if there is an extra element in the left array
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size) { //to counter edge case if there is an extra element in the right array
        v[k] = R[j];
        j++;
        k++;
    }

}


void merge_sort(std::vector<int> &v, int left, int right) 
{
    if (left < right) {
        int mid = (left + right) / 2;//define mid
        //sort the left and right side
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        //merge the final array
        merge(v, left, mid, right);


    }
}

int part(vector<int> &v, int start, int end){
	
	int p = end; //setting pivot as the last element
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[p]){ //if right side is less than pivot 
			swap(v[i],v[j]); //swap pivot with the element
			++j; //increment j
		}
	}
	swap(v[j],v[p]); //swap left with pivot element
	return j;
	
}

void quick_sort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = part(v,start,end); //partition function
		quick_sort(v,start,p-1);
		quick_sort(v,p+1,end);
	}
	
}