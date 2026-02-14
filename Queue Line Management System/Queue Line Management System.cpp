#include <iostream>
#include <queue>
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillLine("A0", 10);

	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();

	PayBillLine.PrintInfo();

	PayBillLine.PrintTicketLineLTR();
	PayBillLine.PrintTicketLineRTL();

	PayBillLine.PrintAllTickets();

	PayBillLine.ServeNextClient();
	cout << "\n\nPay Bills after serving ond Client \n\n";

	PayBillLine.PrintInfo();
}
