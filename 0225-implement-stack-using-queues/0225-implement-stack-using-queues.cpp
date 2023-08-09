class MyStack {
private:
    std::vector<int> stack;  // Using a vector to store the stack elements

public:
    MyStack() {
        // Constructor
    }

    void push(int x) {
        stack.push_back(x);  // Add element to the end of the vector
    }

    int pop() {
        if (!stack.empty()) {
            int topElement = stack.back();  // Get the last element
            stack.pop_back();  // Remove the last element
            return topElement;
        }
        return -1;  // Indicate an empty stack with a sentinel value
    }

    int top() {
        if (!stack.empty()) {
            return stack.back();  // Return the last element without removing it
        }
        return -1;  // Indicate an empty stack with a sentinel value
    }

    bool empty() {
        return stack.empty();  // Return true if the stack is empty, false otherwise
    }
};