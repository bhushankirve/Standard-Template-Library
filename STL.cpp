////////////////////////////////////////////////////////////////
//
//	Author : Bhushan Santosh Kirve
//	Name : Standard Template Libaray
//
///////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////
//
//	Code for Singly LinkedList
////////////////////////////////////////////////////////////


template <typename T>
struct nodesl
{
	T data;
	struct nodesl* next;
};

template <class T>
class singlyLL
{
private:

	nodesl<T> * first;
	int size;

public:
	singlyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);

	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

	void Display();
	int Count();


};

template <class T>
singlyLL<T>::singlyLL()
	{
		first=NULL;
		size=0;
	}

	template <class T>
	void singlyLL <T> ::InsertFirst(T no)
	{
		nodesl<T>* newn=new nodesl<T>; // its like malloc in c-programming

		newn->data=no;
		newn->next=NULL;

		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		size++;
	}

	template <class T>
	void singlyLL<T>::InsertLast(T no)
	{

		nodesl<T>* newn=new nodesl<T>; // its like malloc in c-programming

		newn->data=no;
		newn->next=NULL;

		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			nodesl<T>* temp=first;

			while(temp->next !=NULL)
			{
				temp=temp->next;

			}
			temp->next=newn;
		}
		size++;
	}

	template <class T>
	void singlyLL<T>::InsertAtPos(T no, int pos)
	{
        if((pos < 1) || (pos > (size+1)))
        {
            return;
        }
        
        if(pos ==1)
        {
            InsertFirst(no);
        }
        else if(pos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            nodesl<T>* newn = new nodesl <T>;
            
            newn->data = no;
            newn->next = NULL;
            
            nodesl<T>* temp = first;
            
            for(int i = 1; i < pos-1; i++)
            {
                temp = temp->next;
            }
            
            newn->next = temp->next;
            temp->next = newn;
            
            size++;
        }

	}

	template <class T>
	void singlyLL<T>::DeleteFirst()
	{
		nodesl<T>* temp =first;

		if(first!=NULL)
		{
			first=first->next;
			delete temp;
		
		size--;
		}
	}

	template <class T>
	void singlyLL<T>::DeleteLast()
	{
		nodesl<T>* temp=first;

		if(first==NULL)
		{
			return;
		}
		else if(first->next==NULL)
		{
			delete first;
			first=NULL;
			size--;
		}
		else
		{
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			size--;
		}
	}


	template <class T>
	void singlyLL<T>::DeleteAtPos(int pos)
	{
        if((pos < 1) || (pos > size))
        {
            return;
        }
        
        if(pos ==1)
        {
            DeleteFirst();
        }
        else if(pos == size)
        {
            DeleteLast();
        }
        else
        {
            nodesl<T>* temp = first;
            for(int i = 1; i < pos-1; i++)
            {
                temp = temp->next;
            }
            
            nodesl<T>* targated = temp->next;
            
            temp->next = targated->next;   
            delete targated;
            
            size--;
        }
        
    }

    template <class T>
	void singlyLL<T>::Display()
	{
		nodesl<T>* temp=first;

		while(temp!=NULL)
		{
		cout<<"|"<<temp->data<<"|-> ";
		temp=temp->next;	
		}
		cout<<"NULL\n";
	}

	template <class T>
	int singlyLL<T>::Count()
	{
		return size;
	}

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//
//	Code for Singly Circular LinkedList
/////////////////////////////////////////////////////////////


template <typename T>
struct nodesc
{
    T data;
    struct nodesc *next;
};

template <class T>
class SinglyCL
{
private:
    nodesc <T> * first;
    nodesc <T> * last;
    int size;
    
public:
	SinglyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
};
	template <class T>
    SinglyCL <T> ::SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
    template <class T>
    void SinglyCL <T> :: Display()
    {
        nodesc <T> * temp  = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp != last->next);
        
        cout<<"NULL\n";
    }
    
    template <class T>
    int SinglyCL <T> ::Count()
    {
        return size;
    }
    
    template <class T>
    void SinglyCL <T> ::InsertFirst(T no)
    {
        nodesc <T> * newn = new nodesc <T>;
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
        last->next = first;
        size++;
    }
    
    template <class T>
    void SinglyCL <T> ::InsertLast(T no)
    {
        nodesc <T> * newn = new nodesc <T>;
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        
        last->next = first;
        size++;
    }
    
    template <class T>
    void SinglyCL <T> ::InsertAtPos(T no, int ipos)
    {
	    if((ipos < 1) || (ipos > (size+1)))
        {
            return;
        }

        if(ipos ==1)
        {
            InsertFirst(no);
        }
        else if(ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            nodesc <T> * newn = new nodesc <T>;

            newn->data = no;
            newn->next = NULL;

            nodesc <T> * temp = first;

            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            size++;
        }

    }
    
    template <class T>
    void SinglyCL <T> ::DeleteFirst()
    {
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
        size--;
    }
    
    template <class T>
    void SinglyCL <T> ::DeleteLast()
    {
        nodesc <T> * temp = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;
                
            last->next = first;
        }
        size--;
    }
    
    template <class T>
    void SinglyCL <T> ::DeleteAtPos(int ipos)
    {
	     if((ipos < 1) || (ipos > size))
        {
            return;
        }

        if(ipos ==1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            nodesc <T> * temp = first;
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }

            nodesc <T> * targated = temp->next;

            temp->next = targated->next;    // temp->next = temp->next->next;
            delete targated;

            size--;
        }

    }




/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//
//	Code for Doubly Linear Linkedlist
///////////////////////////////////////////////////////////////////


template <typename T>
struct nodedl
{
	T data;
	struct nodedl *next;
	struct nodedl *prev;
};

template <class T>
class DoublyLL
{
	private:
		nodedl<T>* first;
		nodedl<T>* last;
		int size;

public:
	DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);

	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

	void Display();
	int Count();
};

template <class T>
DoublyLL<T>::DoublyLL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}

	template <class T>
	void DoublyLL<T>::InsertFirst(T no)
	{
		nodedl<T>* newn=new nodedl<T>; // its like malloc in c-programming

		newn->data=no;
		newn->prev=NULL;
		newn->next=NULL;

		if(first==NULL && last==NULL)
		{
			first=newn;
		}
		else
		{

			first->prev=newn;
			newn->next=first;
			first=newn;
		}
		size++;
	}

	template <class T>
	void DoublyLL<T>::InsertLast(T no)
	{

		nodedl<T>* newn=new nodedl<T>; // its like malloc in c-programming

		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;

		if((first==NULL) &&(last==NULL))
		{
			first=newn;
		}
		else
		{
			nodedl<T>* temp=first;

			while(temp->next !=NULL)
			{
				temp=temp->next;

			}
			temp->next=newn;
			newn->prev=temp;
		}
		size++;
	}

	template <class T>
	void DoublyLL<T>::InsertAtPos(T no, int pos)
	{
        if((pos < 1) || (pos > (size+1)))
        {
            return;
        }
        
        if(pos ==1)
        {
            InsertFirst(no);
        }
        else if(pos == size+1)
        {
            InsertLast(no);
        }
        else
        {
        	nodedl<T>* temp=first;
            nodedl<T>* newn = new nodedl<T>;
            
            newn->data = no;
            newn->next = NULL;
            newn->prev=NULL;
           
            
            for(int i = 1; i < pos-1; i++)
            {
                temp = temp->next;
            }
            
            newn->next=temp->next;
			temp->next->prev=newn;
			newn->prev=temp;
			temp->next=newn;
            
            size++;
        }

	}

	template <class T>
	void DoublyLL<T>::DeleteFirst()
	{
		
		nodedl<T>* temp=first;
		if(first==NULL)
		{
			return;
		}
		else
		{
			first=first->next;
			first->prev=NULL;
			delete first->prev;
		
		size--;
		}
	}

	template <class T>
	void DoublyLL<T>::DeleteLast()
	{
		

		if((first==NULL) &&(last==NULL))
		{
			return;
		}
		else if(first->next==NULL)
		{
			delete first;
			first=NULL;
			last=NULL;
			size--;
		}
		else
		{
			nodedl<T>* temp=first;

			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			size--;
		}
	}


	template <class T>
	void DoublyLL<T>::DeleteAtPos(int pos)
	{
        if((pos < 1) || (pos > size))
        {
            return;
        }
        
        if(pos ==1)
        {
            DeleteFirst();
        }
        else if(pos == size)
        {
            DeleteLast();
        }
        else
        {
            nodedl<T>* temp = first;
            for(int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            
            size--;
        }
        
    }

    template <class T>
	void DoublyLL<T>::Display()
	{
		nodedl<T>* temp=first;

		while(temp!=NULL)
		{
		cout<<"|"<<temp->data<<"|-> ";
		temp=temp->next;	
		}
		cout<<"NULL\n";
	}

	template <class T>
	int DoublyLL<T>::Count()
	{
		return size;
	}





////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//
//	Code for Doubly Circular LinkedList
/////////////////////////////////////////////////////////////



template <typename T>
struct nodedc
{
    T data;
    nodedc <T> *next;
    nodedc <T> *prev;
};

template <class T>
class DoublyCL
{
private:
    nodedc <T> * first;
    nodedc <T> * last;
    int size;
    
public:
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

// Return_Value Class_Name :: Fnuction_Name(Parameters)

template <class T>
DoublyCL <T> :: DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    

template <class T>
void DoublyCL  <T> :: InsertFirst(T no)
{
    nodedc <T> * newn = new nodedc <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL <T> :: InsertLast(T no)
{
    nodedc <T> * newn = new nodedc <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL <T> :: Display()
{
    nodedc  <T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyCL <T> :: Count()
{
    return size;
}

template <class T>
void DoublyCL <T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL <T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class T>
void DoublyCL <T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        nodedc <T> * newn= new nodedc <T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        nodedc <T> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}

template <class T>
void DoublyCL <T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        nodedc <T> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}
int main()
{


	singlyLL <int>slobj;
	int iret=0;

	slobj.InsertFirst(51);
	slobj.InsertFirst(21);
	slobj.InsertFirst(11);
	
	slobj.InsertLast(101);

	slobj.Display();

	iret=slobj.Count();
	cout<<"Number of elements:"<<iret<<"\n";

	
	slobj.DeleteFirst();
	slobj.DeleteLast();
	slobj.Display();

	iret=slobj.Count();
	cout<<"Number of elements:"<<iret<<"\n";
///////////////////////////////////////////////////////


    SinglyCL<int> scobj;
   
    
    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    
    scobj.InsertLast(101);
    
    scobj.Display();
    iret = scobj.Count();
    cout<<"Number of elements are : "<<iret<<"\n";
    
    scobj.DeleteFirst();
    slobj.DeleteLast();
    
    scobj.Display();
    iret = scobj.Count();
    cout<<"Number of elements are : "<<iret<<"\n";
    
 /////////////////////////////////////////////////////////////
 
	

	DoublyLL <char>dlcobj;
	
	dlcobj.InsertFirst('A');
	dlcobj.InsertFirst('B');
	dlcobj.InsertFirst('C');
	
	dlcobj.InsertLast('D');

	dlcobj.Display();

	iret=dlcobj.Count();
	cout<<"Number of elements:"<<iret<<"\n";


	DoublyLL <int>dliobj;
	
	dliobj.InsertFirst(11);
	dliobj.InsertFirst(21);
	dliobj.InsertFirst(31);
	
	dliobj.InsertLast(41);

	dliobj.Display();

	iret=dliobj.Count();
	cout<<"Number of elements:"<<iret<<"\n";

//////////////////////////////////////////////////
 
    DoublyCL <int> dcobj;
    
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    
    dcobj.InsertLast(51);
    dcobj.InsertLast(101);
    
    dcobj.InsertAtPos(75,3);
    dcobj.Display();
    
    iret = dcobj.Count();
    cout<<"Number of elements are : "<< iret<<"\n";
    
    dcobj.DeleteAtPos(3);
    dcobj.DeleteFirst();
    dcobj.DeleteLast();
    
    dcobj.Display();
    ///////////////////////////////////////////////////////
    return 0;
}
