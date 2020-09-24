#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

class Solution{
private:
	//const string letterMap[10] = {
	//	"",		// 0
	//	"",		// 1
	//	"abc",	// 2
	//	"def",	// 3
	//	"ghi",	// 4
	//	"jkl",	// 5
	//	"mno",	// 6
	//	"pqrs",	// 7
	//	"tuv",	// 8
	//	"wxyz",	// 9
	//};
public:
	// O(n)
	void function1(long long n);

	// O(n^2)
	void function2(long long n);

	// O(nlogn)
	void function3(long long n);

	// Test function1, function2 and function3
	void TestFunction();

	/*	0349.两个数组的交集	2020-09-23
		给定两个数组，编写一个函数来计算它们的交集
		示例1:
		输入: nums1 = [1,2,2,1], nums2 = [2,2]
		输出: [2]
		示例2:
		输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
		输出: [9,4]
	*/
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);


	/*	0242.有效的字母异位词 2020-09-23
		给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词
		示例1:
		输入: s = "anagram", t = "nagaram"
		输出: true
		示例2:
		输入: s = "rat", t = "car"
		输出: false
	*/
	bool isAnagram(string s, string t);


	/*	0020.有效的括号	2020-09-24
		
	*/


	/*	0018.四数之和	2020-09-24
		给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
		示例：
		给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
		满足要求的四元组集合为：
		[ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
	*/
	vector<vector<int>> fourSum(vector<int>& nums, int target);


	/*	0017.电话号码的字母组合	2020-09-24
		给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母
		示例:
		输入："23"
		输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	*/
	vector<string> letterCombinations(string digits);


	/*	0015.三数之和	2020-09-24
		给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组
		示例：
		给定数组 nums = [-1, 0, 1, 2, -1, -4]，
		满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
	*/
	vector<vector<int>> threeSum(vector<int>& nums);


	/*	0001.两数之和  2020-09-23
		给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
		示例:
		给定 nums = [2, 7, 11, 15], target = 9
		因为 nums[0] + nums[1] = 2 + 7 = 9
		所以返回 [0, 1]
	*/
	vector<int> twoSum0(vector<int>& nums, int target);	// 一般解法
	vector<int> twoSum1(vector<int>& nums, int target);	// 优化解法1
	vector<int> twoSum2(vector<int>& nums, int target);	// 优化解法2
};

#endif
