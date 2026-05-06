# 💥 Project 4 — Bank System & Currency Exchange (OOP)

## 📖 Overview

This project — **Bank System & Currency Exchange (OOP)** — is a **continuation** and **expansion** of the previous project:  
🧩 *Project 12 – Bank System (OOP)*  

It integrates a **mini Currency Exchange System** within the main **Bank System**, proving that even **large-scale software** is just a combination of **small, well-structured subsystems**.  

Instead of building it as a standalone app, we decided to **embed** it inside the Bank System to learn how **real-world enterprise applications** grow, connect, and evolve over time.  

---

## 🎯 Learning Purpose

This project is part of our continuous OOP journey with **Dr. Abu Hadhoud** at [ProgrammingAdvices.com](https://www.programmingadvices.com).  

Through this module, we’re learning step by step how to:  
- Analyze system requirements for a new feature or subsystem.  
- Integrate it smoothly with existing architecture.  
- Apply **Encapsulation**, **Abstraction**, and **Inheritance** effectively.  
- Design modular, scalable, and maintainable OOP systems.  

We start by analyzing the task, implementing our own version, and then comparing it with the instructor’s solution — reinforcing both **logic and architecture** understanding 🔁  

---

## 🏦 Main System Integration

The **Bank System** continues to operate as before, but now includes **two new main menu options**:

```
9 - Currency Exchange
10 - Logout
```

When selecting option **9**, the user is redirected to the new **Currency Exchange Main Screen**, which displays:

```
Currency Exchange Menu
1 - List Currencies
2 - Find Currency
3 - Update Rate
4 - Currency Calculator
5 - Main Menu
```


---

## 💱 Currency Exchange Features

### 1️⃣ List Currencies  
Displays a list of all currencies with details such as:  
- Country Name  
- Currency Code  
- Currency Name  
- Exchange Rate (relative to USD)  

🗂️ Currency data is provided in a ready-to-use file by the instructor for simplicity.

---

### 2️⃣ Find Currency  
Allows searching by **Country Name** or **Currency Code**.  
- ✅ If found → displays the currency card with full details.  
- ❌ If not found → shows an error message.

---

### 3️⃣ Update Rate  
Lets the user **update the exchange rate** of a specific currency.  
Other details (like name, country, and code) remain unchanged.  
The system asks for confirmation before applying the new rate.

---

### 4️⃣ Currency Calculator  
A built-in **currency converter** that calculates value conversion between any two currencies.  

Conversion logic:  
- If one of the currencies is USD → direct conversion.  
- Otherwise → convert from currency A → USD → currency B.  

After conversion, the program asks if the user wants to perform another calculation or return to the menu.

---

### 5️⃣ Main Menu  
Returns to the **Bank System Main Screen**.

---

## 🧠 Educational Insight

This project teaches an important software engineering principle:  
> “Every big system is just a collection of small, connected systems.”  

By embedding the **Currency Exchange project** inside the **Bank System**, we’re practicing how to integrate subsystems that share logic, data, and structure — just like real-world enterprise software.  

We’re not simply coding functions;  
we’re **engineering systems** that can evolve, expand, and scale gracefully 🚀  

---

## 🧩 Project Philosophy

At this stage, we fully understand that:  
- **Encapsulation** hides unnecessary internal details.  
- **Abstraction** keeps the system simple and focused.  
- **Inheritance** enables reuse and consistency.  
- **Polymorphism** allows flexibility and adaptability.  

These OOP concepts combined make the system **organized, readable, and easy to extend** — which is exactly what we’re achieving here.  

---

## 🔧 Technologies

- 💻 **C++ (Object-Oriented Programming)**
- 🧱 File Handling for Data Storage
- 🧩 Modular Class Design
- 🧮 CLI (Console-Based Interface)

---

## 🏗️ Suggested Folder Structure

```text

📂 Bank-System-and-CurrencyExchange
┣ 📁 Core
┃ ┣ clsPerson.h / clsUser.h / clsBankClient.h
┃ ┗ clsScreen.h / clsMainScreen.h
┣ 📁 BusinessLogic
┃ ┣ clsCurrency.h / clsCurrencyExchange.h
┃ ┗ Transaction & Access Control Classes
┣ 📁 Data
┃ ┗ Files for Clients & Currencies
┣ 📁 UI
┃ ┣ Bank Screens / Currency Exchange Screens
┃ ┗ Menus & UI Components
┗ main.cpp

```


---

## 🧩 Comparison: Project 12 vs Project 13

| Aspect | Project 12 – Bank System | Project 13 – Bank System & Currency Exchange |
|--------|--------------------------|----------------------------------------------|
| **Scope** | Core Banking Operations | Banking + Currency Exchange Module |
| **Goal** | Apply OOP Concepts | Practice System Integration & Scalability |
| **Design** | Modular Classes & Screens | Interconnected Subsystems |
| **Complexity** | Single System | Multi-System Integration |
| **Learning Outcome** | Foundation of OOP | Real-world Application Architecture |

---

## 💬 Final Thought

This project marks a major milestone —  
we’ve gone from building isolated systems to **designing interconnected ones**.  

The **Currency Exchange module** proves that we can keep expanding our Bank System indefinitely — one feature at a time —  
and that’s the **true power of OOP** 💪  

> “Mastering OOP isn’t about syntax — it’s about building systems that grow and evolve just like real software.”

---

## 💻 GitHub Repository  
🔗 [github.com/github.com/Aymane-Lazaar/Project-4-Currency-Exchange-oop_](https://github.com/Aymane-Lazaar/Project-4-Currency-Exchange-oop_)

