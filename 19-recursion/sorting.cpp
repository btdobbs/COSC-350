#include <iostream>
using namespace std;

void print(const int a[], int size){
    cout << "[";
    for(int i = 0; i < size-1; i++){
        cout << a[i] << ",";
    }
    if (size != 0)
        cout << a[size-1];
    cout << "]" << endl;
}

void merge(const int s1[], const int s2[], int s[], const int s1_size, const int s2_size, const int s_size){
    int i = 0;
    int j = 0;
    int s_current_index = 0;
    while (i < s1_size && j < s2_size){
        if (s1[i] <= s2[j]){
            s[s_current_index] = s1[i];
            i++;
        } else {
            s[s_current_index] = s2[j];
            j++;
        }
        s_current_index++;
    }
    while (i < s1_size){
        s[s_current_index] = s1[i];
        i++;
        s_current_index++;
    }
    while (j < s2_size){
        s[s_current_index] = s2[j];
        j++;
        s_current_index++;
    }
}

//Split the sorting input in half and recursivly sort the halves.  Merge the split lists.
void merge_sort(int a[], int size){
    if (size <= 1) return;
    int half_size = size/2;
    int s1[half_size];
    int s2[half_size];
    for (int i = 0; i < half_size; i++) s1[i] = a[i];
    for (int i = half_size; i < size; i++) s2[i-half_size] = a[i];
    merge_sort(s1, half_size); //recursive step
    merge_sort(s2, half_size); //recursive step
    merge(s1,s2,a,half_size,half_size,size);
}

//Split the sorting input based on a pivot element and recursivly sort values less than and greater than pivot.  Construct the split lists.
void quick_sort(int a[], int size){
    if (size <= 1) return;
    int pivot = a[size - 1];
    int less[size-1];   //all minus pivot could be less
    int equal[size];    //all could be equal
    int greater[size-1];//all minus pivot could be greater
    int less_size = 0;
    int equal_size = 0;
    int greater_size = 0;
    for (int i = 0; i < size; i++){
        if (a[i] < pivot){
            less[less_size] = a[i];
            less_size++;
        } else if (a[i] == pivot){
            equal[equal_size] = a[i];
            equal_size++;
        } else{
            greater[greater_size] = a[i];
            greater_size++;
        }
    }
    quick_sort(less, less_size); //recursive step
    quick_sort(greater, greater_size); //recursive step
    int current_index = 0;
    for (int i = 0; i < less_size; i++){
        a[current_index] = less[i];
        current_index++;
    }
    for (int i = 0; i < equal_size; i++){
        a[current_index] = equal[i];
        current_index++;
    }
    for (int i = 0; i < greater_size; i++){
        a[current_index] = greater[i];
        current_index++;
    }
}

int main() {
    //Merge Sort
    const int size = 8;
    int a[size] = {85,24,63,45,17,31,96,50};
    print(a,size);
    merge_sort(a,size);
    print(a,size);
    //Quick Sort
    int b[size] = {85,24,63,45,17,31,96,50};
    print(b,size);
    quick_sort(b, size);
    print(b,size);
    return 0;
}
