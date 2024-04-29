```
class Solution {
    public:
    Node* deleteK(Node *head,int K){
    
        if(head == NULL || K==1)
            return NULL;
            
        Node* prev = nullptr;
        Node* curr = head;
        
        int cnt = 0;
        while(curr != nullptr)
        {
          cnt++;
          if(cnt%K==0)
          {
              Node* temp = curr->next;
              prev->next = temp;
              curr=temp;
          }
          else
          {
              prev = curr;
              curr = curr->next;
          }
        }
        return head;
    }
};
```
