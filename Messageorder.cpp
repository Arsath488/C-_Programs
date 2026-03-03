

class Message {
private:
    string text_;
    int id_; // Added to track original order
public: 
    Message() {}
    // Constructor to store text and sequence ID
    Message(const string& text, int id) : text_(text), id_(id) {}
    
    const string& get_text() {
        return text_;
    }

    // Overload < operator for the sort() function in Recipient::fix_order
    bool operator<(const Message& other) const {
        return this->id_ < other.id_;
    }
};

class MessageFactory {
private:
    int current_id = 0; // Internal counter
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        // Increment ID for every new message to preserve order
        return Message(text, current_id++);
    }
};


