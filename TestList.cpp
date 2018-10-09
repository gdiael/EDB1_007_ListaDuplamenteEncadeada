//
//  TestList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "TestList.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

bool test_InsertBegin()
{
    cout << "INÍCIO: Teste InsertBegin" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista->getQuantity();
        
        string valorInserido = v[i];
        
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste InsertBegin: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = lista->insertBegin( valorInserido );
        if( !inseriu )
        {
            cerr << "\tERRO - Teste InsertBegin: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        Node<string>* primeiroElemento = lista->getHead()->getNext();
        if( primeiroElemento == NULL )
        {
            cerr << "\tERRO - Teste InsertBegin: ponteiro para o primeiro elemento retornou nulo." << endl;
            resultado = false;
            break;
        }
        
        string primeiroValor = primeiroElemento->getValue();
        
        if( primeiroValor != valorInserido )
        {
            cerr << "\tERRO - Teste InsertBegin: valor inserido foi '" << valorInserido << "' e o valor encontrado no início foi " << primeiroValor << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste InsertBegin: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste InsertBegin" << endl << endl;
    
    return resultado;
}


bool test_InsertEnd()
{
    cout << "INÍCIO: Teste InsertEnd" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista->getQuantity();
        
        string valorInserido = v[i];
        
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK)
        {
            cerr << "\tERRO - Teste InsertEnd: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = lista->insertEnd( valorInserido );
        if( !inseriu )
        {
            cerr << "\tERRO - Teste InsertEnd: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        Node<string>* ultimoElemento = lista->getTail()->getPrevious();
        if( ultimoElemento == NULL )
        {
            cerr << "\tERRO - Teste InsertEnd: ponteiro para o último elemento não deveria retornar nulo." << endl;
            resultado = false;
            break;
        }
        
        string ultimoValor = ultimoElemento->getValue();
        
        if( ultimoValor != valorInserido )
        {
            cerr << "\tERRO - Teste InsertEnd: valor inserido foi '" << valorInserido << "' e o valor encontrado no fim foi " << ultimoValor << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste InsertEnd: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste InsertEnd" << endl << endl;
    return resultado;
}
bool test_Insert()
{
    cout << "INÍCIO: Teste Insert" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    lista->insert( 1, v[0] );
    
    for(int i = 1; i < 10; i++)
    {
        int tamanhoAntes = lista->getQuantity();
        
        string valorInserido = v[i];
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste Insert: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = lista->insert(indice, valorInserido);
        if( !inseriu )
        {
            cerr << "\tERRO - Teste Insert: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        string valorRetornado = lista->get(indice);
        
        if( valorRetornado != valorInserido )
        {
            cerr << "\tERRO - Teste Insert: valor inserido na posição " << indice << " foi '" << valorInserido << "' e o valor retornado desta posição foi " << valorRetornado << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste Insert: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste Insert" << endl << endl;
    
    return resultado;
}

bool test_RemoveBegin()
{
    cout << "INÍCIO: Teste RemoveBegin" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        string valorInserido = v[i];
        lista->insertBegin( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste RemoveBegin: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->getQuantity();
        string valorRemovido = lista->removeBegin();
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste RemoveBegin: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        string valorEsperado = v[9-i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste RemoveBegin: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste RemoveBegin" << endl << endl;
    
    return resultado;
}

bool test_RemoveEnd()
{
    cout << "INÍCIO: Teste RemoveEnd" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        string valorInserido = v[i];
        lista->insertEnd( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste RemoveEnd: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->getQuantity();
        string valorRemovido = lista->removeEnd();
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste RemoveEnd: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        string valorEsperado = v[9-i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste RemoveEnd: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste RemoveEnd" << endl << endl;
    
    return resultado;
}

bool test_Remove()
{
    cout << "INÍCIO: Teste Remove" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        string valorInserido = v[i];
        lista->insertEnd( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste Remove: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->getQuantity();
        string valorRemovido = lista->remove(1);
        int tamanhoDepois = lista->getQuantity();
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste Remove: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        string valorEsperado = v[i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste Remove: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste Remove" << endl << endl;
    
    return resultado;
}

bool test_Search()
{
    cout << "INÍCIO: Teste Search" << endl;
    
    bool resultado = true;
    
    LinkedList* lista = new LinkedList();
    
    string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        string valorInserido = v[i];
        lista->insertEnd(valorInserido);
    }
    
    for(int i = 0; i < 10; i++)
    {
        string valorBuscado = v[i];
        int indiceRetornado = lista->search(valorBuscado);
        if( indiceRetornado != i+1 )
        {
            cerr << "\tERRO - Teste Search: buscou a chave " << v[i] << " e deveria ter retornado índice "<< i+1 << ", mas retornou índice igual a " << indiceRetornado << endl;
            resultado = false;
            break;
        }
        
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste Search: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
    }
    
    string inexistentes[] = {"0", "50", "100", "200"};
    
    for(int i = 0; i < 4; i++)
    {
        int indiceRetornado = lista->search(inexistentes[i]);
        if( indiceRetornado != -1 )
        {
            cerr << "\tERRO - Teste Search: buscou chave inexistente e não retornou -1." << endl;
            resultado = false;
            break;
        }
        
        ListStatus verificada = lista->checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste Search: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
    }
    
    delete lista;
    
    cout << "FIM: Teste Search" << endl << endl;
    
    return resultado;
}
