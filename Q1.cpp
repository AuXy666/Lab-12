#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
};

class queue
{
public:
    node* front = NULL;
    node* rear = NULL;
    node* head;
    queue()
    {
        head = NULL;
    }

    int front1()
    {
        return front->data;
    }
    void push(int val)
    {
        node* temp;
        if (rear == NULL)
        {
            rear = new node;
            rear->next = NULL;
            rear->data = val;
            front = rear;
        }
        else
        {
            temp = new node;
            rear->next = temp;
            temp->data = val;
            temp->next = NULL;
            rear = temp;
        }
    }
    void pop()
    {
        node* temp = new node;
        temp = front;
        if (front == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        else
            if (temp->next != NULL) {
                temp = temp->next;

                delete front;
                front = temp;
            }
            else {

                delete front;
                front = NULL;
                rear = NULL;
            }
    }
    void display()
    {
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};
class stack
{
public:
    node* top = NULL;
    stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    int Top()
    {
        return top->data;
    }
    void push(int key)
    {
        node* temp = new node;
        temp->data = key;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (isEmpty() == true)
        {
            return;
            
        }
        else {
            top = top->next;
        }
    }
    void display()
    {
        node* temp = top;
        if (isEmpty() == true)
        {
            cout << endl;
            cout << "Stack is Empty, So Cannot Display" << endl;
        }
        else {
            temp = top;
            cout << endl;
            cout << "Stack = " << endl;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }


    }
};



int main()
{

    int loopInput = 0;
    int N = 0, M = 0;
    int cols = 2;     
    int** array = NULL;
    int** matrix = NULL;
    int** transpose = NULL;
    int** result = NULL;
    queue* l = NULL;
    int x = 0, y = 0;
    while (1)
    {
        cout << "Press 1 to input Vertices and Edges" << endl;
        cout << "Press 2 to Input array" << endl;
        cout << "Press 3 to create Adjacency matrix " << endl;
        cout << "Press 4 to BST" << endl;
        cout << "Press 5 to DST " << endl;
        cout << "Press 6 to end" << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            cout << "Enter Number of Vertices (0-N)= ";
            cin >> N;
            cout << "Enter Number of Edges = ";
            cin >> M;
        }
        else if (loopInput == 2)
        {
            array = new int* [M];
            for (int i = 0; i < M; ++i)
                array[i] = new int[cols];

            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    while (1)
                    {
                        cin >> array[i][j];
                        if (array[i][j] > N)
                        {
                            cout << "Value Entered Greater then Given Vertices, Try Again" << endl;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }


        }
        else if (loopInput == 3)
        {

            matrix = new int* [N + 1];
            for (int i = 0; i < N + 1; ++i)
                matrix[i] = new int[N + 1];


            for (int i = 0; i < N + 1; i++)
            {

                for (int j = 0; j < N + 1; j++)
                {
                    matrix[i][j] = 0;
                }
            }


            for (int i = 0; i < M; i++)
            {

                

                x = array[i][0];
                y = array[i][1];

                matrix[x][y] = 1;
               matrix[y][x] = 1;
            }
            cout << endl;
            cout << "Adjacency Matrix Created Successfully" << endl;

             
            cout << endl;
            cout << "Following is the Required Adjacency Matrix" << endl;

            for (int i = 0; i < N + 1; i++)
            {
                for (int j = 0; j < N + 1; j++)
                {


                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        else if (loopInput == 4)
        {
            int s;
            int temp2;
            cout << "Enter Starting vertex = ";
            cin >> s;
           temp2=s;
            bool checker = false;
            bool* indexChecker = new bool[N + 1];
            for (int i = 0; i < N + 1; i++)
            {
                indexChecker[i] = false;
            }

            queue ste;
            ste.push(s);
            while (ste.front != NULL)
            {
                s = ste.front1();
                cout << s << " ";
        
                checker = false;
                for (int j = 0; j < N + 1; j++)
                {
                    if (matrix[s][j] == 1 && indexChecker[j] == false&& j!=temp2)
                    {
                        ste.push(j);
                        indexChecker[j] = true;
                        checker = true;

                    }


                }
                ste.pop();
            }
            
        }
        else if (loopInput == 5)
        {
            int s;
            cout << "Enter Starting vertex = ";
            cin >> s;
            bool checker = false;
            bool* indexChecker = new bool[N + 1];
            for (int i = 0; i < N + 1; i++)
            {
                indexChecker[i] = false;
            }
            
            stack ste;  
            cout << s << " ";
            ste.push(s);
            for (int i = 0,k=1; k < N + 1;)
            {
                checker = false;
                for (int j = 0; j < N + 1; j++)
                {
                    if (matrix[i][j] == 1 &&indexChecker[j]==false&& s != j)
                    {
                        ste.push(j);
                        cout << j << " ";
                        indexChecker[j] = true;
                        k++;
                        i = j;
                        checker = true;
                        break;
                        
                    }

                    
                }
                if (checker == false)
                {
                     
                    ste.pop();
                    i = ste.Top();
                }
                
            }
        }
        else if (loopInput == 6)
        {
            break;
        }

        cout << endl;
        system("pause");
        system("cls");
    }
    return 0;
}

