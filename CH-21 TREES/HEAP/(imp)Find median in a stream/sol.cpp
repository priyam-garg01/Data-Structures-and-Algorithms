/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.*/
class MedianFinder {
public:
    priority_queue<double> pMax;
    priority_queue<double, vector<double>, greater<double> > pMin;
    int sMax = 0;
    int sMin = 0;
    MedianFinder() {

    }
    
    void balanceHeaps(){//O(logn)
         
        if(sMax > sMin){
            pMin.push(pMax.top());//O(n(logn))
            pMax.pop();
            sMax--;
            sMin++;
        }
        else if(sMax < sMin){
            pMax.push(pMin.top());//O(nlogn)
            pMin.pop();
            sMax++;
            sMin--;
        }
    }
    void addNum(int num) {//O(logn)
        if(sMax == 0 || num <= pMax.top()){
            pMax.push(num);//(logn)
            sMax++;
        }
        else {
            pMin.push(num);//(logn)
            sMin++;
        }
        balanceHeaps();
        
        
    }
    double findMedian() {
         if(sMin == sMax + 1){
                return pMin.top();
            }
         if(sMax == sMin + 1){
                return pMax.top();
            }

        return (pMax.top() + pMin.top())/2;//if sizes are equal
    }
};/*T.C. = O(NLOGN), S.C. = O(N) for n additions*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
