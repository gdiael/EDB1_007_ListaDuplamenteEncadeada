//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    // TO-DO
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

string LinkedList::get(int i)
{
    if( i < 1 || i > this->getQuantity())
    {
        std::cout << "Valor do índice de busca deve estar entre [1, quantity].\n";
        return "";
    }
	if( this->isEmpty() )
	{
		std::cout << "Não há elementos a serem retornados, pois lista está vazia.\n";
        return "";
	}
		
    int counter = 1;
    
    string result;
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( i == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;
}

int LinkedList::search(string s)
{
	std::cout << "\tERRO - Método search ainda não foi implementado.\n";
    return -1;
}

bool LinkedList::insertBegin(string s)
{
   	std::cout << "\tERRO - Método insertBegin ainda não foi implementado.\n";
    return false;
}

bool LinkedList::insertEnd(string s)
{
	std::cout << "\tERRO - Método insertEnd ainda não foi implementado.\n";
    return false;
}

bool LinkedList::insert(int i, string s)
{
    std::cout << "\tERRO - Método insert ainda não foi implementado.\n";
    return false;
}

string LinkedList::removeEnd(void)
{
    std::cout << "\tERRO - Método removeEnd ainda não foi implementado.\n";
    return "";
}

string LinkedList::removeBegin(void)
{
    std::cout << "\tERRO - Método removeBegin ainda não foi implementado.\n";
    return "";
}

string LinkedList::remove(int indice)
{
    std::cout << "\tERRO - Método remove ainda não foi implementado.\n";
    return "";
}

void LinkedList::print(void)
{
	for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
	if( this->head == NULL )
	{
		return HeadNull;
	}
	else if( this->head->getNext() == NULL )
	{
		return HeadNextNull;
	}
	else if( this->head->getNext()->getPrevious() != this->head )
	{
		return IncorrectLink;
	}
	else if( this->head->getPrevious() != NULL )
	{
		return HeadPrevious;
	}
	
	if( this->tail == NULL )
	{
		return TailNull;
	}
	else if( this->tail->getPrevious() == NULL )
	{
		return TailPreviousNull;
	}
	else if( this->tail->getPrevious()->getNext() != this->tail )
	{
		return IncorrectLink;
	}
	else if( this->tail->getNext() != NULL )
	{
		return TailNext;
	}
	
	if(this->isEmpty())
	{
		if( this->head->getNext() != this->tail )
		{
			return HeadTail;
		}
		
		if( this->head != this->tail->getPrevious() )
		{
			return HeadTail;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
		{
			if( i->getNext()->getPrevious() != i )
			{
				return IncorrectLink;
			}
			if( i->getPrevious()->getNext() != i )
			{
				return IncorrectLink;
			}
		}
	}
	
	return OK;
}
