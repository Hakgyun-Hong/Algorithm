#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

struct bucket* hashTable = NULL;
int BUCKET_SIZE=10;


// 1: Node Struct
struct Node{
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
};

// 2: Bucket 구조체를 선언해야 hash로 쓸 수 있기 때문에 만들어 준다.
struct bucket{
    struct Node* head;
    int count;
};


// 3: Allocation Node
struct Node* myAlloc(int key,int value)
{
    struct Node* tempNode;
    
    tempNode=(struct Node*) malloc(sizeof(struct Node));
    tempNode->key=key;
    tempNode->value=value;
    tempNode->next = NULL;
    tempNode->prev = NULL;
    
    return tempNode;
}

// 4: Hash Function
int hashFunction(int key)
{
    return key%BUCKET_SIZE;
}

// 5: Add Function
void add(int key, int value)
{
    int hashIndex = hashFunction(key);
    
    struct Node* newNode = myAlloc(key,value);
    
    
    if(hashTable[hashIndex].count==0)
    {
        hashTable[hashIndex].count =1;
        hashTable[hashIndex].head = newNode;
    }
    else{
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}

// 6: Remove Function
void remove_key(int key)
{
    int hashIndex = hashFunction(key);
    
    int flag = 0;
    
    struct Node* node=NULL;
    struct Node* before=NULL;
    
    node = hashTable[hashIndex].head;
    
    while(node != NULL)
    {
        if(node->key == key)
        {
            if(node == hashTable[hashIndex].head)
            {
                hashTable[hashIndex].head = node->next;
                
            }
            else{
                before->next = node->next;
            }
        }
        
        before = node;
        node = node->next;
    }
    
    if(flag==1)
    {
        printf("%d was deleted. \n",key);
    }
    else{
        printf("%d was not deleted. Unfound item \n",key);
    }
}

// 7: Search
void search(int key)
{
    int hashIndex = hashFunction(key);
    
    struct Node* node = hashTable[hashIndex].head;
    int flag = 0;
    while( node != NULL)
    {
        if(node->key == key)
        {
            flag =1;
            break;
        }
        
        node = node->next;
    }
    
    if(flag == 1)
    {
        printf("Key : %d, Value : %d\n",node->key, node->value);
        
    }
    else{
        printf("Unfound Key\n");
    }
}

// 8: Display function
void display(void)
{
    
    struct Node* iterator;
    
    for(int i=0;i<BUCKET_SIZE;++i)
    {
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ",i);
        while(iterator !=NULL)
        {
            printf("(key : %d, value : %d) -> ",iterator->key,iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
}

int main (){
    
    hashTable = (struct bucket*)malloc(BUCKET_SIZE* sizeof(struct bucket));
    
    for(int i=0; i<16; ++i)
    {
        add(i,10*i);
    }
    
    add(21,211);
    add(31,311);
    add(41,411);
    display();
    return 0;
    
}



