//Main function - builds the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    /*
        Step 1: Create a min heap of capacity = size.
                Initially, there are modes = size
                num node = num of data we have
    */
   struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

   /*
    Iterate while size of heap doesn't become 1
    If its one, then we have successfully build our huffman tree and stop 
   */
   while(!isSizeOne(minHeap))
   {
       //Step 2: Extract the 2 min freq items from min heap
       left = extractMin(minHeap);
       right = extractMin(minHeap);

       /*
        Step 3: Create a new internal node w/ freq = sum of 2 nodes freq
                Make the 2 extracted node as left & right children of this
                    new node
                + this node to the min heap

        $ is a speacial value for internal nodes, not used
       */
      top = newNode('$', left->freq + right->freq)

      top->left = left;
      top->right = right;

      insertMinHeap(minHeap, top);  //Add into the min heap
   }

   /*
    Step 4: The remaining node is the root node and the tree is complete
                root node and tree is complete
   */
    return extractMin(minHeap);
}

/*
    Prints huffman codes from the root of Huffman Tree
    Uses arr[] to store codes
*/
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    //Assign 0 to left edge and recur
    if(root->left)
    {
        arr[top] = 0L;
        printCodes(root->left, arr, top + 1);
    }

    //Assigne 1 to the right edge and recur
    if(root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1)
    }

    /*
        If leaf node
            contains 1 of the input chars
            print the char and its code from arr[]
    */   
   if(isLeaf(root))
   {
       printf("%c: ", root->data);
       printArr(arr, top);
   }
}

/*
    Acts like the main function that builds a Huffman Tree and print codes
        by traversing the built Huffman Tree
*/
void HuffmanCodes(char data[], int freq[], int size)
{
    //Construct Huffman Tree
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);


    //Print Huffman codes using the Huffman tree build above
    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}