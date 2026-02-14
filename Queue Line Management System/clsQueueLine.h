#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

class clsQueueLine
{
public:

	class Ticket
	{
	public:

		string PrefixTicket;
		string Date;
		int WatingClients;
		int ServedTime;
	};

private:

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

	int _Size = 0;
	string _Prefix;
	int _Time;
	int _ServedClients = 0;
	int _WatingClients;
	int _TotalTickets = 0;

	queue <Ticket> _MyQueue;
	queue <Ticket> _TempQueue;

public:

	clsQueueLine(string Prefix, int Time)
	{
		_Prefix = Prefix;
		_Time = Time;
	}

	void IssueTicket()
	{
		Ticket _Ticket;

		_TotalTickets++;

		_Ticket.Date = GetSystemDateTimeString();
		_Ticket.PrefixTicket = _Prefix + to_string(_TotalTickets);
		_Ticket.ServedTime = _MyQueue.size() * _Time;
		_Ticket.WatingClients = _MyQueue.size();

		_MyQueue.push(_Ticket);
	}

	bool ServeNextClient()
	{
		if (_MyQueue.empty())
			return false;

		_ServedClients++;
		_MyQueue.pop();
		return true;
	}

	void PrintTicketLineLTR()
	{
		if (_MyQueue.empty()) return;

		_TempQueue = _MyQueue;

		cout << "\n\t\tTickets: ";

		while (!_TempQueue.empty())
		{
			Ticket Ticket = _TempQueue.front();
			cout << Ticket.PrefixTicket << "--> ";

			_TempQueue.pop();

			//if (!_TempQueue.empty())
			//{
			//	cout << " <-- ";
			//}
		}
		cout << "\n";
	}

	void PrintTicketLineRTL()
	{
		if (_MyQueue.empty()) return;

		stack <Ticket> _TempStack;
		_TempQueue = _MyQueue;

		while (!_TempQueue.empty())
		{
			_TempStack.push(_TempQueue.front());
			_TempQueue.pop();
		}

		cout << "\n\t\tTickets: ";

		while (!_TempStack.empty())
		{
			Ticket Ticket = _TempStack.top();
			cout << Ticket.PrefixTicket << " <--";

			_TempStack.pop();

			//if (!_TempStack.empty())
			//{
			//	cout << " --> ";
			//}
		}
		cout << "\n";
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________________\n";
		cout << "\t\t\t\t     Queue Info\n";
		cout << "\t\t\t _________________________________\n";

		cout << "\t\t\t  Prefix          = " << _Prefix << "\n";
		cout << "\t\t\t  Total Tickets   = " << _TotalTickets << "\n";
		cout << "\t\t\t  Served Clients  = " << _ServedClients << "\n";
		cout << "\t\t\t  Waiting Clients = " << _MyQueue.size() << "\n";

		cout << "\t\t\t _________________________________\n";
		cout << "\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       --- Tickets Gallery --- \n\n";

		if (_MyQueue.empty())
		{
			cout << "\t\t\t       No Tickets in the Queue.\n";
			return;
		}

		_TempQueue = _MyQueue;

		while (!_TempQueue.empty())
		{
			Ticket Ticket = _TempQueue.front();

			cout << "\t\t\t _________________________________\n";
			cout << "\t\t\t  " << Ticket.PrefixTicket << "                            \n"; 
			cout << "\t\t\t " << Ticket.Date << "       \n";
			cout << "\t\t\t Waiting Clients : " << Ticket.WatingClients << "           \n";
			cout << "\t\t\t Serve Time In   : " << Ticket.ServedTime << " Minutes  \n";
			cout << "\t\t\t_______________________________\n\n";

			_TempQueue.pop();
		}
	}

};

