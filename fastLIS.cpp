#include <iostream>
#include<vector>
#include<algorithm>
long getLIS(vector<int> &a){
	vector<int> dp(a.size(),__INT_MAX__);
	for (int i=0; i<a.size(); ++i) {
		*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.end(), __INT_MAX__) - dp.begin();
}