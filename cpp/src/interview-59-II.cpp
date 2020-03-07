struct Node {
    int value;
    Node* next;
};

class MaxQueue {
public:
    MaxQueue() {
        this->head = (Node*)malloc(sizeof(Node));
        this->head->value = -1;

        this->rear = (Node*)malloc(sizeof(Node));
        this->rear->value = -1;
        this->rear->next = NULL;

        this->head->next = this->rear;
    }
    
    int max_value() {
        Node* cur = this->head->next;
        
        int max = -1;
        while (cur->next != NULL) {
            max = max > cur->value ? max : cur->value;
            cur = cur->next;
        }

        return max;
    }
    
    void push_back(int value) {
        Node *node = (Node*)malloc(sizeof(Node));
        node->value = -1;
        node->next = NULL;

        this->rear->value = value;
        this->rear->next = node;

        this->rear = node;
    }
    
    int pop_front() {
        if (this->head->next->next == NULL) return -1;

        this->head = this->head->next;
        
        int value = this->head->value;
        this->head->value = -1;

        return value;
    }

private:
    Node* head;
    Node* rear;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
