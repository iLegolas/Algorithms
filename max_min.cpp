#include <iostream>

 int Max(int*, int);
 int Min(int*, int);

 int main() {
    int n, a[20], max=0, min=0;
    std::cout << "\n\n\t Enter the size of the array : ";
    std::cin >> n;
    std::cout << "\n\t Enter the values :\n";
    for(int i=0; i<n; i++)
        std::cin >> a[i];
    max = Max(a, n);
    min = Min(a, n);
    std::cout << "\n\n\t Maximum : " << max << std::endl;
    std::cout << "\n\n\t Minimum : " << min << std::endl;
    return 0;
 }

 int Max(int *p, int size) {
    int mid = size/2, m1 = 0, m2 = 0;
    if(size < 2)
        return *p;
    m1 = Max(p, mid);
    m2 = Max(p+mid, size-mid);
    return ((m1>m2)?m1:m2);
 }

 int Min(int *p, int size) {
    int mid = size/2, m1 = 0, m2 = 0;
    if(size < 2)
        return *(p);
    m1 = Min(p, mid);
    m2 = Min(p+mid, size-mid);
    return ((m1>m2)?m2:m1);
 }
