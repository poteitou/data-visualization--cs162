#include "Screen.hpp"

Screen::Screen(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font), mData(0), mMenu(mWindow, mFont), mStaticArray(mWindow, mFont), mDynamicArray(mWindow, mFont), mSinglyLinkedList(mWindow, mFont), mDoublyLinkedList(mWindow, mFont), mCircularLinkedList(mWindow, mFont), mStack(mWindow, mFont), mQueue(mWindow, mFont)
{
    
}

void Screen::update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, float dt)
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.update(mousePress, mousePosition, mData);
        break;
    case 1: // Static array
        mStaticArray.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 2: // Dynamic array
        mDynamicArray.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 3: // Singly linked list
        mSinglyLinkedList.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 4: // Doubly linked list
        mDoublyLinkedList.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 5: // Circular linked list
        mCircularLinkedList.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 6: // Stack
        mStack.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 7: // Queue
        mQueue.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    default:
        break;
    }
}

void Screen::draw()
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.draw();
        break;
    case 1: // Static array
        mStaticArray.draw();
        break;
    case 2: // Dynamic array
        mDynamicArray.draw();
        break;
    case 3: // Singly linked list
        mSinglyLinkedList.draw();
        break;
    case 4: // Doubly linked list
        mDoublyLinkedList.draw();
        break;
    case 5: // Circular linked list
        mCircularLinkedList.draw();
        break;
    case 6: // Stack
        mStack.draw();
        break;
    case 7: // Queue
        mQueue.draw();
        break;
    default:
        break;
    }
}

