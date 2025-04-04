class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freqMap;

            for (int num : nums) {
                freqMap[num]++;
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            for (unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
                int num = it->first;
                int freq = it->second;
                minHeap.push({freq, num});
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }

            vector<int> result;
            while (!minHeap.empty()) {
                result.push_back(minHeap.top().second);
                minHeap.pop();
            }
    
            return result;
        }
    };