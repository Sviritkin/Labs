//Constructors and destructors

#include <iostream>

using namespace std;


//item type
enum class TypeElement
{
    one, two
};

//element data
union Data
{
    int value; //number
    const char* svalue; //string

    Data() : value(0) {}
};

//element of the second type
struct ElementTwo
{
    Data data;
    TypeElement te;
    ElementTwo* next;

    //constrictors
    ElementTwo(int value, ElementTwo* next) : te(TypeElement::one), next(next)
    {
        data.value = value;
        cout << "Created element two. Value: " << data.value << endl;
    }

    //destructor
    ~ElementTwo()
    {
        freeTwo(&next);
        next = nullptr;
        cout << "Deleted element two. Value: " << data.value << endl;
    }

private:

    //recursively deletes an object
    void freeTwo(ElementTwo** two)
    {
        if (*two)freeTwo(&(*two)->next);
        else
            return;
        delete* two;
        *two = nullptr;
    }
};

//element of the first type
struct ElementOne
{
    Data data;
    TypeElement te;
    ElementOne* left; //pointers to the left and right elements
    ElementTwo* right;

    //constructors
    ElementOne(int value, ElementOne* l, ElementTwo* r) : te(TypeElement::two), left(l), right(r)
    {
        data.value = value;
        cout << "Created element one. Value: " << data.value << endl;
    }

    //destructor
    ~ElementOne()
    {
        delete right;
        right = nullptr;
        freeOne(&left);
        cout << "Deleted element one. Value: " << data.value << endl;
    }

private:

    //recursively deletes an object
    void freeOne(ElementOne** one)
    {
        if (*one)freeOne(&(*one)->left);
        else
            return;
        delete* one;
        *one = nullptr;
    }
};


int main()
{
    //creating objects
    ElementOne* root = new ElementOne(0,
                                      new ElementOne(1,
                                              new ElementOne(2,
                                                      new ElementOne(3, nullptr, nullptr),
                                                      new ElementTwo(4, nullptr)),
                                              new ElementTwo(5,
                                                      new ElementTwo(6, nullptr))),
                                      new ElementTwo(7,
                                              new ElementTwo(8,
                                                      new ElementTwo(9, nullptr))));
    cout << endl;


    //testing
    cout << root->data.value << " " << root->left->data.value << " " << root->right->next->next->data.value << endl << endl;

    //deleting objects
    delete root;

    return 0;
}
