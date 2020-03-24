class Solution {
 public:
	int lastStoneWeightII(vector<int>& stones) {
		int sum = 0;
		for(int i=0; i<stones.size(); i++)
			sum += stones[i];

		int V = sum / 2;
		int Bag[V+1];
		memset(Bag, 0, sizeof(Bag));
		for(int i=1; i<=stones.size(); i++)
			for(int j=V; j>=stones[i-1]; j--)
				Bag[j] = max(Bag[j], Bag[j-stones[i-1]] + stones[i-1]);

		return sum - Bag[V]*2;
	}
};
