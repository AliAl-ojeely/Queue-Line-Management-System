🏦 Queue Line Management System

A robust and efficient C++ implementation of a waiting line management system. This project simulates a real-world ticketing workflow (e.g., bank, customer service) using Object-Oriented Programming (OOP) and standard data structures.

🚀 Overview

The Queue Line Management System provides a complete solution for managing client flow. It handles ticket generation with timestamps, estimates waiting times dynamically, and manages the serving process using the FIFO (First-In-First-Out) principle. It also features a visual representation of the queue in both directions.

✨ Key Features

Smart Ticket Issuance: Generates unique, sequential tickets (e.g., A01, A02) with real-time timestamps.

Dynamic Wait Time: Automatically calculates the expected serving time for new clients based on the current queue size and average service time.

Service Flow Control: Serves clients sequentially and updates queue statistics instantly.

Visual Reporting:

LTR Printing: Visualizes the queue from left to right (entry order).

RTL Printing: Visualizes the queue from right to left using a stack data structure.

Detailed Analytics: Provides a dashboard view of total tickets, served clients, and currently waiting clients.

🛠️ Technical Concepts

This project demonstrates a solid understanding of C++ and data structures:

std::queue: Used as the core container for managing the line (FIFO).

std::stack: Used to reverse the queue order for RTL visualization.

struct & class: Encapsulation of ticket data and queue logic.

ctime: Integration with system time for accurate ticket stamping.

💻 Installation & Usage
1. Integration

Simply include the clsQueueLine header file in your C++ project.

2. Example Code
#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{
    // Initialize Queue: Prefix "A0", Service Time: 10 mins per client
    clsQueueLine PayQueue("A0", 10);

    // 1. Issue Tickets
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();

    // 2. Display Queue Info
    cout << "\n--- Queue Status ---\n";
    PayQueue.PrintInfo();

    // 3. Visualize Queue (Left to Right)
    PayQueue.PrintTicketLineLTR();

    // 4. Visualize Queue (Right to Left)
    PayQueue.PrintTicketLineRTL();

    // 5. Print All Detailed Tickets
    PayQueue.PrintAllTickets();

    // 6. Serve a Client
    cout << "\nServing next client...\n";
    PayQueue.ServeNextClient();

    // 7. Check Info after serving
    cout << "\n--- After Serving ---\n";
    PayQueue.PrintInfo();

    return 0;
}

📊 Sample Output

Below is an example of what the console output looks like:

 _________________________________
             Queue Info
 _________________________________
   Prefix          = A0
   Total Tickets   = 4
   Served Clients  = 0
   Waiting Clients = 4
 _________________________________


Tickets: A01--> A02--> A03--> A04--> 

Serving next client...

 _________________________________
             Queue Info
 _________________________________
   Prefix          = A0
   Total Tickets   = 4
   Served Clients  = 1
   Waiting Clients = 3
 _________________________________

🔧 API Documentation
Method	Description
IssueTicket()	Creates a new ticket, stamps the time, calculates wait time, and pushes it to the queue.
ServeNextClient()	Removes the client at the front of the queue and updates the served counter. Returns false if the queue is empty.
PrintInfo()	Displays a summary dashboard (Total, Served, Waiting).
PrintAllTickets()	Iterates through the queue and prints full details for every ticket in a card format.
PrintTicketLineLTR()	Prints the queue flow from left to right.
PrintTicketLineRTL()	Prints the queue flow from right to left (using a temporary stack).
