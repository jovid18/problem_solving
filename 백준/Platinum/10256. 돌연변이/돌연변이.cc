#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int T, N, M;
string DNA, MARK;
struct Trie {
	Trie* go[4];
	Trie* fail;
	int found;
	Trie() {
		memset(go, 0, sizeof(go));
		fail = nullptr;
		found = 0;
	}
	~Trie() {
		for (int i = 0;i < 4;++i) if (go[i]) delete(go[i]);
	}
	void insert(string& key, int nth) {
		if (nth == key.size()) {
			found = 1;;
			return;
		}
		int next = key[nth] - 'a';
		if (!go[next]) {
			go[next] = new Trie();
		}
		go[next]->insert(key, nth + 1);
	}
};
void fail(Trie* root) {
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while (!Q.empty()) {
		Trie* cur = Q.front();
		Q.pop();
		for (int i = 0;i < 4;++i) {
			Trie* next = cur->go[i];
			if (!next) continue;
			if (cur == root) next->fail = root;
			else {
				Trie* par = cur->fail;
				while (par != root && !par->go[i])
					par = par->fail;
				if (par->go[i]) par = par->go[i];
				next->fail = par;
			}
			next->found += next->fail->found;
			Q.push(next);
		}
	}
}
int solve(string& s, Trie* root) {
	Trie* cur = root;
	int ans = 0;
	for (int i = 0;i < s.size();++i) {
		int next = s[i] - 'a';
		while (cur != root && !cur->go[next]) {
			cur = cur->fail;
		}
		if (cur->go[next]) cur = cur->go[next];
		ans += cur->found;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M >> DNA >> MARK;
		for (int i = 0;i < N;++i) {
			if (DNA[i] == 'A') DNA[i] = 'a';
			else if (DNA[i] == 'C') DNA[i] = 'b';
			else if (DNA[i] == 'G') DNA[i] = 'c';
			else DNA[i] = 'd';
		}
		for (int i = 0;i < M;++i) {
			if (MARK[i] == 'A') MARK[i] = 'a';
			else if (MARK[i] == 'C') MARK[i] = 'b';
			else if (MARK[i] == 'G') MARK[i] = 'c';
			else MARK[i] = 'd';
		}
		Trie* root = new Trie();
		root->insert(MARK, 0);
		for (int i = 0;i <= M;++i) {
			for (int j = i + 2;j <= M;++j) {
				reverse(MARK.begin() + i, MARK.begin() + j);
				root->insert(MARK,0);
				reverse(MARK.begin() + i, MARK.begin() + j);
			}
		}
		fail(root);
		cout << solve(DNA, root) << '\n';
		delete root;
	}
}