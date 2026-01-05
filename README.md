# Convertinus v0.2.4

**Auditor:** James Ananenkovic  
**Date:** 2 January 2026  
**License:** MIT  

---

## Overview

Convertinus is a simple console-based software for converting integers between binary and decimal formats.  
v0.2x adds support for **signed 8-bit binary conversions** and **multi-block signed binary → decimal conversions**.

---

## Features

### Unsigned
- **Binary → Decimal**  
  - Arbitrary length, blocks of 8 bits
  - Input example: `00000001-10101010`
- **Decimal → Binary**  
  - Arbitrary length, auto-blocking
  - Output example: `00000001-10101010`

### Signed (two's complement)
- **Binary → Decimal**  
  - Input must be 8-bit blocks (multi-block supported)
  - Negative numbers are displayed correctly, e.g., `( -44 )`
  - Multi-block input example: `11111111-11010100` → `-44`
- **Decimal → Binary**  
  - Input supports full range (previously -128 … 127, now multi-block for larger numbers)
  - Converts negative numbers using two’s complement
  - Output is in 8-bit blocks, separated by `-` if multi-block
  - Example: `-44` → `11111111-11010100`  
