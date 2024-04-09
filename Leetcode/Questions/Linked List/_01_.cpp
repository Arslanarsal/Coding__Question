class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;
    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = onehead->next ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = nullptr;
    Node *head =  zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}