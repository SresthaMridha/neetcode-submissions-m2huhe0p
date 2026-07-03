class Node{
public:
    int key, value;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
public:
    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
        
    }

    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insert(Node* node){
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            //update value
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }
        if(mp.size() == capacity){
            Node* node = tail->prev;
            remove(node);
            mp.erase(node->key);
            delete node;
        }
        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};
