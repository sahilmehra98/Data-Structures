/*
Given a generic tree, find and return the height of given tree.

Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output Format :
Height

Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output :
3
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int height(TreeNode<int>* root) {
    int ans = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        int childHeight = height(root -> children[i]);
        if(childHeight > ans) {
            ans = childHeight;
        }
    }
    return ans + 1;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << height(root) << endl;
}
