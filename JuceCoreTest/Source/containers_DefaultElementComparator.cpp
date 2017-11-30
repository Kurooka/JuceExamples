/*
  ==============================================================================

    containers_DefaultElementComparator.cpp
    Created: 30 Nov 2017 7:47:06pm
    Author:  kurooka

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
/*


	'<'演算子をサポートするオブジェクトの配列をソートするために使用できる単純なElementComparatorクラスです。
	これは、演算子「<」 を実装するプリミティブ型およびオブジェクトに対して機能します。

	こちらも参照のこと
		ElementComparator

	オーバーライド前提というよりは昇順がほしいときに使えということかな？

*/

void DefaultElementComparator_test()
{

	Array<int> myArray;
	DefaultElementComparator<int> sorter;

	juce::Random r;

	for (int i = 0; i < 32; i++)
	{
		myArray.add(r.nextInt());
	}

	myArray.sort(sorter);


	for each (int var in myArray)
	{
		juce::Logger::outputDebugString(juce::String(var));
	}



}
