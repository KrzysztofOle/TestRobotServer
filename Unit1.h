//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
//---------------------------------------------------------------------------
class TRobotServer : public TForm
{
__published:	// IDE-managed Components
	TButton *btnStart;
	TButton *btnStop;
	TButton *btnClear;
	TIdTCPServer *IdTCPServer1;
	TMemo *Memo1;
	TEdit *EditIP;
	TLabel *Label1;
	void __fastcall btnStartClick(TObject *Sender);
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
	void __fastcall btnStopClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall IdTCPServer1Connect(TIdContext *AContext);
	void __fastcall IdTCPServer1Disconnect(TIdContext *AContext);

private:	// User declarations
public:		// User declarations
	__fastcall TRobotServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRobotServer *RobotServer;
//---------------------------------------------------------------------------
#endif
