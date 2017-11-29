/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#include <cstdio>


class ActionObject : public UndoableAction
{
public:
	ActionObject() {}
	virtual ~ActionObject() {}

	/*
	このメソッドは、UndoManagerによって呼び出されます。
	@returnsアクションがエラーなしで実行できる場合はtrue。
	*/
	virtual bool perform()
	{
		return true;
	}

	/*
	このメソッドは、UndoManagerによって呼び出されます。
	呼び出し可能な undo（）メソッドで呼び出しを行わないように注意してください
	再帰的にUndoManager :: perform（）メソッドに戻す

	@returnsアクションがエラーなしで元に戻すことができる場合はtrue。
	*/

	virtual bool undo()
	{
		return true;
	}

};


void undoTest()
{

	juce::UndoManager undomanager(200,30); //Undoリストの最大数を指定

	//undoのヒストリーをクリア
	undomanager.clearUndoHistory();

	//UndoableActionオブジェクトを格納するために使用するスペースの現在の量を返します。
	int size = undomanager.getNumberOfUnitsTakenUpByStoredCommands();
	Logger::outputDebugString( juce::String(size) );

	//UndoableActionオブジェクトを格納するために使用できる領域の量を設定します。
	undomanager.setMaxNumberOfStoredUnits(200,30);

	//Undo可能なアクションの実行
	undomanager.beginNewTransaction();			//次のbeginNewTransactionまでグループ化（トランザクション）される
	undomanager.perform(new ActionObject());

	//Undo可能なアクションの実行2
	undomanager.beginNewTransaction("named transaction"); //トランザクションに名前を付ける
	undomanager.perform(new ActionObject(),"named action");

	//グループ化
	undomanager.beginNewTransaction("group transaction");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());

	undomanager.setCurrentTransactionName("in 3 action"); //現在のトランザクションの名前の変更

	//現在のトランザクションの名前を返す
	Logger::outputDebugString( undomanager.getCurrentTransactionName() );

	//UndoリストにUndo可能なアクションがあるか?
	if (undomanager.canUndo())
	{
		Logger::outputDebugString("Undo is OK");
	}
	else {
		Logger::outputDebugString("Undo is NG");
	}

	//Undoが呼び出されたときのトランザクション名を返す
	Logger::outputDebugString(undomanager.getUndoDescription());


	//Undo 最後のトランザクションをロールバックします。
	//トランザクションを取り消すことができる場合はtrue、失敗した場合、取り消すトランザクションがない場合はfalse
	if (undomanager.undo())
	{
		Logger::outputDebugString("Undo = true ");
	}
	else {
		Logger::outputDebugString("Undo = false ");
	}

	//canRedo Redo可能か？
	if (undomanager.canRedo())
	{
		Logger::outputDebugString("Redo is OK");
	}
	else {
		Logger::outputDebugString("Redo is NG");
	}


	//redo（）が呼び出されたときにやり直すトランザクションの名前を返します。
	Logger::outputDebugString(undomanager.getRedoDescription());
	
	//redoの実行
	if (undomanager.redo())
	{
		Logger::outputDebugString("redo = true ");
	}
	else {
		Logger::outputDebugString("redo = false ");
	}


	//現在のトランザクションに追加されたアクションをロールバックしようとします。
	//
	//Undoの最後の呼び出し後に追加されたUndoリストでいくつかのアクションが追加されている場合のみ実行ができます。
	//具体的な用法としては実際にbeginNewTransaction時にアクションをいくつか呼び出したのちにアクションを実際に実行するかを判断しこのトランザクション呼び出し無かったことにできます。
	Logger::outputDebugString(undomanager.getUndoDescription());
	undomanager.beginNewTransaction("fail action");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	Logger::outputDebugString(undomanager.getUndoDescription());

	if (undomanager.undoCurrentTransactionOnly())
	{
		Logger::outputDebugString("undoCurrentTransactionOnly = true ");
	}

	Logger::outputDebugString(undomanager.getUndoDescription());


	// getActionsInCurrentTransaction
	//現在開いているトランザクション中に実行されたUndoableActionオブジェクトのリストを返します。
	//	効果的に、これはundoCurrentTransactionOnly（）が今呼び出されたときに元に戻されるアクションのリストです。
	//	リスト内の最初の項目は、実行された最も初期のアクションです。
	undomanager.beginNewTransaction("getActionsInCurrentTransaction test");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());

	juce::Array<const UndoableAction*> actionlist;
	undomanager.getActionsInCurrentTransaction(actionlist);
	Logger::outputDebugString(juce::String( actionlist.size() ));

	for each (const UndoableAction* var in actionlist){
		//要素の検査等
	}
	
	//undo（）が呼び出されたときに状態が復元される時刻を返します。
	//元に戻すことができない場合、Time（）を返します。
	juce::Time _time = undomanager.getTimeOfUndoTransaction();
	Logger::outputDebugString( _time.toString(false, true) );

	//redo（）が呼び出されたときに状態が復元される時刻を返します。
	//やり直しが現在可能でない場合、Time::getCurrentTime（）を返します。
	_time = undomanager.getTimeOfRedoTransaction();
	Logger::outputDebugString(_time.toString(false, true));



}

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
	undoTest();

    return 0;
}
