/*
  ==============================================================================

    containers_array.cpp
    Created: 30 Nov 2017 6:48:11pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

/*
	Array< ElementType, TypeOfCriticalSectionToUse, minimumAllocatedSize >

	プリミティブオブジェクトまたはcopy-by-valueオブジェクトのサイズ変更可能な配列を保持します。

	配列の例は次のとおりです。
	
	Array<int>
	Array<Rectangle>
	またはArray<MyClass *>

	Arrayクラスを使用すると、単純な非ポリモフィックオブジェクトやプリミティブ型を保持できます。
	そのためには、クラスが次の要件を満たしている必要があります。

	コピーコンストラクタと代入演算子が必要です
	これはmemcpyによってメモリに再配置できなければなりません。
	そのため、外部ポインタや自身への参照に依存する機能を持つオブジェクトは使用できません。
	もちろん、オブジェクトの任意の種類へのポインタの配列を持つことができます。 
	Array <MyClass *>ですが、これを行うと配列はオブジェクトの所有権を持ちません。
	オブジェクトのリストを保持するためのより強力な方法については、OwnedArrayクラスまたはReferenceCountedArrayクラスを参照してください。

	文字列のリストを保持するには、Array <String>を使用することができますが、通常、特殊なクラスStringArrayを使用する方が便利です。

	すべての配列のメソッドをスレッドセーフにするには、デフォルトのDummyCriticalSectionではなく、テンプレートのTypeOfCriticalSectionToUseパラメータとして "CriticalSection"を渡します。
*/

CriticalSection objectLock;

void	ArrayTemplateTest()
{
	//DummyCriticalSectionで作成される = スレッドセーフではない
	juce::Array<int> int_array; 

	for (int i = 0 ; i < 32 ; i++ )
		int_array.add(i);

	//スレッドセーフな配列操作
	juce::Array<int, CriticalSection, 64> int_array2;
	{
		//スコープロック
		const ScopedLock myScopedLock(objectLock);

		for (int i = 0; i < 32; i++)
			int_array2.add(i);
	}
}
