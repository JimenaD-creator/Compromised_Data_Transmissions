# 🔎 Transmission Analysis Tool  

This project analyzes transmission files to detect malicious code patterns, identify palindromes, and find common substrings between transmissions. It implements **string matching algorithms** such as **KMP**, **Manacher’s Algorithm**, and **Dynamic Programming** for longest common substrings.  

---

## 📌 Features  

### 1. Search for malicious code in transmissions (KMP Algorithm)  
- Detects if malicious code snippets (`mcode1`, `mcode2`, `mcode3`) appear in transmission files.  
- Uses **Knuth–Morris–Pratt (KMP)** for efficient pattern searching.  
- Supports **overlapping matches**.  

### 2. Find the longest palindrome in transmissions  
- Identifies the **longest palindromic substring** inside each transmission.  
- Two approaches implemented:  
  - **Brute Force** (checks all substrings, slower).  
  - **Manacher’s Algorithm** (optimized linear-time solution).  

### 3. Longest common substring between transmissions  
- Finds the **longest exact matching substring** shared by two transmissions.  
- Implemented with **dynamic programming** using a 2D DP table.  

---

## 📂 Project Structure  
```bash
├── transmission1.txt   # First transmission file
├── transmission2.txt   # Second transmission file
├── mcode1.txt          # Malicious code pattern 1
├── mcode2.txt          # Malicious code pattern 2
├── mcode3.txt          # Malicious code pattern 3
├── main.cpp            # Main source code with all algorithms
```

## ⚡ Algorithms Used  

- **KMP (Knuth–Morris–Pratt)** → efficient pattern searching in O(n + m).  
- **Manacher’s Algorithm** → finds the longest palindromic substring in O(n).  
- **Dynamic Programming (LCS)** → finds the longest common substring in O(m × n).  

---

## 🛠️ Installation & Compilation  

1. Clone this repository:  
   ```bash
   git clone https://github.com/your-username/your-repo.git
   cd your-repo
   g++ main.cpp -o transmission_too
   ./transmission_tool
