/*
  ==============================================================================

    containers_LinkedListPointer.cpp
    Created: 1 Dec 2017 7:44:16pm
    Author:  kurooka

  ==============================================================================
*/
/*

	単独でリンクされたオブジェクトのリストを操作するのに役立ちます。

	リスト内の後続項目へのポインタを含むように設計されたオブジェクトの場合、
	このクラスにはリストを処理するメソッドが含まれています。
	これを使用するには、指すObjectTypeクラスに、nextListItemというLinkedListPointerが含まれている必要があります。


	---

	LinkedListPointer< ObjectType >::Appender

	リストに効果的に繰り返し挿入できます。

	リスト内の最後の要素を指すAppenderオブジェクトを作成し、Appender::append()を繰り返し呼び出して、
	O（1）時間内にリストの最後に項目を追加することができます。
	(個数によらず一定の時間や手間がかかる操作)

*/


#include "../JuceLibraryCode/JuceHeader.h"


struct MyObject
{
	int id;
	LinkedListPointer<MyObject> nextListItem;
	MyObject(int _id) : id(_id) {}

};


void core_containers_LinkedListPointer_test()
{
	DBG("core_containers_LinkedListPointer_test");


	LinkedListPointer<MyObject> myList;
	myList.append(new MyObject(1));
	myList.append(new MyObject(2));

	int numItems = myList.size(); // returns 2
	DBG(numItems);

	MyObject* lastInList = myList.getLast();
	MyObject* obj0 = myList[0];

	//リストに含まれている？
	if (myList.contains(obj0))
	{
		DBG("true");
	}

	//挿入
	myList.findPointerTo(obj0);
	myList.insertNext(new MyObject(3));

	//挿入２
	myList.insertAtIndex(2, new MyObject(4));

	//効率的な繰り返し挿入
	LinkedListPointer<MyObject>::Appender apender(myList.getLast());

	for (int i = 5; i < 15; i++)
	{
		apender.append(new MyObject(i));
	}

	

	for (int i = 0; i < myList.size(); i++)
	{
		MyObject * e = myList[i];
	}

	myList.deleteAll();



}