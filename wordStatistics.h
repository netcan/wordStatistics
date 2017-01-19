/*************************************************************************
	> File Name: wordStatistics.h
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 Thu 17:40:00 CST
 ************************************************************************/


#ifndef __wordStatistics_H__
#define __wordStatistics_H__

#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;
const static int charaN = 128;

struct Trie {
	Trie *next[charaN]; // 128个字符
	bool isEnd; // 是否是字母结尾
	unsigned int times = 0; // 重复单词出现次数
	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));
		times = 0;
	}
};

struct wordTree {
	private:
		Trie* root;
		string tmp; // 遍历用的中间变量
		int count; // 单词总数
		void free(Trie *p);
		void traverse(Trie *p);
	public:
		wordTree() {
			count = 0;
			root = new Trie();
		}
		void add(const string &str);
		void addLine(const string &str); // 从一行字符串中提取添加
		bool acceptChar(const char &c) const; // 统计规则
		int find(const string &str) const; // 查找单词，返回次数
		void traverse() { // 遍历输出信息
			tmp = "";
			printf("word,times\n");
			traverse(root);
		}
		~wordTree() {
			free(root);
		}
};
#endif

