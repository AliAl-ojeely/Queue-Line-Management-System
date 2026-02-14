# 🏦 Queue Line Management System

A robust and efficient **C++** implementation of a waiting line management system.  
This project simulates a real-world ticketing workflow (e.g., bank, customer service) using **Object-Oriented Programming (OOP)** and standard data structures.

---

# 🚀 Overview

The **Queue Line Management System** provides a complete solution for managing client flow.

It:

- Generates tickets with real-time timestamps  
- Dynamically estimates waiting time  
- Manages the serving process using the **FIFO (First-In-First-Out)** principle  
- Provides visual representations of the queue in both directions  

---

# ✨ Key Features

## 🎟 Smart Ticket Issuance
Generates unique, sequential tickets (e.g., `A01`, `A02`) with real-time timestamps.

## ⏱ Dynamic Wait Time
Automatically calculates the expected serving time for new clients based on:
- Current queue size  
- Average service time  

## 🔄 Service Flow Control
- Serves clients sequentially  
- Instantly updates queue statistics  

## 📊 Visual Reporting
- **LTR Printing:** Displays queue from left to right (entry order)  
- **RTL Printing:** Displays queue from right to left using a `std::stack`  

## 📈 Detailed Analytics
Provides a dashboard showing:
- Total tickets  
- Served clients  
- Waiting clients  

---

# 🛠 Technical Concepts

This project demonstrates strong understanding of:

- `std::queue` → Core FIFO container  
- `std::stack` → Reverse visualization  
- `struct` & `class` → Data encapsulation  
- `<ctime>` → System time integration  

---

# 💻 Installation & Usage

## 1️⃣ Integration

Include the header file in your C++ project:

```cpp
#include "clsQueueLine.h"
2️⃣ Example Usage
#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{
    // Initialize Queue: Prefix "A0", Service Time: 10 mins per client
    clsQueueLine PayQueue("A0", 10);

    // Issue Tickets
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();
    PayQueue.IssueTicket();

    // Display Queue Info
    cout << "\n--- Queue Status ---\n";
    PayQueue.PrintInfo();

    // Visualizations
    PayQueue.PrintTicketLineLTR();
    PayQueue.PrintTicketLineRTL();

    // Detailed Tickets
    PayQueue.PrintAllTickets();

    // Serve Client
    cout << "\nServing next client...\n";
    PayQueue.ServeNextClient();

    cout << "\n--- After Serving ---\n";
    PayQueue.PrintInfo();

    return 0;
}
📊 Sample Output
_________________________________
            Queue Info
_________________________________
Prefix          = A0
Total Tickets   = 4
Served Clients  = 0
Waiting Clients = 4
_________________________________

Tickets:
A01 --> A02 --> A03 --> A04 -->

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
IssueTicket()	Creates a new ticket, stamps time, calculates wait time, and pushes it to the queue.
ServeNextClient()	Removes the front client and updates counters. Returns false if empty.
PrintInfo()	Displays summary statistics.
PrintAllTickets()	Prints full details for every ticket.
PrintTicketLineLTR()	Displays queue left → right.
PrintTicketLineRTL()	Displays queue right → left using a temporary stack.
🧠 Design Pattern
This system follows a clear FIFO queue model, simulating real-world service counters such as:

Banks

Customer support centers

Government offices

Ticketing systems
