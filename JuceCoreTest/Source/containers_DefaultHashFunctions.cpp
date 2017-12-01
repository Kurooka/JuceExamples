/*
  ==============================================================================

    containers_DefaultHashFunctions.cpp
    Created: 1 Dec 2017 7:03:15pm
    Author:  kurooka

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


/*

	HashMapクラスで使用するための、いくつかのプリミティブ型のハッシュ関数を生成する単純なクラスです。

	juce_core » containers HashMapクラスも参照のこと https://juce.com/doc/classHashMap

	out 
	12
	8
	0
	96
	93029210
	1444370555

*/

void	core_containers_DefaultHashFunctions_test()
{
	juce::Logger::outputDebugString("--------------------");
	juce::Logger::outputDebugString("core_containers_DefaultHashFunctions_test");


	//uint32
	uint32 a = 12;	
	juce::Logger::outputDebugString( juce::String(
		DefaultHashFunctions::generateHash(a ,16)
	));

	//int32 
	int32 b = 24;
	juce::Logger::outputDebugString(juce::String(
		DefaultHashFunctions::generateHash(b, 16)
	));

	//uint64
	uint64 c = 48;
	juce::Logger::outputDebugString(juce::String(
		DefaultHashFunctions::generateHash(c, 16)
	));

	//int64
	int64 d = 96;
	juce::Logger::outputDebugString(juce::String(
		DefaultHashFunctions::generateHash(d, INT_MAX)
	));

	//String
	juce::String e = "apple";
	juce::Logger::outputDebugString(juce::String(
		DefaultHashFunctions::generateHash(e, INT_MAX)
	));

	//variant
	juce::var f = 123.56;
	juce::Logger::outputDebugString(juce::String(
		DefaultHashFunctions::generateHash(f, INT_MAX)
	));


}

