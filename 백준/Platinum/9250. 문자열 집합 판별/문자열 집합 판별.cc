//해당 코드는 https://m.blog.naver.com/kks227/220992598966의 게시물을 공부한 후 작성한 코드임을 명시합니다
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
bool ans;
struct Trie {
	Trie* go[26];
	Trie* fail;
	bool found = false;
	Trie() {
		memset(go, 0, sizeof(go));
		fail = nullptr;
	}
	~Trie() {
		for (int i = 0;i < 26;++i) if (go[i]) delete(go[i]);
	}
	void insert(string key, int nth) {
		if (nth == key.size()) {
			found = true;
			return;
		}
		int next = key[nth] - 'a';
		if (!go[next]) {
			go[next] = new Trie();
		}
		go[next]->insert(key, nth + 1);
	}
};
vector<string> S, T;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	S.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> S[i];
	}
	cin >> M;
	T.resize(M);
	for (int i = 0;i < M;++i) {
		cin >> T[i];
	}
	Trie* root = new Trie;
	for (int i = 0;i < N;++i) {
		root->insert(S[i], 0);
	}
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while (!Q.empty()) {
		Trie* cur = Q.front();
		Q.pop();
		for (int i = 0;i < 26;++i) {
			Trie* next = cur->go[i];
			if (!next) continue;
			if (cur == root) next->fail = root;
			else {
				Trie* par = cur->fail;
				while (par != root && !par->go[i]) par = par->fail;
				if (par->go[i]) par = par->go[i];
				next->fail = par;
			}
			if (next->fail->found) next->found = true;
			Q.push(next);
		}
	}
	for (int q = 0;q < M;++q) {
		Trie* cur = root;
		ans = false;
		for (int i = 0;i < T[q].size();++i) {
			int next = T[q][i] - 'a';
			while (cur != root && !cur->go[next]) {
				cur=cur->fail;
			}
			if (cur->go[next]) cur = cur->go[next];
			if (cur->found) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
	delete root;
}