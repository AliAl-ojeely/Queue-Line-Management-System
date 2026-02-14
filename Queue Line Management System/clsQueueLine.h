// My Code:

//#pragma warning(disable : 4996)
//#pragma once
//#include <iostream>
//#include <string>
//#include <queue>
//#include <stack>
//#include <ctime>
//
//using namespace std;
//
//class clsQueueLine
//{
//public:
//
//	class Ticket
//	{
//	public:
//
//		string PrefixTicket;
//		string Date;
//		int WatingClients;
//		int ServedTime;
//	};
//
//private:
//
//	static string GetSystemDateTimeString()
//	{
//		//system datetime string
//		time_t t = time(0);
//		tm* now = localtime(&t);
//
//		short Day, Month, Year, Hour, Minute, Second;
//
//		Year = now->tm_year + 1900;
//		Month = now->tm_mon + 1;
//		Day = now->tm_mday;
//		Hour = now->tm_hour;
//		Minute = now->tm_min;
//		Second = now->tm_sec;
//
//		return (to_string(Day) + "/" + to_string(Month) + "/"
//			+ to_string(Year) + " - "
//			+ to_string(Hour) + ":" + to_string(Minute)
//			+ ":" + to_string(Second));
//
//	}
//
//	int _Size = 0;
//	string _Prefix;
//	int _Time;
//	int _ServedClients = 0;
//	int _WatingClients;
//	int _TotalTickets = 0;
//
//	queue <Ticket> _MyQueue;
//	queue <Ticket> _TempQueue;
//
//public:
//
//	clsQueueLine(string Prefix, int Time)
//	{
//		_Prefix = Prefix;
//		_Time = Time;
//	}
//
//	void IssueTicket()
//	{
//		Ticket _Ticket;
//
//		_TotalTickets++;
//
//		_Ticket.Date = GetSystemDateTimeString();
//		_Ticket.PrefixTicket = _Prefix + to_string(_TotalTickets);
//		_Ticket.ServedTime = _MyQueue.size() * _Time;
//		_Ticket.WatingClients = _MyQueue.size();
//
//		_MyQueue.push(_Ticket);
//	}
//
//	bool ServeNextClient()
//	{
//		if (_MyQueue.empty())
//			return false;
//
//		_ServedClients++;
//		_MyQueue.pop();
//		return true;
//	}
//
//	void PrintTicketsLineRTL()
//	{
//		if (_MyQueue.empty())
//			cout << "\n\t\tTickets: No Tickets.";
//		else
//			cout << "\n\t\tTickets: ";
//
//		_TempQueue = _MyQueue;
//
//		while (!_TempQueue.empty())
//		{
//			Ticket Ticket = _TempQueue.front();
//			cout << Ticket.PrefixTicket << " <-- ";
//
//			_TempQueue.pop();
//		}
//		cout << "\n";
//	}
//
//	void PrintTicketsLineLTR()
//	{
//		if (_MyQueue.empty())
//			cout << "\n\t\tTickets: No Tickets.";
//		else
//			cout << "\n\t\tTickets: ";
//
//		stack <Ticket> _TempStack;
//		_TempQueue = _MyQueue;
//
//		while (!_TempQueue.empty())
//		{
//			_TempStack.push(_TempQueue.front());
//			_TempQueue.pop();
//		}
//
//		while (!_TempStack.empty())
//		{
//			Ticket Ticket = _TempStack.top();
//			cout << Ticket.PrefixTicket << " --> ";
//
//			_TempStack.pop();
//		}
//		cout << "\n";
//	}
//
//	void PrintInfo()
//	{
//
//		cout << "\n\t\t\t _________________________\n";
//		cout << "\n\t\t\t\tQueue Info";
//		cout << "\n\t\t\t _________________________\n";
//		cout << "\n\t\t\t    Prefix   = " << _Prefix;
//		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
//		cout << "\n\t\t\t    Served Clients  = " << _ServedClients;
//		cout << "\n\t\t\t    Wating Clients  = " << _MyQueue.size();
//		cout << "\n\t\t\t _________________________\n";
//		cout << "\n";
//	}
//
//	void PrintAllTickets()
//	{
//		cout << "\n\n\t\t\t       ---Tickets---";
//
//		if (_MyQueue.empty())
//		{
//			cout << "\n\n\t\t\t     ---No Tickets---\n";
//			return;
//		}
//
//		_TempQueue = _MyQueue;
//
//		while (!_TempQueue.empty())
//		{
//			Ticket Ticket = _TempQueue.front();
//
//			cout << "\n\t\t\t  _______________________\n";
//			cout << "\n\t\t\t\t    " << Ticket.PrefixTicket;
//			cout << "\n\n\t\t\t    " << Ticket.Date;
//			cout << "\n\t\t\t    Wating Clients = " << Ticket.WatingClients;
//			cout << "\n\t\t\t      Serve Time In";
//			cout << "\n\t\t\t       " << Ticket.ServedTime << " Minutes.";
//			cout << "\n\t\t\t  _______________________\n";
//
//			_TempQueue.pop();
//		}
//	}
//
//};


#pragma
#include <iostream>
#include "clsDate.h"
#include <string>
#include <queue>
#include <stack>

using namespace std;

class clsQueueLine
{
private:

	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";

	class clsTicket
	{
		private:
			short _Number = 0;
			string _Prefix;
			string _TicketTime;
			short _WaitingClients = 0;
			short _AverageServeTime = 0;
			short _ExpectedServerTime = 0;

		public:

			clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
			{
				_Number = Number;
				_TicketTime = clsDate::GetSystemDateTimeString();
				_Prefix = Prefix;
				_WaitingClients = WaitingClients;
				_AverageServeTime = AverageServeTime;
			}

			string Prefix()
			{
				return _Prefix;
			}

			short Number()
			{
				return _Number;
			}

			string FullNumber()
			{
				return _Prefix + to_string(_Number);
			}

			string TicketTime()
			{
				return _TicketTime;
			}

			short WaitingClients()
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
				cout << "\n\n\t\t\t    " << _TicketTime;
				cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
				cout << "\n\t\t\t      Serve Time In";
				cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
				cout << "\n\t\t\t  _______________________\n";
			}
	};

public:

	queue<clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.";
		else
			return QueueLine.front().FullNumber();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}

	void PrintTicketsLineRTL()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.FullNumber() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";

	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

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

			cout << " " << Ticket.FullNumber() << " --> ";

			TempStackLine.pop();
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
};