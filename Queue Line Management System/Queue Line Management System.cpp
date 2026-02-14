#include <iostream>
#include <queue>
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillLine("A0", 10);
	clsQueueLine SubscriptionQueue("B0", 5);

	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();
	PayBillLine.IssueTicket();

	PayBillLine.PrintInfo();

	PayBillLine.PrintTicketLineLTR();
	PayBillLine.PrintTicketLineRTL();

	PayBillLine.PrintAllTickets();

	PayBillLine.ServeNextClient();
	cout << "\n\nPay Bills after serving one Client \n\n";
	PayBillLine.PrintInfo();

	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();

	SubscriptionQueue.PrintInfo();
	SubscriptionQueue.PrintTicketLineLTR();
	SubscriptionQueue.PrintTicketLineRTL();

	SubscriptionQueue.PrintAllTickets();

	SubscriptionQueue.ServeNextClient();
	SubscriptionQueue.ServeNextClient();

	cout << "\n\nSubscription Queue after serving two clients:\n\n";

	SubscriptionQueue.PrintInfo();

	system("pause>0");
	return 0;
}
