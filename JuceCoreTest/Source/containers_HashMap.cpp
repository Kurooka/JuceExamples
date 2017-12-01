/*
  ==============================================================================

    containers_HashMap.cpp
    Created: 1 Dec 2017 7:19:50pm
    Author:  kurooka

  ==============================================================================
*/

/*

	いくつかのキーと値のペアの間のマッピングのセットを保持します。

	keyおよびvalueオブジェクトの型は、テンプレートパラメータとして設定されます。
	クラスを指定して、キー値をハッシュされた整数に変換するハッシュ関数を提供することもできます。
	このクラスの形式は次のとおりです。

	struct MyHashGenerator
	{
		int generateHash (MyKeyType key, int upperLimit) const
		{
			// The function must return a value 0 <= x < upperLimit
			return someFunctionOfMyKeyType (key) % upperLimit;
		}
	};



	Arrayクラスと同様に、キーと値の型はコピー型であると予想されます。
	したがって、ポインタ型として定義すると、このクラスはそれらが指すオブジェクトを削除しません。

	HashFunctionTypeテンプレートパラメータのクラスを指定しない場合、デフォルトのものは文字列とintの単純なマッピングを提供します。


	Iteratorは
	HashMap< KeyType, ValueType, HashFunctionType, TypeOfCriticalSectionToUse >::Iterator


*/


#include "../JuceLibraryCode/JuceHeader.h"


struct MyHashGenerator
{
	int generateHash(int key, int upperLimit) const
	{
		// The function must return a value 0 <= x < upperLimit
		return DefaultHashFunctions::generateHash(key, 567890);
	}
};

void	core_containers_HashMap_test()
{

	HashMap<int, String> hash;
	hash.set(1,"test1");
	hash.set(2, "test2");

	//イテレーター
	HashMap<int, String>::Iterator itr(hash);
	while (itr.next())
	{
		DBG(itr.getKey() << " -> " << itr.getValue());
	}


	juce::Logger::outputDebugString(hash[1]);
	juce::Logger::outputDebugString(hash[2]);

	hash[1] = "test3";
	juce::Logger::outputDebugString(hash[1]);
	hash.set(1, "test3");
	juce::Logger::outputDebugString(hash[1]);

	//独自ハッシュ生成＋クリティカルセクション
	HashMap<int, String, MyHashGenerator,CriticalSection> hash2;
	hash2.set(1, "aaaaa");
	hash2.set(2, "abaaa");

	//クリティカルセクションのみ
	HashMap<int, String, DefaultHashFunctions, CriticalSection> hash3;


}


