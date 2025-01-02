### 🚀 **42-ft_printf**  
🔗 **ft_printf**: A Recreation of `printf` in C  
*"Mastering formatted output with a custom implementation."*  

---

### 🌟 **What is ft_printf?**  
**ft_printf** is a project from 42 Campus that involves creating a custom version of the standard C library function `printf`. It provides formatted output functionality, handling a variety of placeholders for strings, integers, pointers, and more.  

With **ft_printf**, you can:
- Print various data types using custom formatting.
- Extend its functionality to meet specific requirements.
- Enhance your understanding of variadic functions and low-level I/O operations in C.

---

### 🛠️ **How it Works**  

#### **Core Concepts**  
- **Format Specifiers**: Handles placeholders like `%c`, `%s`, `%d`, `%p`, etc., to output different data types.  
- **Variadic Arguments (`<stdarg.h>`)**: Allows functions to accept a variable number of arguments using `va_list`, `va_start`, `va_arg`, and `va_end`.  
- **Custom I/O Functions**: Utilizes low-level I/O like `write()` for efficient output.  

---

### 🧩 **ft_printf Step-by-Step**  

#### 1️⃣ **Parsing and Processing**  
The main function, `ft_printf`, iterates through the format string:  
```c
int	ft_printf(char const *str, ...)
{
	va_list va;
	size_t counter = 0;
	va_start(va, str);
	while (*str) {
		if (*str == '%') {
			str++;
			ft_format(va, (char *)str, &counter);
		} else {
			ft_putchar_pf(*str, &counter);
		}
		str++;
	}
	va_end(va);
	return (counter);
}
```
If % is found, it processes the specifier (ft_format).
Otherwise, it prints the character directly.
2️⃣ Handling Specifiers
The helper function ft_format matches the format specifier and calls the appropriate function:

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c') ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's') ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p') ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd') ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u') ft_putuint_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X') {
		char *base = (*str == 'x') ? HEX_LOW_BASE : HEX_UPP_BASE;
		ft_puthex_pf(va_arg(va, unsigned int), counter, base);
	} else if (*str == '%') ft_putchar_pf('%', counter);
}
Supports %c, %s, %p, %d, %u, %x, %X, and literal %.
Utilizes custom functions (ft_put...) to handle each type.
3️⃣ Custom Output Functions
Examples of helper functions in ft_printf.h:

ft_putchar_pf: Writes a single character.
ft_putstr_pf: Outputs a string.
ft_putnbr_pf: Prints integers.
ft_puthex_pf: Converts numbers to hexadecimal.
🌈 Visualizing the Workflow
plaintext

Input: ft_printf("Hello %s, your score is %d!", "Alice", 42);

Parsing: 
1. "Hello " -> Print directly.
2. %s -> Call ft_putstr_pf("Alice").
3. ", your score is " -> Print directly.
4. %d -> Call ft_putnbr_pf(42).

Output: "Hello Alice, your score is 42!"
🔑 Key Functions
va_list: Manages variadic arguments.
write(): Outputs characters efficiently.
ft_format: Processes and dispatches specifiers.
Custom Helpers: Handles specifics like pointer formatting (%p) or unsigned integers (%u).
🚨 Error Handling
Null Strings: Handles NULL for %s gracefully by printing (null).
Edge Cases: Ensures correct behavior for large numbers, negative values, etc.
Robustness: Avoids memory leaks and improper pointer usage.
🛠️ How to Compile and Run
Clone the Repository
bash

git clone https://github.com/your-repo/42-ft_printf.git
cd 42-ft_printf
Compile

gcc -Wall -Wextra -Werror ft_printf.c -o ft_printf
Run

./ft_printf
📚 Resources
Variadic Functions in C
Understanding printf Format Specifiers
File Descriptors Explained
🎉 ft_printf gives you the power to build and control formatted output in C, enhancing your understanding of core programming concepts!
