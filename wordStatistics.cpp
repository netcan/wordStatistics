/*************************************************************************
	> File Name: wordStatistics.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 Thu 16:24:00 CST
 ************************************************************************/

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
			traverse(root);
		}
		~wordTree() {
			free(root);
		}
};

void wordTree::traverse(Trie *p) {
	if(p == NULL) return;
	if(p->isEnd)
		printf("%s(%d/%d)\n", tmp.c_str(), p->times, count);

	for (int i = 0; i < charaN; ++i) {
		if(p->next[i]) {
			tmp.push_back(i);
			traverse(p->next[i]);
			tmp.pop_back();
		}
	}
}

void wordTree::add(const string &str) {
	if(str.length() == 0) return;
	Trie *p = this->root, *q;
	for(size_t i = 0; i<str.length(); ++i) {
		int id = str[i];
		if(p->next[id] == NULL) {
			q = new Trie();
			p->next[id] = q;
		}
		p = p->next[id];
	}
	++(p->times);
	++count;
	// printf("%s(%d)\n", str.c_str(), p->times);
	p->isEnd = true;
}

bool wordTree::acceptChar(const char &c) const{
	return isalpha(c) || c=='-' || c=='\'';
}

void wordTree::addLine(const string &str) { // 从一行字符串中提取添加
	unsigned int cur = 0;
	while(cur < str.length()) {
		while(! acceptChar(str[cur]) && cur < str.length()) ++cur;
		unsigned int end = cur;
		while(acceptChar(str[end]) && end < str.length()) ++end;
		string t = str.substr(cur, end-cur);
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		add(t);
		cur = end;
	}
}

int wordTree::find(const string &str) const {
	Trie *p = this->root;
	for(size_t i = 0; i<str.length(); ++i) {
		int id = str[i];
		if(id < 0 || id > charaN || (p = p->next[id]) == NULL) return -1;
	}
	if(p && p->isEnd) return p->times;
	return -1;
}

void wordTree::free(Trie *p) {
	if(p == NULL) return;
	for (int i = 0; i < charaN; ++i)
		if(p->next[i]) free(p->next[i]);
	delete p;
}

int main(int argc, char *argv[]) {
	string in;
	wordTree wt;
	while(getline(cin, in)) {
		wt.addLine(in);
	}
	wt.traverse();
	return 0;
}

