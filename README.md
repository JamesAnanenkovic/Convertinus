# Convertinus v0.2.3

**Author & Auditor:** James Ananenkovic  
**Date:** 5 January 2026  
**License:** MIT  

---

## Overview

Convertinus is a simple console-based software for converting integers between binary and decimal formats.  
v0.2x adds support for **signed 8-bit binary and decimal conversions**.  
v0.2.3 expands **signed decimal → binary** to support **arbitrarily large signed numbers** with 8-bit block formatting.

---

## Features

### Unsigned
- **Binary → Decimal** (arbitrary length, blocks of 8 bits)
- **Decimal → Binary** (arbitrary length, auto-blocking)

### Signed
- **Binary → Decimal (8-bit)**  
  - Input must be 8 bits  
  - Negative numbers are displayed in parentheses, e.g., `( -127 )`  
  - Uses two’s complement representation
- **Decimal → Binary (expanded)**  
  - Supports signed numbers beyond -128 … 127  
  - Outputs in **8-bit blocks**, e.g., `00000001-10101100`  
  - Negative numbers are displayed in parentheses, e.g., `(- 00101100)`  
