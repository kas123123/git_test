#include <iostream>

using namespace std;

int main()
{
    int n;
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[n];
    }
    merge_sort(0,(n-1)/2,n-1,a);
    for(int i=0; i<n; i++){
        cout << a[n] << " ";
    }
    delete[] a;
    return 0;
}
void merge_sort(int left,int middle, int right, int& s[]){

//나누는 부분
    int lm = (left + middle)/2, mr = (middle+1+right)/2;
    merge_sort(left,lm,middle,s);
    merge_sort(middle+1, mr,right,s);

//합치는 부분
    int* l = new int[middle - left + 1];
    int* r = new int[right - middle];
    for(int i=0; i<right-left+1; i++){
        if(i< middle-left+1){
            l[i] = s[i];
        }
        else{
            r[i-(middle-left+1)] = s[i];
        }
    }
    int x=0,y=0,z=0;
    while(1){
        if(y==middle-left+1 || z==right-middle) break;
        if(l[y] > r[z]){
            s[x] = r[z];
            z++;
            x++;
        }
        else{
            s[x] = l[y];
            y++;
            x++;
        }
    }
    for(int i=x; i<right-left+1; i++){
        if(y==middle-left+1){
            s[i] = r[z+i-x];
        }
        else{
            s[i] = l[y+i-x];
        }
    }
    delete[] l,r;
}
