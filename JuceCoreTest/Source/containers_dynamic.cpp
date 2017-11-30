/*
  ==============================================================================

    containers_dynamic.cpp
    Created: 30 Nov 2017 7:02:05pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

/*
	動的に実装されるオブジェクトを表します。
	このクラスは主にスクリプティング言語オブジェクトをラップするためのものですが、他の目的にも使用できます。
	DynamicObjectのインスタンスを使用して名前付きプロパティを格納し、hasMethod()およびinvokeMethod()をサブクラス化することによって、
	オブジェクトメソッドを与えることができます。
*/



void containers_dynamic_test()
{
	juce::DynamicObject* objbase = new juce::DynamicObject();
	juce::DynamicObject& obj = *objbase;

	obj.setProperty("a", 1);
	obj.setProperty("b", 2);
	obj.setProperty("c", 3);
	obj.setProperty("x", 4);
	obj.setProperty("y", 5);

	if (obj.hasProperty("a"))
	{
		juce::Logger::outputDebugString("have a.");
	}
	else {
		juce::Logger::outputDebugString("don't have a.");
	}

	juce::Logger::outputDebugString( obj.getProperty("a").toString() );

	//Json出力
	juce::File f = juce::File::getCurrentWorkingDirectory();
	juce::String filepath = f.getFullPathName() + "\\test.json";
	FileOutputStream file(filepath);

	obj.writeAsJSON(file,true,false,1024);

	/* test.json
		{
		"a": 1,
		"b": 2,
		"c": 3,
		"x": 4,
		"y": 5
		}
	*/

	//クローン　deepコピー
	juce::DynamicObject::Ptr obj2 = obj.clone();
	obj.setProperty("a", 10);

	//deepなので変更されていない
	juce::Logger::outputDebugString(obj2->getProperty("a").toString());

	delete objbase;
}
