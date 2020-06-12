//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRobotServer *RobotServer;
//---------------------------------------------------------------------------
__fastcall TRobotServer::TRobotServer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRobotServer::btnStartClick(TObject *Sender)
{
	// ... START SERVER:

    // ... clear the Bindings property ( ... Socket Handles )
	//IdTCPServer1->Bindings->Clear();
    // ... Bindings is a property of class: TIdSocketHandles;

	// ... add listening ports:

	// ... add a port for connections from guest clients.
	//IdTCPServer1->Bindings->Add()->Port = 9200;
    // ... etc..

    // ... ok, Active the Server!
	IdTCPServer1->Active = True;

    // ... disable start button
	btnStart->Enabled = False;

    // ... enable stop button
	btnStop->Enabled  = True;

	// ... message log
	Memo1->Lines->Add("Server Started:");
}
//---------------------------------------------------------------------------
void __fastcall TRobotServer::IdTCPServer1Execute(TIdContext *AContext)
{
	String xxxxx;
	int PeerPort;
	String PeerIP;
	int bs;

	PeerIP = AContext->Binding->PeerIP;
	PeerPort = AContext->Binding->PeerPort;

	Memo1->Lines->Add("    IdTCPServer1Execute "+PeerIP+" : "+IntToStr(PeerPort));
	//AContext->Connection->IOHandler->ReadTimeout=1000;
	//Sleep(500);
	bs = AContext->Connection->IOHandler->RecvBufferSize;
	xxxxx = AContext->Connection->IOHandler->ReadLn();
	Memo1->Lines->Add(xxxxx);
	AContext->Connection->IOHandler->WriteLn(xxxxx);

	// tutaj symulacja przetwarzana obrazu
	Sleep(2000);
	AContext->Connection->IOHandler->WriteLn("ReconError#");
	AContext->Connection->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TRobotServer::btnStopClick(TObject *Sender)
{
    // ... before stopping the server ... send 'good bye' to all clients connected
	//BroadcastMessage('Goodbye Client ');

	//IdTCPServer1->Bindings->Clear();
	IdTCPServer1->StopListening();

    // ... stop server!
	IdTCPServer1->Active = False;

    // ... hide stop button
	btnStop->Enabled   = False;

    // ... show start button
	btnStart->Enabled  = True;

    // ... message log
	Memo1->Lines->Add("Server Stoped!");
}
//---------------------------------------------------------------------------
void __fastcall TRobotServer::FormShow(TObject *Sender)
{
	Memo1->Lines->Clear();
	btnStart->Enabled = true;
	btnStop->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TRobotServer::IdTCPServer1Connect(TIdContext *AContext)
{
	int PeerPort;
	String PeerIP;

	PeerIP = AContext->Binding->PeerIP;
	PeerPort = AContext->Binding->PeerPort;

	Memo1->Lines->Add(" ");
	Memo1->Lines->Add("    connect: "+PeerIP+" : "+IntToStr(PeerPort));
	if (PeerIP.Compare(EditIP->Text)!=0) {
		Memo1->Lines->Add(" ");
		Memo1->Lines->Add("Zle ip, odrzucam polaczenie!");
		Memo1->Lines->Add(" ");
		AContext->Connection->Disconnect();
	}
	//AContext->Connection->IOHandler->ReadTimeout=1000;
}
//---------------------------------------------------------------------------

void __fastcall TRobotServer::IdTCPServer1Disconnect(TIdContext *AContext)
{
	int PeerPort;
	String PeerIP;

	PeerIP = AContext->Binding->PeerIP;
	PeerPort = AContext->Binding->PeerPort;

	Memo1->Lines->Add("    disconnect: "+PeerIP+" : "+IntToStr(PeerPort));
	Memo1->Lines->Add(" ");
}
//---------------------------------------------------------------------------


