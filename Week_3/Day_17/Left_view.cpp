if (!root)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element
            // at the level
            if (i == 1)
                cout<<temp->data<<" ";
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }