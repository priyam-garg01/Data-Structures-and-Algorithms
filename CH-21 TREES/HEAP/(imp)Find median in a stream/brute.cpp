class MedianFinder {
public:
    vector<double> arr;
    int size = 0;
    MedianFinder() {
    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(), arr.end());size++;//O(N^2)Placing each and every elem at its correct place
    }
    
    double findMedian() {
        if(size % 2 == 0){
            return (arr[size/2] + arr[size/2 - 1])/2;
        }
        return arr[size/2];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */