# Convertinus v0.2.2

**Author:** James Ananenkovic  
**Date:** 2 January 2026  
**License:** MIT  

---

## Overview

Convertinus is a simple console-based software for converting integers between binary and decimal formats.  
v0.2x adds support for **signed 8-bit binary and decimal to each other conversions**.

---

## Features

### Unsigned
- **Binary → Decimal** (arbitrary length, blocks of 8 bits)
- **Decimal → Binary** (arbitrary length, auto-blocking)

### Signed (8-bit, two's complement)
- **Binary → Decimal**  
  - Input must be 8 bits
  - Negative numbers are displayed in parentheses, e.g., `( -127 )`
  - Uses two’s complement representation
- **Decimal → Binary**
  - Input must be in the range -128 … 127
  - Converts negative numbers to 8-bit two’s complement
  - Output is always 8 bits, MSB = sign bit
