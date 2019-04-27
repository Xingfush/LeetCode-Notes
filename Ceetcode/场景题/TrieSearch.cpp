class TrieNode {
public:
	TrieNode* child[26];
	bool isWord;
	/** Initialize your data structure here. */
	TrieNode() {
		for (int i = 0; i<26; i++) child[i] = nullptr;
		isWord = false;
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (auto c : word) {
			int k = c - 'a';
			if (!p->child[k]) p->child[k] = new TrieNode();
			p = p->child[k];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;
		for (auto c : word) {
			if (!p->child[c - 'a']) return false;
			p = p->child[c - 'a'];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (auto c : prefix) {
			if (!p->child[c - 'a']) return false;
			p = p->child[c - 'a'];
		}
		return true;
	}

	/** Returns all the words which are start with the given prefix. */
	vector<string> startsWithPrefix(string prefix) {
		TrieNode* p = root;
		for (auto c : prefix) {
			if (!p->child[c - 'a']) return{ "" };
			p = p->child[c - 'a'];
		}
		vector<string> res;
		string path;
		prefixHelper(p, res, path);
		for (string & s : res)
			s = prefix + s;
		return res;
	}

private:
	TrieNode* root;

	void prefixHelper(TrieNode* root, vector<string>& res, string& path) {
		if (root == nullptr) return;
		if (root->isWord) res.push_back(path);
		for (int i = 0; i < 26; i++) {
			if (root->child[i]) {
				path.push_back(char('a' + i));
				prefixHelper(root->child[i], res, path);
				path.pop_back();
			}
		}
	}
};
