#include <vector>
#include <unordered_map> // 底层由哈希表实现，key无序，查询增删效率O(1)
#include <map>			 // 底层由红黑树实现，key有序，查询增删效率O(logn)
#include <unordered_set> // 底层由哈希表实现，
#include <algorithm>

#include "Solution.h"

void Solution::function1(long long n)
{
	long long k = 0;
	for (long long i = 0; i < n; i++){
		k++;
	}
}

void Solution::function2(long long n)
{
	long long k = 0;
	for (long long i = 0; i < n; i++){
		for (long j = 0; j < n; j++){
			k++;
		}
	}
}

void Solution::function3(long long n)
{
	long long k = 0;
	for (long long i = 0; i < n; i++){
		for (long long j = 1; j < n; j = j * 2){
			k++;
		}
	}
}

void Solution::TestFunction()
{
	long long n;	// 数据规模
	while (1){
		cout << "输入n：";
		cin >> n;
		milliseconds start_time = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch()
		);

		//function1(n);
		//function2(n);
		function3(n);

		milliseconds end_time = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch()
		);

		cout << "耗时：" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
	}
}

vector<int> Solution::twoSum0(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); i++){
		for (int j = i + 1; j < nums.size(); j++){
			if (nums[i] + nums[j] == target){
				return{ i, j };
			}
		}
	}
	return{};
}

vector<int> Solution::twoSum1(vector<int>& nums, int target)
{
	std::map<int, int> map;
	for (int i = 0; i < nums.size(); i++){
		auto iter = map.find(target - nums[i]);
		if (iter != map.end()){
			return{ iter->second, i };
		}
		map.insert({ nums[i], i });
	}
	return{};
}

vector<int> Solution::twoSum2(vector<int>& nums, int target)
{
	std::unordered_map <int, int> map;
	for (int i = 0; i < nums.size(); i++){
		auto iter = map.find(target - nums[i]);
		if (iter != map.end()){
			return{ iter->second, i };
		}
		map.insert(pair<int, int>(nums[i], i));
	}
	return{};
}

bool Solution::isAnagram(string s, string t)
{
	int record[26] = { 0 };
	for (int i = 0; i < s.size(); i++){
		// 并不需要记住字符a的ASCII，只需要求出一个相对数值就可以了
		record[s[i] - 'a']++;
	}
	for (int i = 0; i < t.size(); i++){
		record[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++){
		if (record[i] != 0){
			// record数组如果有的元素不为零，说明字符串s和t 一定是哪个多了字符或者哪个少了字符
			return false;
		}
	}
	// record数组所有元素都为0，说明字符串s和t是字母异位词
	return true;
}

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> result_set;	// 存放结果
	unordered_set<int> nums_set(nums1.begin(), nums1.end());

	for (int num : nums2){
		// 发现nums2的元素 在nums_set里又出现过
		if (nums_set.find(num) != nums_set.end()){
			result_set.insert(num);
		}
	}
	return vector<int>(result_set.begin(), result_set.end());
}

// 双指针法
vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	// 找出 a + b + c = 0
	// a = nums[i], b = nums[left], c = nums[right]
	for (int i = 0; i < nums.size(); i++){
		// 排序之后如果第一个元素已经大于0，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
		if (nums[i] > 0){
			return result;
		}
		// 正确去重方法
		if (i > 0 && nums[i] == nums[i - 1]){
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		while (right > left){
			if (nums[i] + nums[left] + nums[right] > 0){
				right--;
			}
			else if (nums[i] + nums[left] + nums[right] < 0){
				left++;
			}
			else{
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				// 去重逻辑应该放在找到一个三元组之后
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1])
					left++;

				// 找到答案时，双指针同时收缩
				right--;
				left++;
			}
		}
	}
	return result;
}

//-------------0017.电话号码的字母组合--------------------
vector<string> result;
const string letterMap[10] = {
	"",		// 0
	"",		// 1
	"abc",	// 2
	"def",	// 3
	"ghi",	// 4
	"jkl",	// 5
	"mno",	// 6
	"pqrs",	// 7
	"tuv",	// 8
	"wxyz",	// 9
};
void getCombinations(const string& digits, int index, const string& s)
{
	if (index == digits.size()){
		result.push_back(s);
		return;
	}
	int digit = digits[index] - '0';
	string letters = letterMap[digit];
	for (int i = 0; i < letters.size(); i++){
		getCombinations(digits, index + 1, s + letters[i]);
	}
}
vector<string> Solution::letterCombinations(string digits)
{
	if (digits.size() == 0){
		return result;
	}
	getCombinations(digits, 0, "");
	return result;
}
//--------------------------------------------------------


//-------------------0018.四数之和------------------------
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); k++){
		// 去重
		if (k > 0 && nums[k] == nums[k - 1]){
			continue;
		}
		for (int i = k + 1; i < nums.size(); i++){
			// 正确去重方法
			if (i > k + 1 && nums[i] == nums[i - 1]){
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left){
				if (nums[k] + nums[i] + nums[left] + nums[right] > target){
					right--;
				}
				else if (nums[k] + nums[i] + nums[left] + nums[right] < target){
					left--;
				}
				else{
					result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;

					right--;
					left++;
				}
			}
		}
	}
	return result;
}
//--------------------------------------------------------


