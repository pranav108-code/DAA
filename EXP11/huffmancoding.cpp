#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// Node of Huffman Tree
struct Node {
    char data;
    int frequency;
    Node *left, *right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Compare nodes based on frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Coding function
void huffmanCoding(string text) {

    // Calculate frequency of each character
    unordered_map<char, int> frequency;

    for (char ch : text) {
        frequency[ch]++;
    }

    // Create a min-heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create nodes for each character
    for (auto pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {

        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node(
            '\0',
            left->frequency + right->frequency
        );

        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = minHeap.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Display Huffman Codes
    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Encode the text
    string encodedText = "";

    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }

    cout << "\nOriginal Text: " << text << endl;
    cout << "Encoded Text: " << encodedText << endl;

    cout << "\nOriginal Size: "
         << text.length() * 8 << " bits";

    cout << "\nCompressed Size: "
         << encodedText.length() << " bits";

    cout << "\n";
}

int main() {

    string text;

    cout << "Enter text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Text cannot be empty.";
        return 0;
    }

    huffmanCoding(text);

    return 0;
}