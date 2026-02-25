#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include "clsDate.h"

using namespace std;
class clsQueueLine
{
private:

	string _Prefix = "";
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	
	class clsTicket {
	private:
		short _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectedServeTime = 0;
	public:
		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Prefix = Prefix;
			_Number = Number;
			_TicketTime = clsDate::get_system_date_time_string();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		}

		string GetPrefix()
		{
			return _Prefix;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string GetTicketTime()
		{
			return _TicketTime;
		}
		
		short GetWaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << GetTicketTime();
			cout << "\n\t\t\t    Wating Clients = " << GetWaitingClients();
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}

	};


public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0;
	}

	
	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClient(), _AverageServeTime);
		QueueLine.push(Ticket);
	}

	short WaitingClient()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClient();
	}



	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClient();
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "Teckets:   ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();
			cout << Ticket.FullNumber() << "<--";
			TempQueueLine.pop();
		}
		cout << "\n";
	}
	
	void PrintTicketsLineLTR()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "Teckets:   ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top();
			TempStackLine.pop();
			cout << Ticket.FullNumber() << "-->";
		}
		cout << "\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;


		QueueLine.pop();
		
		return true;
	}
};



