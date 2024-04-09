
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{
    Node *dumy = new Node();
    Node *cur = dumy;
    cur->next = head;
    head->prev = cur;
    while (head)
    {
        if (head->data == k)
        {
            Node *del = head;
            cur->next = head->next;
            if (cur->next)
            {
                cur->next->prev = cur;
            }
            delete del;
            head = cur->next;
        }
        else
        {
            cur = head;
            head = head->next;
        }
    }
    if (dumy->next)
    {
        dumy->next->prev = nullptr;
    }
    return dumy->next;
}
