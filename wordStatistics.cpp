/*************************************************************************
	> File Name: wordStatistics.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 Thu 16:24:00 CST
 ************************************************************************/

#include "wordStatistics.h"
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

