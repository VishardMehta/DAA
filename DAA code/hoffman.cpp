#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct node {
    char ch;
    int freq;
    node *left, *right;
    
    node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct cmp {
    bool operator()(node* a, node* b) {
        return a->freq > b->freq;
    }
};

void make_codes(node* root, string code, unordered_map<char, string> &codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }

    make_codes(root->left, code + "0", codes);
    make_codes(root->right, code + "1", codes);
}

string encode(string s, unordered_map<char, string> &codes) {
    string enc = "";
    for (char c : s) {
        enc += codes[c];
    }
    return enc;
}

string decode(string enc, node* root) {
    string dec = "";
    node* curr = root;
    for (char bit : enc) {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            dec += curr->ch;
            curr = root;
        }
    }
    return dec;
}

int main() {
    string str;
    cout << "enter string: ";
    getline(cin, str);

    unordered_map<char, int> freq;
    for (char c : str) freq[c]++;

    priority_queue<node*, vector<node*>, cmp> pq;

    for (auto it : freq) {
        pq.push(new node(it.first, it.second));
    }

    while (pq.size() > 1) {
        node* l = pq.top(); pq.pop();
        node* r = pq.top(); pq.pop();

        node* m = new node('$', l->freq + r->freq);
        m->left = l;
        m->right = r;

        pq.push(m);
    }

    node* root = pq.top();

    unordered_map<char, string> codes;
    make_codes(root, "", codes);

    cout << "\nhuffman codes:\n";
    for (auto it : codes) {
        cout << it.first << " : " << it.second << endl;
    }

    string encoded = encode(str, codes);
    cout << "\nencoded string: " << encoded << endl;

    string decoded = decode(encoded, root);
    cout << "decoded string: " << decoded << endl;

    return 0;
}
