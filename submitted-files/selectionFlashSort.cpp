// With Count
void selectionSortWithCount(int a[], int n, long long &countC){
    countC = 0;
    for (int i = 0; ++countC && (i < n - 1); ++i) {
        int cur_min = i;
        
        for (int j = i + 1; ++countC && (j < n); ++j)
            if (++countC && a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]); 
    }
}
// Without Count
void selectionSortWithoutCount(int a[], int n){
    for (int i = 0; i < n - 1; ++i) {
        int cur_min = i;
        
        for (int j = i + 1; j < n; ++j)
            if (a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]); 
    }
}
// With Count
void flashSortWithCount(int a[], int n, long long &countC){
    int *__L = new int[n];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2){
        m = 2;
    }
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0];
    int Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i]){
            Mx = a[i];
        }
        if (Mn > a[i] ){
            Mn = a[i];
        }
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++countC && (i < n); ++i){
        ++__L[getK(a[i])];
    }
        
    for (int i = 1; ++countC && (i < m); ++i){
        __L[i] += __L[i - 1];
    }
        
    //step 2
    int count = 0;
    int i = 0;
    while (++countC && count < n) {
        int k = getK(a[i]);
        while (++countC && (i >= __L[k])){
            k = getK(a[++i]);
        }
            
        int z = a[i];

        while (++countC && (i != __L[k])) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    //step 3
    for (int k = 1; ++countC && (k < m); ++k) {
        for (int i = __L[k] - 2; ++countC && (i >= __L[k - 1]); --i)
            if (++countC && (a[i] > a[i + 1])) {
                int t = a[i], j = i;
                while (++countC && (t > a[j + 1])){
                    a[j] = a[j + 1]; ++j;
                } 
                a[j] = t;
            }
    }
}
// Without Count
void flashSortWithoutCount(int a[], int n) {
    int *__L = new int[n];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i]) Mx = a[i];
        if (Mn > a[i]) Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k]) 
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    //step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {a[j] = a[j + 1]; ++j;}
                a[j] = t;
            }
    }
}